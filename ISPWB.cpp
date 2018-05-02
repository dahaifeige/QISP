#include "Camera.h"
#include "qtest.h"
#include "ISPWB.h"
#include "Camera.h"
#include "iport.h"
#include "ISPDockWidget.h"
ISPWB::ISPWB(QWidget *parent, Qt::WindowFlags f):
m_WBEnableCheckBox(new QCheckBox(this)),
m_correctionMode(new QGroupBox(this)),
m_staticModeRadioButton(new QRadioButton(m_correctionMode)),
m_smartModeRadioButton(new QRadioButton(m_correctionMode)),
m_SampleLineLabel(new QLabel(this)),
m_SampleLineLineEdit(new QLineEdit(this)),
m_startXPosLabel(new QLabel(this)),
m_startXPosLineEdit(new QLineEdit(this)),
m_startYPosLabel(new QLabel(this)),
m_startYPosLineEdit(new QLineEdit(this)),

m_rGainLabel(new QLabel(this)),
m_rGainLineEdit(new QLineEdit(this)),
m_rReadGainLabel(new QLabel(this)),
m_rReadPushButton(new QPushButton(this)),

m_gGainLabel(new QLabel(this)),
m_gGainLineEdit(new QLineEdit(this)),
m_gReadGainLabel(new QLabel(this)),
m_gReadPushButton(new QPushButton(this)),

m_bGainLabel(new QLabel(this)),
m_bReadGainLabel(new QLabel(this)),
m_bGainLineEdit(new QLineEdit(this)),
m_bReadPushButton(new QPushButton(this)),

m_sampleEnablePushButton(new QPushButton(this)),
m_verticalSpacer(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding)),
m_hlayout_1(new QHBoxLayout(m_correctionMode)),
m_hlayout_2(new QHBoxLayout),
m_hlayout_3(new QHBoxLayout),
m_hlayout_4(new QHBoxLayout),
m_hlayout_5(new QHBoxLayout),
m_hlayout_6(new QHBoxLayout),
m_hlayout_7(new QHBoxLayout),
m_vlayout(new QVBoxLayout(this)),
m_pCamera(nullptr),
m_bStaticMode(false), m_bSmartMode(false)

