#pragma once
#ifndef ISPFFC2_H
#define ISPFFC2_H
#include <QWidget>
#include <QCheckBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <memory>
#include "ISPRegisterDef.h"
namespace gcp2 {
	class Camera;
}
class ISPFFC2 :public QWidget
{
	Q_OBJECT
public:
	ISPFFC2(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ISPFFC2();
private slots:
	void on_FFC2EnableCheckBox_clicked(bool);
	void on_MannerModeRadioButton_clicked(bool);
	void on_OneKeyModeRadioButton_clicked(bool);
	void on_SampleLineLineEdit_returnPressed();
	void on_StartXPosLineEdit_returnPressed();
	void on_StartYPosLineEdit_returnPressed();
	void on_FT2EnableCheckBox_clicked(bool);
	void on_VWindowLineEdit_returnPressed();
	void on_FPN2EnablePushButton_clicked();
	void on_PRNU2EnablePushButton_clicked();
	void on_FFC2ParaReturnPushButton_clicked();
private:
	QCheckBox* m_FFC2EnableCheckBox;
	QGroupBox* m_correctionMode;
	QRadioButton* m_mannerModeRadioButton;
	QRadioButton* m_oneKeyModeRadioButton;
	QLabel* m_sampleLineLabel;
	QLineEdit* m_sampleLineLineEdit;
	QLabel* m_startXPosLabel;
	QLineEdit* m_startXPosLineEdit;
	QLabel* m_startYPosLabel;
	QLineEdit* m_startYPosLineEdit;
	QCheckBox* m_FT2EnableCheckBox;
	QLabel* m_VWindowLabel;
	QLineEdit* m_VWindowLineEdit;
	QPushButton* m_FPN2EnablePushButton;
	QPushButton* m_PRNU2EnablePushButton;
	QPushButton* m_FFC2ParaReturnPushButton;
	std::shared_ptr<gcp2::Camera> m_pCamera;
	QSpacerItem *m_verticalSpacer;

	QHBoxLayout* m_hlayout_1;
	QHBoxLayout* m_hlayout_2;
	QHBoxLayout* m_hlayout_3;
	QHBoxLayout* m_hlayout_4;
	QHBoxLayout* m_hlayout_5;
	QVBoxLayout* m_vlayout;

};
#endif
