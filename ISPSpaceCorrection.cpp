#include "Camera.h"
#include "qtest.h"
#include "ISPSpaceCorrection.h"
#include "iport.h"
#include "ISPDockWidget.h"
ISPSpaceCorrection::ISPSpaceCorrection(QWidget *parent, Qt::WindowFlags f ) :
m_SCEnableCheckBox(new QCheckBox(this)),
m_SCCoefficientLabel(new QLabel(this)),
m_SCCoefficientEdit(new QLineEdit(this)),
m_CorrectionDirectGroupBox(new QGroupBox(this)),
m_RGBDirect(new QRadioButton(m_CorrectionDirectGroupBox)),
m_BGRDirect(new QRadioButton(m_CorrectionDirectGroupBox)),
m_verticalSpacer(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding)),
m_SCCoefficientLayOut(new QHBoxLayout()),
m_GroupBoxLayOut(new QHBoxLayout(m_CorrectionDirectGroupBox)),
m_VerticalLayOut(new QVBoxLayout(this)),
m_pCamera(nullptr)

{
	m_SCEnableCheckBox->setText(QApplication::translate("MainWindow", "\347\251\272\351\227\264\346\240\241\346\255\243 (i_en)", Q_NULLPTR));//

	m_SCCoefficientLabel->setText(QApplication::translate("MainWindow", "\346\240\241\346\255\243\347\263\273\346\225\260\357\274\232(iv_SC)", Q_NULLPTR));
	m_SCCoefficientLayOut->addWidget(m_SCCoefficientLabel);
	m_SCCoefficientLayOut->addWidget(m_SCCoefficientEdit);

	m_CorrectionDirectGroupBox->setTitle(QApplication::translate("MainWindow", "\346\240\241\346\255\243\346\226\271\345\220\221\357\274\232", Q_NULLPTR));
	m_RGBDirect->setText(QApplication::translate("MainWindow", "RGB\346\226\271\345\220\221", Q_NULLPTR));
	m_BGRDirect->setText(QApplication::translate("MainWindow", "BGR\346\226\271\345\220\221", Q_NULLPTR));
	m_GroupBoxLayOut->addWidget(m_RGBDirect);
	m_GroupBoxLayOut->addWidget(m_BGRDirect);

	m_VerticalLayOut->addWidget(m_SCEnableCheckBox);
	m_VerticalLayOut->addLayout(m_SCCoefficientLayOut);
	m_VerticalLayOut->addWidget(m_CorrectionDirectGroupBox);

	m_VerticalLayOut->addItem(m_verticalSpacer);

	connect(m_SCEnableCheckBox, SIGNAL(clicked(bool)), this, SLOT(on_SCEnableCheckBox_clicked(bool)));
	connect(m_SCCoefficientEdit, SIGNAL(returnPressed()), this, SLOT(on_SCValueLineEdit_returnPressed()));
	connect(m_RGBDirect, SIGNAL(clicked(bool)), this, SLOT(on_RGBDirectRadioButton_clicked(bool)));
	connect(m_BGRDirect, SIGNAL(clicked(bool)), this, SLOT(on_BGRDirectRadioButton_clicked(bool)));

}

ISPSpaceCorrection::~ISPSpaceCorrection()
{
}
//¿Õ¼äÐ£Õý
void ISPSpaceCorrection::on_SCEnableCheckBox_clicked(bool isClicked)
{
	quint32 enable = 1;
	quint32 disable = 0;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&enable, SC_EN_REG, sizeof(quint32));
	else
		m_pCamera->GetCameraIPort()->write((quint8*)&disable, SC_EN_REG, sizeof(quint32));
}
void ISPSpaceCorrection::on_SCValueLineEdit_returnPressed()
{
	float srtFloat = m_SCCoefficientEdit->text().toFloat();
	quint32 srcInt16 = srtFloat * 4096;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8*)&srcInt16, SC_VALUE, sizeof(quint32));
}
void ISPSpaceCorrection::on_RGBDirectRadioButton_clicked(bool isClicked)
{
	quint32 RGB_Direction = 1;
	quint32 BGR_Direction = 0;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&RGB_Direction, SC_DIRECTION_REG, sizeof(quint32));
	else
		m_pCamera->GetCameraIPort()->write((quint8*)&BGR_Direction, SC_DIRECTION_REG, sizeof(quint32));
}
void ISPSpaceCorrection::on_BGRDirectRadioButton_clicked(bool isClicked)
{
	quint32 RGB_Direction = 1;
	quint32 BGR_Direction = 0;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&BGR_Direction, SC_DIRECTION_REG, sizeof(quint32));
	else
		m_pCamera->GetCameraIPort()->write((quint8*)&RGB_Direction, SC_DIRECTION_REG, sizeof(quint32));
}