{
	m_WBEnableCheckBox->setText(QApplication::translate("MainWindow", "\347\231\275\345\271\263\350\241\241(i_AWB_en)", Q_NULLPTR));
	m_correctionMode->setTitle(QApplication::translate("MainWindow", "\346\240\241\346\255\243\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
	m_staticModeRadioButton->setText(QApplication::translate("MainWindow", "\351\235\231\346\200\201\346\250\241\345\274\217", Q_NULLPTR));
	m_smartModeRadioButton->setText(QApplication::translate("MainWindow", "smart\346\250\241\345\274\217", Q_NULLPTR));
	m_SampleLineLabel->setText(QApplication::translate("MainWindow", "\351\207\207\346\240\267\350\241\214\346\225\260\357\274\232(iv_CSS)", Q_NULLPTR));
	m_startXPosLabel->setText(QApplication::translate("MainWindow", "\350\265\267\345\247\213\345\235\220\346\240\207\357\274\232(iv_X)", Q_NULLPTR));
	m_startYPosLabel->setText(QApplication::translate("MainWindow", "\347\273\210\346\255\242\345\235\220\346\240\207\357\274\232(iv_Y)", Q_NULLPTR));
	m_rGainLabel->setText(QApplication::translate("MainWindow", "B\345\242\236\347\233\212\357\274\232", Q_NULLPTR));
	m_gGainLabel->setText(QApplication::translate("MainWindow", "G\345\242\236\347\233\212\357\274\232", Q_NULLPTR));
	m_bGainLabel->setText(QApplication::translate("MainWindow", "R\345\242\236\347\233\212\357\274\232", Q_NULLPTR));
	m_rReadGainLabel->setText("BValue");
	m_gReadGainLabel->setText("GValue");
	m_bReadGainLabel->setText("RValue");
	m_rReadPushButton->setText("ReadBValue");
	m_gReadPushButton->setText("ReadGValue");
	m_bReadPushButton->setText("ReadRValue");
	m_sampleEnablePushButton->setText(QApplication::translate("MainWindow", "\346\240\207\345\256\232\344\275\277\350\203\275(i_C_once)", Q_NULLPTR));

	m_hlayout_1->addWidget(m_staticModeRadioButton);
	m_hlayout_1->addWidget(m_smartModeRadioButton);

	m_hlayout_2->addWidget(m_SampleLineLabel);
	m_hlayout_2->addWidget(m_SampleLineLineEdit);

	m_hlayout_3->addWidget(m_startXPosLabel);
	m_hlayout_3->addWidget(m_startXPosLineEdit);

	m_hlayout_4->addWidget(m_startYPosLabel);
	m_hlayout_4->addWidget(m_startYPosLineEdit);

	m_hlayout_5->addWidget(m_rGainLabel);
	m_hlayout_5->addWidget(m_rGainLineEdit);
	m_hlayout_5->addWidget(m_rReadGainLabel);
	m_hlayout_5->addWidget(m_rReadPushButton);

	m_hlayout_6->addWidget(m_gGainLabel);
	m_hlayout_6->addWidget(m_gGainLineEdit);
	m_hlayout_6->addWidget(m_gReadGainLabel);
	m_hlayout_6->addWidget(m_gReadPushButton);

	m_hlayout_7->addWidget(m_bGainLabel);
	m_hlayout_7->addWidget(m_bGainLineEdit);
	m_hlayout_7->addWidget(m_bReadGainLabel);
	m_hlayout_7->addWidget(m_bReadPushButton);

	m_vlayout->addWidget(m_WBEnableCheckBox);
	m_vlayout->addWidget(m_correctionMode);

	m_vlayout->addLayout(m_hlayout_2);
	m_vlayout->addLayout(m_hlayout_3);
	m_vlayout->addLayout(m_hlayout_4);
	m_vlayout->addLayout(m_hlayout_5);
	m_vlayout->addLayout(m_hlayout_6);
	m_vlayout->addLayout(m_hlayout_7);
	m_vlayout->addWidget(m_sampleEnablePushButton);

	m_vlayout->addItem(m_verticalSpacer);

	connect(m_WBEnableCheckBox, SIGNAL(clicked(bool)), this, SLOT(on_AWBEnableCheckBox_clicked(bool)));
	connect(m_staticModeRadioButton, SIGNAL(clicked(bool)), this, SLOT(on_AWBStaticModeRadioButton_clicked(bool)));
	connect(m_smartModeRadioButton, SIGNAL(clicked(bool)), this, SLOT(on_AWBSmartModeRadioButton_clicked(bool)));
	connect(m_SampleLineLineEdit, SIGNAL(returnPressed()), this, SLOT(on_SampleLineNumLineEdit_returnPressed()));
	connect(m_startXPosLineEdit, SIGNAL(returnPressed()), this, SLOT(on_startXPosLineEdit_returnPressed()));
	connect(m_startYPosLineEdit, SIGNAL(returnPressed()), this, SLOT(on_startYPosLineEdit_returnPressed()));
	connect(m_rGainLineEdit, SIGNAL(returnPressed()), this, SLOT(on_rGainLineEdit_returnPressed()));
	connect(m_gGainLineEdit, SIGNAL(returnPressed()), this, SLOT(on_gGainLineEdit_returnPressed()));
	connect(m_bGainLineEdit, SIGNAL(returnPressed()), this, SLOT(on_bGainLineEdit_returnPressed()));
	connect(m_sampleEnablePushButton, SIGNAL(clicked()), this, SLOT(on_gainCalOnceEnablePushButton_clicked()));
	connect(m_rReadPushButton, SIGNAL(clicked()), this, SLOT(on_rReadPushButton_clicked()));
	connect(m_gReadPushButton, SIGNAL(clicked()), this, SLOT(on_gReadPushButton_clicked()));
	connect(m_bReadPushButton, SIGNAL(clicked()), this, SLOT(on_bReadPushButton_clicked()));


}


ISPWB::~ISPWB()
{
}

void ISPWB::on_AWBEnableCheckBox_clicked(bool isClicked)
{
	quint32 enable = 1;
	quint32 disable = 0;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&enable, AWB_EN_REG, sizeof(quint32));
	else
		m_pCamera->GetCameraIPort()->write((quint8*)&disable, AWB_EN_REG, sizeof(quint32));
}
void ISPWB::on_AWBStaticModeRadioButton_clicked(bool isClicked)
{
	quint32 buffer = 0;
	if (isClicked)
	{
		m_startXPosLineEdit->setEnabled(false);
		m_startYPosLineEdit->setEnabled(false);
		m_rGainLineEdit->setEnabled(true);
		m_gGainLineEdit->setEnabled(true);
		m_bGainLineEdit->setEnabled(true);
		m_sampleEnablePushButton->setEnabled(true);

		m_pCamera = ISPDockWidget::GetCamera();
		if (!m_pCamera)
			return;
		if (!(m_pCamera->GetCameraIPort()))
			return;
		m_pCamera->GetCameraIPort()->write((quint8*)&buffer, AWB_MODE_REG, sizeof(quint32));
		m_bStaticMode = true;
		m_bSmartMode = false;
	}

}
void ISPWB::on_AWBSmartModeRadioButton_clicked(bool isClicked)
{
	quint32 buffer = 1;

	if (isClicked)
	{
		m_startXPosLineEdit->setEnabled(true);
		m_startYPosLineEdit->setEnabled(true);
		m_rGainLineEdit->setEnabled(false);
		m_gGainLineEdit->setEnabled(false);
		m_bGainLineEdit->setEnabled(false);
		m_sampleEnablePushButton->setEnabled(false);

		m_pCamera = ISPDockWidget::GetCamera();
		if (!m_pCamera)
			return;
		if (!(m_pCamera->GetCameraIPort()))
			return;
		m_pCamera->GetCameraIPort()->write((quint8*)&buffer, AWB_MODE_REG, sizeof(quint32));
		m_bSmartMode = true;
		m_bStaticMode = false;
	}

}
void ISPWB::on_SampleLineNumLineEdit_returnPressed()
{
	quint32 srtInt16 = m_SampleLineLineEdit->text().toInt(nullptr, 10);
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8 *)&srtInt16, AWB_HIGH_REG, sizeof(quint32));
}
void ISPWB::on_startXPosLineEdit_returnPressed()
{
	quint32 srtInt16 = m_startXPosLineEdit->text().toInt(nullptr, 10);
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8 *)&srtInt16, STARTX_REG, sizeof(quint32));
}
void ISPWB::on_startYPosLineEdit_returnPressed()
{
	quint32 srtInt16 = m_startYPosLineEdit->text().toInt(nullptr, 10);
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8 *)&srtInt16, ENDX_REG, sizeof(quint32));
}
void ISPWB::on_rGainLineEdit_returnPressed()
{
	quint32 srtInt16 = m_rGainLineEdit->text().toInt(nullptr, 10);

	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8 *)&srtInt16, WB_RGAIN_REG, sizeof(quint32));

}
void ISPWB::on_gGainLineEdit_returnPressed()
{
	/*quint32 srtInt16 = m_gGainLineEdit->text().toInt(nullptr, 10);

	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (m_bStaticMode)
		m_pCamera->GetCameraIPort()->write((quint8 *)&srtInt16, WB_RGAIN_REG, sizeof(quint32));
	if (m_bSmartMode)
		m_pCamera->GetCameraIPort()->write((quint8 *)&srtInt16, AWB_RGAIN_REG, sizeof(quint32));*/
}
void ISPWB::on_bGainLineEdit_returnPressed()
{
	quint32 srtInt16 = m_bGainLineEdit->text().toInt(nullptr, 10);

	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8 *)&srtInt16, WB_BGAIN_REG, sizeof(quint32));
}
void ISPWB::on_gainCalOnceEnablePushButton_clicked()
{
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	quint32 enable = 1;
	m_pCamera->GetCameraIPort()->write((quint8*)&enable, GAIN_CAL_ONCE_REG, sizeof(quint32));
}

