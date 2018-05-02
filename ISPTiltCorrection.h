#pragma once
#ifndef ISPTILTCORRECTION_H
#define ISPTILTCORRECTION_H
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <memory>
#include "ISPRegisterDef.h"
namespace gcp2 {
	class Camera;
}
class ISPTiltCorrection:public QWidget
{
	Q_OBJECT
public:
	ISPTiltCorrection(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ISPTiltCorrection();
private slots:
	void on_tiltLeftParaLineEdit_returnPressed();
	void on_tiltRightParaLineEdit_returnPressed();
	void on_frontDirectionRadioButton_clicked(bool);
	void on_backDirectionRadioButton_clicked(bool);
	void on_tiltEnableCheckBox_clicked(bool);
	void on_tiltEnablePushButton_clicked();
private:
	QLabel* m_tiltLeftParaLabel;
	QLabel* m_tiltRightParaLabel;
	QLineEdit* m_tiltLeftParaLineEdit;
	QLineEdit* m_tiltRightParaLineEdit;
	QGroupBox* m_CorrectionDirectGroupBox;
	QRadioButton* m_frontDirectionRadioButton;
	QRadioButton* m_backDirectionRadioButton;
	QCheckBox* m_tiltEnableCheckBox;
	QPushButton* m_tiltEnablePushButton;
	QSpacerItem *m_verticalSpacer;

	QHBoxLayout* m_hlayout_1;
	QHBoxLayout* m_hlayout_2;
	QHBoxLayout* m_hGroupBoxlayout;
	QHBoxLayout* m_hlayout_3;
	QVBoxLayout* m_vlayout;

	std::shared_ptr<gcp2::Camera> m_pCamera;

};
#endif