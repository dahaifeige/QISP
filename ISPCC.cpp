#include "Camera.h"
#include "qtest.h"
#include "ISPCC.h"
#include "iport.h"
#include "ISPDockWidget.h"
ISPCC::ISPCC(QWidget *parent, Qt::WindowFlags f):
m_CCMEnableCheckBox(new QCheckBox(this)),
m_CTChoseLabel(new QLabel(this)),
m_CTChoseComboBox(new QComboBox(this)),
m_CMatrixLabel(new QLabel(this)),
m_A11LineEdit(new QLineEdit(this)),
m_A12LineEdit(new QLineEdit(this)),
m_A13LineEdit(new QLineEdit(this)),
m_A21LineEdit(new QLineEdit(this)),
m_A22LineEdit(new QLineEdit(this)),
m_A23LineEdit(new QLineEdit(this)),
m_A31LineEdit(new QLineEdit(this)),
m_A32LineEdit(new QLineEdit(this)),
m_A33LineEdit(new QLineEdit(this)),
m_matrixComfirmPushButton(new QPushButton(this)),
m_resetPushButton(new QPushButton(this)),
m_verticalSpacer(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding)),
m_hlayout_1(new QHBoxLayout),
m_hlayout_2(new QHBoxLayout),
m_vlayout(new QVBoxLayout(this)),
m_gridlayout(new QGridLayout),
m_pCamera(nullptr)
{
	m_CCMEnableCheckBox->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\346\240\241\346\255\243(i_CCM_en)", Q_NULLPTR));
	m_CTChoseLabel->setText(QApplication::translate("MainWindow", "\350\211\262\346\270\251\351\200\211\346\213\251\357\274\232", Q_NULLPTR));
	m_CTChoseComboBox->clear();
	m_CTChoseComboBox->insertItems(0, QStringList()
		<< QApplication::translate("MainWindow", "1", Q_NULLPTR)
		<< QApplication::translate("MainWindow", "2", Q_NULLPTR)
		<< QApplication::translate("MainWindow", "3", Q_NULLPTR)
		<< QApplication::translate("MainWindow", "4", Q_NULLPTR)
		<< QApplication::translate("MainWindow", "5", Q_NULLPTR)
	);
	m_CMatrixLabel->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\347\237\251\351\230\265\357\274\232(iv_A11~iv_A33)", Q_NULLPTR));
	m_matrixComfirmPushButton->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", Q_NULLPTR));
	m_resetPushButton->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", Q_NULLPTR));

	m_hlayout_1->addWidget(m_CTChoseLabel);
	m_hlayout_1->addWidget(m_CTChoseComboBox);

	m_gridlayout->addWidget(m_A11LineEdit, 0, 0);
	m_gridlayout->addWidget(m_A12LineEdit, 0, 1);
	m_gridlayout->addWidget(m_A13LineEdit, 0, 2);
	m_gridlayout->addWidget(m_A21LineEdit, 1, 0);
	m_gridlayout->addWidget(m_A22LineEdit, 1, 1);
	m_gridlayout->addWidget(m_A23LineEdit, 1, 2);
	m_gridlayout->addWidget(m_A31LineEdit, 2, 0);
	m_gridlayout->addWidget(m_A32LineEdit, 2, 1);
	m_gridlayout->addWidget(m_A33LineEdit, 2, 2);

	m_vlayout->addWidget(m_CCMEnableCheckBox);
	m_vlayout->addLayout(m_hlayout_1);
	m_vlayout->addWidget(m_CMatrixLabel);
	m_vlayout->addLayout(m_gridlayout);

	m_vlayout->addWidget(m_matrixComfirmPushButton);
	m_vlayout->addWidget(m_resetPushButton);

	m_vlayout->addItem(m_verticalSpacer);

	connect(m_CCMEnableCheckBox, SIGNAL(clicked(bool)), this, SLOT(on_CCMEnableCheckBox_clicked(bool)));
	connect(m_matrixComfirmPushButton, SIGNAL(clicked(bool)), this, SLOT(on_matrixComfirmPushButton_clicked(bool)));
	connect(m_CTChoseComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(CTchose(int)));
}