void ISPWB::on_rReadPushButton_clicked()
{
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	quint32 srtInt32;
	if (m_bStaticMode)
		m_pCamera->GetCameraIPort()->read((quint8 *)&srtInt32, WB_RGAIN_REG, sizeof(quint32));
	if (m_bSmartMode)
		m_pCamera->GetCameraIPort()->read((quint8 *)&srtInt32, AWB_RGAIN_REG, sizeof(quint32));
	m_rReadGainLabel->setText(QString::number(srtInt32, 10));
}

void ISPWB::on_gReadPushButton_clicked()
{
	/*m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	quint32 srtInt32;
	if (m_bStaticMode)
		m_pCamera->GetCameraIPort()->read((quint8 *)&srtInt32, WB_GGAIN_REG, sizeof(quint32));
	if (m_bSmartMode)
		m_pCamera->GetCameraIPort()->read((quint8 *)&srtInt32, AWB_RGAIN_REG, sizeof(quint32));
	m_gReadGainLabel->setText(QString::number(srtInt32, 10));*/
}

void ISPWB::on_bReadPushButton_clicked()
{
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	quint32 srtInt32;
	if (m_bStaticMode)
		m_pCamera->GetCameraIPort()->read((quint8 *)&srtInt32, WB_BGAIN_REG, sizeof(quint32));
	if (m_bSmartMode)
		m_pCamera->GetCameraIPort()->read((quint8 *)&srtInt32, AWB_BGAIN_REG, sizeof(quint32));
	m_bReadGainLabel->setText(QString::number(srtInt32, 10));
}
