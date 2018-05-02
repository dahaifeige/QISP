
#include "ISPToolBox.h"
#include "ISPSpaceCorrection.h"
#include "ISPTiltCorrection.h"
#include "ISPFocusCorrection.h"
#include "ISPFFC1.h"
#include "ISPFFC2.h"
#include "ISPMC.h"
#include "ISPWB.h"
#include "ISPCC.h"
ISPToolBox::ISPToolBox():
m_spaceCorrection(new ISPSpaceCorrection),
m_tiltCorrection(new ISPTiltCorrection),
m_focusCorrection(new ISPFocusCorrection),
m_FFC1(new ISPFFC1),
m_FFC2(new ISPFFC2),
m_MC(new ISPMC),
m_ISPWB(new ISPWB),
m_ISPCC(new ISPCC)
{
	addItem(m_spaceCorrection, QApplication::translate("MainWindow", "\347\251\272\351\227\264\346\240\241\346\255\243", Q_NULLPTR));
	addItem(m_tiltCorrection, QApplication::translate("MainWindow", "\345\200\276\346\226\234\346\240\241\346\255\243", Q_NULLPTR));
	addItem(m_focusCorrection, QString::fromUtf8("\350\276\205\345\212\251\345\257\271\347\204\246"));
	addItem(m_FFC1, QStringLiteral("FFC1"));
	addItem(m_FFC2, QStringLiteral("FFC2"));
	addItem(m_MC, QString::fromUtf8("\350\201\224\345\220\210\345\271\263\345\234\272\346\240\241\345\207\206"));
	addItem(m_ISPWB, QString::fromUtf8("\347\231\275\345\271\263\350\241\241"));
	addItem(m_ISPCC, QString::fromUtf8("\351\242\234\350\211\262\346\240\241\346\255\243"));

}

ISPToolBox::~ISPToolBox()
{
}
