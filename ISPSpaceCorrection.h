#pragma once
#ifndef SPACECORRECTION_H
#define SPACECORRECTION_H
#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <memory>
#include "ISPRegisterDef.h"
namespace gcp2 {
	class Camera;
}
class ISPSpaceCorrection :public QWidget
{
	Q_OBJECT
public:
	ISPSpaceCorrection(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ISPSpaceCorrection();
public slots:
	void on_SCEnableCheckBox_clicked(bool isClicked);
	void on_SCValueLineEdit_returnPressed();
	void on_RGBDirectRadioButton_clicked(bool isClicked);
	void on_BGRDirectRadioButton_clicked(bool isClicked);
private:
	QCheckBox *m_SCEnableCheckBox;
	QLabel*  m_SCCoefficientLabel;
	QLineEdit* m_SCCoefficientEdit;
	QGroupBox* m_CorrectionDirectGroupBox;
	QRadioButton* m_RGBDirect;
	QRadioButton* m_BGRDirect;
	QSpacerItem *m_verticalSpacer;

	QHBoxLayout* m_SCCoefficientLayOut;
	QHBoxLayout* m_GroupBoxLayOut;
	QVBoxLayout* m_VerticalLayOut;

	std::shared_ptr<gcp2::Camera> m_pCamera;

};

#endif