ISPCC::~ISPCC()
{
}

void ISPCC::on_CCMEnableCheckBox_clicked(bool isClicked)
{
	quint32 enable = 1;
	quint32 disable = 0;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&enable, CCM_EN_REG, sizeof(quint32));
	else
		m_pCamera->GetCameraIPort()->write((quint8*)&disable, CCM_EN_REG, sizeof(quint32));
}
void ISPCC::on_matrixComfirmPushButton_clicked(bool)
{

	qint32 a11 = m_A11LineEdit->text().toInt(nullptr, 10);
	qint32 a12 = m_A12LineEdit->text().toInt(nullptr, 10);
	qint32 a13 = m_A13LineEdit->text().toInt(nullptr, 10);

	qint32 a21 = m_A21LineEdit->text().toInt(nullptr, 10);
	qint32 a22 = m_A22LineEdit->text().toInt(nullptr, 10);
	qint32 a23 = m_A23LineEdit->text().toInt(nullptr, 10);

	qint32 a31 = m_A31LineEdit->text().toInt(nullptr, 10);
	qint32 a32 = m_A32LineEdit->text().toInt(nullptr, 10);
	qint32 a33 = m_A33LineEdit->text().toInt(nullptr, 10);

	if (a11 < 0)
	{
		a11 = -a11;
		a11 |= 0x8000;
	}
	if (a12 < 0)
	{
		a12 = -a12;
		a12 |= 0x8000;
	}
	if (a13 < 0)
	{
		a13 = -a13;
		a13 |= 0x8000;
	}
	if (a21 < 0)
	{
		a21 = -a21;
		a21 |= 0x8000;
	}
	if (a22 < 0)
	{
		a22 = -a22;
		a22 |= 0x8000;
	}
	if (a23 < 0)
	{
		a23 = -a23;
		a23 |= 0x8000;
	}
	if (a31 < 0)
	{
		a31 = -a31;
		a31 |= 0x8000;
	}
	if (a32 < 0)
	{
		a32 = -a32;
		a32 |= 0x8000;
	}
	if (a33 < 0)
	{
		a33 = -a33;
		a33 |= 0x8000;
	}
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;

	m_pCamera->GetCameraIPort()->write((quint8 *)&a11, CCM_A11_REG, sizeof(quint32));
	m_pCamera->GetCameraIPort()->write((quint8 *)&a12, CCM_A12_REG, sizeof(quint32));
	m_pCamera->GetCameraIPort()->write((quint8 *)&a13, CCM_A13_REG, sizeof(quint32));

	m_pCamera->GetCameraIPort()->write((quint8 *)&a21, CCM_A21_REG, sizeof(quint32));
	m_pCamera->GetCameraIPort()->write((quint8 *)&a22, CCM_A22_REG, sizeof(quint32));
	m_pCamera->GetCameraIPort()->write((quint8 *)&a23, CCM_A23_REG, sizeof(quint32));

	m_pCamera->GetCameraIPort()->write((quint8 *)&a31, CCM_A31_REG, sizeof(quint32));
	m_pCamera->GetCameraIPort()->write((quint8 *)&a32, CCM_A32_REG, sizeof(quint32));
	m_pCamera->GetCameraIPort()->write((quint8 *)&a33, CCM_A33_REG, sizeof(quint32));

}
void ISPCC::CTchose(int index)
{
	if (index == 4)
		m_resetPushButton->setEnabled(false);
	else
		m_resetPushButton->setEnabled(true);
	quint32 sendIndex = index + 1;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8 *)&sendIndex, CCM_CT_REG, sizeof(quint32));
	m_pCamera->GetCameraIPort()->write((quint8 *)&sendIndex, CCM_CT_REG, sizeof(quint32));

}