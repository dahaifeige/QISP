#include "Camera.h"
#include "qtest.h"
#include "ISPFFC2.h"
#include "iport.h"
#include "ISPDockWidget.h"
ISPFFC2::ISPFFC2(QWidget *parent, Qt::WindowFlags f):
m_FFC2EnableCheckBox(new QCheckBox(this)),
m_correctionMode(new QGroupBox(this)),
m_mannerModeRadioButton(new QRadioButton(m_correctionMode)),
m_oneKeyModeRadioButton(new QRadioButton(m_correctionMode)),
m_sampleLineLabel(new QLabel(this)),
m_sampleLineLineEdit(new QLineEdit(this)),
m_startXPosLabel(new QLabel(this)),
m_startXPosLineEdit(new QLineEdit(this)),
m_startYPosLabel(new QLabel(this)),
m_startYPosLineEdit(new QLineEdit(this)),
m_FT2EnableCheckBox(new QCheckBox(this)),
m_VWindowLabel(new QLabel(this)),
m_VWindowLineEdit(new QLineEdit(this)),
m_FPN2EnablePushButton(new QPushButton(this)),
m_PRNU2EnablePushButton(new QPushButton(this)),
m_FFC2ParaReturnPushButton(new QPushButton(this)),
m_pCamera(nullptr),
m_verticalSpacer(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding)),
m_hlayout_1(new QHBoxLayout(m_correctionMode)),
m_hlayout_2(new QHBoxLayout),
m_hlayout_3(new QHBoxLayout),
m_hlayout_4(new QHBoxLayout),
m_hlayout_5(new QHBoxLayout),
m_vlayout(new QVBoxLayout(this))
{
	m_FFC2EnableCheckBox->setText(QApplication::translate("MainWindow", "FFC2 (i_FFC2_en)", Q_NULLPTR));
	m_correctionMode->setTitle(QApplication::translate("MainWindow", "\346\240\241\346\255\243\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
	m_mannerModeRadioButton->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\346\250\241\345\274\217", Q_NULLPTR));
	m_oneKeyModeRadioButton->setText(QApplication::translate("MainWindow", "\344\270\200\351\224\256\345\274\217", Q_NULLPTR));
	m_sampleLineLabel->setText(QApplication::translate("MainWindow", "\351\207\207\346\240\267\350\241\214\346\225\260\357\274\232(iv_CSS)", Q_NULLPTR));
	m_startXPosLabel->setText(QApplication::translate("MainWindow", "\350\265\267\345\247\213\345\235\220\346\240\207\357\274\232(iv_X)", Q_NULLPTR));
	m_startYPosLabel->setText(QApplication::translate("MainWindow", "\347\273\210\346\255\242\345\235\220\346\240\207\357\274\232(iv_Y)", Q_NULLPTR));
	m_FT2EnableCheckBox->setText(QApplication::translate("MainWindow", "\346\273\244\346\263\242\344\275\277\350\203\275 (i_FT2_EN)", Q_NULLPTR));
	m_VWindowLabel->setText(QApplication::translate("MainWindow", "\346\273\244\346\263\242\347\252\227\345\217\243\357\274\232(iv_wn)", Q_NULLPTR));
	m_FPN2EnablePushButton->setText(QApplication::translate("MainWindow", "\346\232\227\345\234\272\346\240\241\345\207\206\344\275\277\350\203\275(i_FPN2_once)", Q_NULLPTR));
	m_PRNU2EnablePushButton->setText(QApplication::translate("MainWindow", "\344\272\256\345\234\272\346\240\241\345\207\206\344\275\277\350\203\275(i_PRNU2_once)", Q_NULLPTR));
	m_FFC2ParaReturnPushButton->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\345\233\236\350\257\273", Q_NULLPTR));

	m_hlayout_1->addWidget(m_mannerModeRadioButton);
	m_hlayout_1->addWidget(m_oneKeyModeRadioButton);
	
	m_hlayout_2->addWidget(m_sampleLineLabel);
	m_hlayout_2->addWidget(m_sampleLineLineEdit);

	m_hlayout_3->addWidget(m_startXPosLabel);
	m_hlayout_3->addWidget(m_startXPosLineEdit);

	m_hlayout_4->addWidget(m_startYPosLabel);
	m_hlayout_4->addWidget(m_startYPosLineEdit);

	m_hlayout_5->addWidget(m_VWindowLabel);
	m_hlayout_5->addWidget(m_VWindowLineEdit);

	m_vlayout->addWidget(m_FFC2EnableCheckBox);
	m_vlayout->addWidget(m_correctionMode);
	m_vlayout->addLayout(m_hlayout_2);
	m_vlayout->addLayout(m_hlayout_3);
	m_vlayout->addLayout(m_hlayout_4);
	m_vlayout->addWidget(m_FT2EnableCheckBox);

	m_vlayout->addLayout(m_hlayout_5);
	m_vlayout->addWidget(m_FPN2EnablePushButton);
	m_vlayout->addWidget(m_PRNU2EnablePushButton);
	m_vlayout->addWidget(m_FFC2ParaReturnPushButton);

	m_vlayout->addItem(m_verticalSpacer);


	connect(m_FFC2EnableCheckBox, SIGNAL(clicked(bool)), this, SLOT(on_FFC2EnableCheckBox_clicked(bool)));
	connect(m_mannerModeRadioButton, SIGNAL(clicked(bool)), this, SLOT(on_MannerModeRadioButton_clicked(bool)));
	connect(m_oneKeyModeRadioButton, SIGNAL(clicked(bool)), this, SLOT(on_OneKeyModeRadioButton_clicked(bool)));
	connect(m_sampleLineLineEdit, SIGNAL(returnPressed()), this, SLOT(on_SampleLineLineEdit_returnPressed()));
	connect(m_startXPosLineEdit, SIGNAL(returnPressed()), this, SLOT(on_StartXPosLineEdit_returnPressed()));
	connect(m_startYPosLineEdit, SIGNAL(returnPressed()), this, SLOT(on_StartYPosLineEdit_returnPressed()));
	connect(m_FT2EnableCheckBox, SIGNAL(clicked(bool)), this, SLOT(on_FT2EnableCheckBox_clicked(bool)));
	connect(m_VWindowLineEdit, SIGNAL(returnPressed()), this, SLOT(on_VWindowLineEdit_returnPressed()));
	connect(m_FPN2EnablePushButton, SIGNAL(clicked()), this, SLOT(on_FPN2EnablePushButton_clicked()));
	connect(m_PRNU2EnablePushButton, SIGNAL(clicked()), this, SLOT(on_PRNU2EnablePushButton_clicked()));
	connect(m_FFC2ParaReturnPushButton, SIGNAL(clicked()), this, SLOT(on_FFC2ParaReturnPushButton_clicked()));

}


ISPFFC2::~ISPFFC2()
{
}

void ISPFFC2::on_FFC2EnableCheckBox_clicked(bool isClicked)
{
	quint32 enable = 1;
	quint32 disable = 0;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&enable, FFC2_ENB_REG, sizeof(quint32));
	else
		m_pCamera->GetCameraIPort()->write((quint8*)&disable, FFC2_ENB_REG, sizeof(quint32));
}
void ISPFFC2::on_MannerModeRadioButton_clicked(bool isClicked)
{
	quint32 buffer = 0;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&buffer, FFC2_MODE_REG, sizeof(quint32));
}
void ISPFFC2::on_OneKeyModeRadioButton_clicked(bool isClicked)
{
	quint32 buffer = 1;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&buffer, FFC2_MODE_REG, sizeof(quint32));
}
void ISPFFC2::on_SampleLineLineEdit_returnPressed()
{
	quint32 srtInt8 = m_sampleLineLineEdit->text().toInt(nullptr, 10);

	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8*)&srtInt8, FFC2_CSS_REG, sizeof(quint32));
}
void ISPFFC2::on_StartXPosLineEdit_returnPressed()
{
	quint32 srtInt16 = m_startXPosLineEdit->text().toInt(nullptr, 10);
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8*)&srtInt16, FFC2_CALIB_START_X_8bits, sizeof(quint32));
}
void ISPFFC2::on_StartYPosLineEdit_returnPressed()
{
	quint32 srtInt16 = m_startYPosLineEdit->text().toInt(nullptr, 10);
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8*)&srtInt16, FFC2_CALIB_END_X_8bits, sizeof(quint32));
}
void ISPFFC2::on_FT2EnableCheckBox_clicked(bool isClicked)
{
	quint32 enable = 1;
	quint32 disable = 0;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&enable, FT_ENB_REG, sizeof(quint32));
	else
		m_pCamera->GetCameraIPort()->write((quint8*)&disable, FT_ENB_REG, sizeof(quint32));

}
void ISPFFC2::on_VWindowLineEdit_returnPressed()
{
	quint32 srtInt8 = m_VWindowLineEdit->text().toInt(nullptr, 10);

	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8*)&srtInt8, WN_REG, sizeof(quint32));
}
void ISPFFC2::on_FPN2EnablePushButton_clicked()
{
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	quint32 enable = 1;
	m_pCamera->GetCameraIPort()->write((quint8*)&enable, FPN2_CALIBRATION_REG, sizeof(quint32));
}
void ISPFFC2::on_PRNU2EnablePushButton_clicked()
{
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	quint32 enable = 1;
	m_pCamera->GetCameraIPort()->write((quint8*)&enable, PRNU2_CALIBRATION_REG, sizeof(quint32));
}
void ISPFFC2::on_FFC2ParaReturnPushButton_clicked()
{
}