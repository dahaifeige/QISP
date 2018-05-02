#include "Camera.h"
#include "qtest.h"
#include "ISPFFC1.h"
#include "iport.h"
#include "ISPDockWidget.h"
ISPFFC1::ISPFFC1(QWidget * parent, Qt::WindowFlags f):
m_FFC1EnableCheckBox(new QCheckBox(this)),
m_FFC1_SampleLineLabel(new QLabel(this)),
m_FFC1_SampleLineLineEdit(new QLineEdit(this)),
m_FPN1EnablePushButton(new QPushButton(this)),
m_PRNU1EnablePushButton(new QPushButton(this)),
m_FFC1ParaReturnPushButton(new QPushButton(this)),
m_verticalSpacer(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding)),
m_hlayout(new QHBoxLayout),
m_vlayout(new QVBoxLayout(this)),
m_pCamera(nullptr)
{
	m_FFC1EnableCheckBox->setText(QApplication::translate("MainWindow", "FFC1 (i_FFC1_en)", Q_NULLPTR));
	m_FFC1_SampleLineLabel->setText(QApplication::translate("MainWindow", "\351\207\207\346\240\267\350\241\214\346\225\260\357\274\232", Q_NULLPTR));
	m_FPN1EnablePushButton->setText(QApplication::translate("MainWindow", "\346\232\227\345\234\272\346\240\241\346\255\243\344\275\277\350\203\275(i_FPN1_once)", Q_NULLPTR));
	m_PRNU1EnablePushButton->setText(QApplication::translate("MainWindow", "\344\272\256\345\234\272\346\240\241\346\255\243\344\275\277\350\203\275(i_PRNU1_once)", Q_NULLPTR));
	m_FFC1ParaReturnPushButton->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\345\233\236\350\257\273", Q_NULLPTR));

	m_hlayout->addWidget(m_FFC1_SampleLineLabel);
	m_hlayout->addWidget(m_FFC1_SampleLineLineEdit);

	m_vlayout->addWidget(m_FFC1EnableCheckBox);
	m_vlayout->addLayout(m_hlayout);
	m_vlayout->addWidget(m_FPN1EnablePushButton);
	m_vlayout->addWidget(m_PRNU1EnablePushButton);
	m_vlayout->addWidget(m_FFC1ParaReturnPushButton);

	m_vlayout->addItem(m_verticalSpacer);


	connect(m_FFC1EnableCheckBox, SIGNAL(clicked(bool)), this, SLOT(on_FFC1EnableCheckBox_clicked(bool)));
	connect(m_FFC1_SampleLineLineEdit, SIGNAL(returnPressed()), this, SLOT(on_FFC1_SampleLineLineEdit_returnPressed()));
	connect(m_FPN1EnablePushButton, SIGNAL(clicked()), this, SLOT(on_FPN1EnablePushButton_clicked()));
	connect(m_PRNU1EnablePushButton, SIGNAL(clicked()), this, SLOT(on_PRNU1EnablePushButton_clicked()));
	connect(m_FFC1ParaReturnPushButton, SIGNAL(clicked()), this, SLOT(on_FFC1ParaReturnPushButton_clicked()));
}

ISPFFC1::~ISPFFC1()
{
}
void ISPFFC1::on_FFC1EnableCheckBox_clicked(bool isClicked)
{
	quint32 enable = 1;
	quint32 disable = 0;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	if (isClicked)
		m_pCamera->GetCameraIPort()->write((quint8*)&enable, FFC1_ENB_REG, sizeof(quint32));
	else
		m_pCamera->GetCameraIPort()->write((quint8*)&disable, FFC1_ENB_REG, sizeof(quint32));
}
void ISPFFC1::on_FFC1_SampleLineLineEdit_returnPressed()
{
	quint32 srtInt8 = m_FFC1_SampleLineLineEdit->text().toInt(nullptr, 10);
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8*)&srtInt8, FFC1_CSS_REG, sizeof(quint32));
}
void ISPFFC1::on_FPN1EnablePushButton_clicked()
{
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	quint32 enable = 1;
	m_pCamera->GetCameraIPort()->write((quint8*)&enable, FPN1_CALIBRATION_REG, sizeof(quint32));
}
void ISPFFC1::on_PRNU1EnablePushButton_clicked()
{
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	quint32 enable = 1;
	m_pCamera->GetCameraIPort()->write((quint8*)&enable, PRNU1_CALIBRATION_REG, sizeof(quint32));
}
void ISPFFC1::on_FFC1ParaReturnPushButton_clicked()
{

}