#pragma once
#ifndef ISPMC_H
#define ISPMC_H
#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <memory>
#include "ISPRegisterDef.h"
namespace gcp2 {
class Camera;
}
class ISPMC:public QWidget
{
	Q_OBJECT
public:
	ISPMC(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ISPMC();
private:
	QCheckBox* m_MCEnableCheckBox;
	QLabel* m_sampleLineLabel;
	QLineEdit* m_sampleLineLineEdit;
	QLabel* m_referCamLabel;
	QComboBox* m_referCamComboBox;
	QCheckBox* m_camSampleEnableCheckBox;
	QPushButton* m_calcIncreasePushButton;
	QSpacerItem *m_verticalSpacer;

	QHBoxLayout* m_hlayout_1;
	QHBoxLayout* m_hlayout_2;
	QVBoxLayout* m_vlayout;
	std::shared_ptr<gcp2::Camera> m_pCamera;

};

#endif // !
