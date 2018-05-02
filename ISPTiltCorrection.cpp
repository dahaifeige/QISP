#include "Camera.h"
#include "qtest.h"
#include "ISPTiltCorrection.h"
#include "iport.h"
#include "ISPDockWidget.h"
ISPTiltCorrection::ISPTiltCorrection(QWidget *parent, Qt::WindowFlags f ):
m_tiltLeftParaLabel(new QLabel(this)),
m_tiltRightParaLabel(new QLabel(this)),
m_tiltLeftParaLineEdit(new QLineEdit(this)),
m_tiltRightParaLineEdit(new QLineEdit(this)),
m_CorrectionDirectGroupBox(new QGroupBox(this)),
m_frontDirectionRadioButton(new QRadioButton(m_CorrectionDirectGroupBox)),
m_backDirectionRadioButton(new QRadioButton(m_CorrectionDirectGroupBox)),
m_tiltEnableCheckBox(new QCheckBox(this)),
m_tiltEnablePushButton(new QPushButton(this)),
m_verticalSpacer(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding)),
m_hlayout_1(new QHBoxLayout),
m_hlayout_2(new QHBoxLayout),
m_hGroupBoxlayout(new QHBoxLayout(m_CorrectionDirectGroupBox)),
m_hlayout_3(new QHBoxLayout),
m_vlayout(new QVBoxLayout(this)),
m_pCamera(nullptr)
{
	m_tiltLeftParaLabel->setText(QApplication::translate("MainWindow", "\345\267\246-\350\211\262\345\275\251\345\201\217\347\247\273\351\207\217(wl)\357\274\232", Q_NULLPTR));
	m_tiltRightParaLabel->setText(QApplication::translate("MainWindow", "\345\217\263-\350\211\262\345\275\251\345\201\217\347\247\273\351\207\217(wr)\357\274\232", Q_NULLPTR));
	m_CorrectionDirectGroupBox->setTitle(QApplication::translate("MainWindow", "\346\240\241\346\255\243\346\226\271\345\220\221(i_direction)\357\274\232", Q_NULLPTR));
	m_frontDirectionRadioButton->setText(QApplication::translate("MainWindow", "\345\220\221\345\211\215", Q_NULLPTR));
	m_backDirectionRadioButton->setText(QApplication::translate("MainWindow", "\345\220\221\345\220\216", Q_NULLPTR));
	m_tiltEnableCheckBox->setText(QApplication::translate("MainWindow", "\345\200\276\346\226\234\346\240\241\346\255\243 (i_TILT_en)", Q_NULLPTR));
	m_tiltEnablePushButton->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214\346\240\241\346\255\243", Q_NULLPTR));
	
	m_hlayout_1->addWidget(m_tiltLeftParaLabel);
	m_hlayout_1->addWidget(m_tiltLeftParaLineEdit);

	m_hlayout_2->addWidget(m_tiltRightParaLabel);
	m_hlayout_2->addWidget(m_tiltRightParaLineEdit);

	m_hGroupBoxlayout->addWidget(m_frontDirectionRadioButton);
	m_hGroupBoxlayout->addWidget(m_backDirectionRadioButton);

	m_hlayout_3->addWidget(m_tiltEnableCheckBox);
	m_hlayout_3->addWidget(m_tiltEnablePushButton);

	m_vlayout->addLayout(m_hlayout_1);
	m_vlayout->addLayout(m_hlayout_2);
	m_vlayout->addWidget(m_CorrectionDirectGroupBox);
	m_vlayout->addLayout(m_hlayout_3);

	m_vlayout->addItem(m_verticalSpacer);

	connect(m_tiltLeftParaLineEdit, SIGNAL(returnPressed()), this, SLOT(on_tiltLeftParaLineEdit_returnPressed()));
	connect(m_tiltRightParaLineEdit, SIGNAL(returnPressed()), this, SLOT(on_tiltRightParaLineEdit_returnPressed()));
	connect(m_frontDirectionRadioButton, SIGNAL(clicked(bool)), this, SLOT(on_frontDirectionRadioButton_clicked(bool)));
	connect(m_backDirectionRadioButton, SIGNAL(clicked(bool)), this, SLOT(on_backDirectionRadioButton_clicked(bool)));
	connect(m_tiltEnableCheckBox, SIGNAL(clicked(bool)), this, SLOT(on_tiltEnableCheckBox_clicked(bool)));
	connect(m_tiltEnablePushButton, SIGNAL(clicked()), this, SLOT(on_tiltEnablePushButton_clicked()));

}
ISPTiltCorrection::~ISPTiltCorrection()
{
}
void ISPTiltCorrection::on_tiltLeftParaLineEdit_returnPressed()
{
	float srtFloat = m_tiltLeftParaLineEdit->text().toFloat();
	quint32 srcInt16 = srtFloat * 128;

	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8 *)&srcInt16, TILT_PARA_L_1, sizeof(quint32));
}
void ISPTiltCorrection::on_tiltRightParaLineEdit_returnPressed()
{
	float srtFloat = m_tiltRightParaLineEdit->text().toFloat();
	quint32 srcInt16 = srtFloat * 128;

	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8 *)&srcInt16, TILT_PARA_R_1, sizeof(quint32));
}
void ISPTiltCorrection::on_frontDirectionRadioButton_clicked(bool isClicked)
{
	quint32 buffer = 1;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&buffer, DIRECTION, sizeof(quint32));
}
void ISPTiltCorrection::on_backDirectionRadioButton_clicked(bool isClicked)
{
	quint32 buffer = 0;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&buffer, DIRECTION, sizeof(quint32));
}
void ISPTiltCorrection::on_tiltEnableCheckBox_clicked(bool isClicked)
{
	quint32 enable = 1;
	quint32 disable = 0;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&enable, TILT_ENABLE, sizeof(quint32));
	else
		m_pCamera->GetCameraIPort()->write((quint8*)&disable, TILT_ENABLE, sizeof(quint32));
}
void ISPTiltCorrection::on_tiltEnablePushButton_clicked()
{
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	quint32 enable = 1;
	m_pCamera->GetCameraIPort()->write((quint8*)&enable, TILT_ENABLE, sizeof(quint32));
}