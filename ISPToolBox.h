#pragma once
#ifndef TOOLBOX_H
#define TOOLBOX_H
#include <QToolBox>
class ISPSpaceCorrection;
class ISPTiltCorrection;
class ISPFocusCorrection;
class ISPFFC1;
class ISPFFC2;
class ISPMC;
class ISPWB;
class ISPCC;

class ISPToolBox :public QToolBox
{
public:
	ISPToolBox();
	~ISPToolBox();
private:
	ISPSpaceCorrection* m_spaceCorrection;
	ISPTiltCorrection* m_tiltCorrection;
	ISPFocusCorrection* m_focusCorrection;
	ISPFFC1* m_FFC1;
	ISPFFC2* m_FFC2;
	ISPMC* m_MC;
	ISPWB* m_ISPWB;
	ISPCC* m_ISPCC;
};
#endif // !TOOLBOX_H
