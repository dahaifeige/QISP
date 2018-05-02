#include "Camera.h"
#include "qtest.h"
#include "ISPMC.h"
#include "iport.h"
#include "ISPDockWidget.h"
ISPMC::ISPMC(QWidget *parent, Qt::WindowFlags f):
m_MCEnableCheckBox(new QCheckBox(this)),
m_sampleLineLabel(new QLabel(this)),
m_sampleLineLineEdit(new QLineEdit(this)),
m_referCamLabel(new QLabel(this)),
m_referCamComboBox(new QComboBox(this)),
m_camSampleEnableCheckBox(new QCheckBox(this)),
m_calcIncreasePushButton(new QPushButton(this)),
m_verticalSpacer(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding)),
m_hlayout_1(new QHBoxLayout),
m_hlayout_2(new QHBoxLayout),
m_vlayout(new QVBoxLayout(this)),
m_pCamera(nullptr)
{
	m_MCEnableCheckBox->setText(QApplication::translate("MainWindow", "\350\201\224\345\220\210\345\271\263\345\234\272\346\240\241\345\207\206(i_MC_en)", Q_NULLPTR));
	m_sampleLineLabel->setText(QApplication::translate("MainWindow", "\351\207\207\346\240\267\350\241\214\346\225\260\357\274\232(iv_CSS)", Q_NULLPTR));
	m_referCamLabel->setText(QApplication::translate("MainWindow", "\345\217\202\350\200\203\347\233\270\346\234\272\357\274\232", Q_NULLPTR));
	m_referCamComboBox->clear();
	m_referCamComboBox->insertItems(0, QStringList()
		<< QApplication::translate("MainWindow", "1", Q_NULLPTR)
		<< QApplication::translate("MainWindow", "2", Q_NULLPTR)
		<< QApplication::translate("MainWindow", "3", Q_NULLPTR)
		<< QApplication::translate("MainWindow", "4", Q_NULLPTR)
	);
	m_camSampleEnableCheckBox->setText(QApplication::translate("MainWindow", "\347\233\270\346\234\272\346\240\207\345\256\232\344\275\277\350\203\275(i_DO_I_once)", Q_NULLPTR));
	m_calcIncreasePushButton->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227\345\242\236\347\233\212(i_MC_once)", Q_NULLPTR));

	m_hlayout_1->addWidget(m_sampleLineLabel);
	m_hlayout_1->addWidget(m_sampleLineLineEdit);

	m_hlayout_2->addWidget(m_referCamLabel);
	m_hlayout_2->addWidget(m_referCamComboBox);

	m_vlayout->addWidget(m_MCEnableCheckBox);
	m_vlayout->addLayout(m_hlayout_1);
	m_vlayout->addLayout(m_hlayout_2);
	m_vlayout->addWidget(m_camSampleEnableCheckBox);
	m_vlayout->addWidget(m_calcIncreasePushButton);

	m_vlayout->addItem(m_verticalSpacer);



}


ISPMC::~ISPMC()
{
}
