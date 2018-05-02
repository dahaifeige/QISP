#pragma once
#ifndef ISPFFC1_H
#define ISPFFC1_H
#include <QWidget>
#include <QCheckBox>
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
class ISPFFC1 :public QWidget 
{
	Q_OBJECT
public:
	ISPFFC1(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ISPFFC1();
private slots:
	void on_FFC1EnableCheckBox_clicked(bool);
	void on_FFC1_SampleLineLineEdit_returnPressed();
	void on_FPN1EnablePushButton_clicked();
	void on_PRNU1EnablePushButton_clicked();
	void on_FFC1ParaReturnPushButton_clicked();
private:
	QCheckBox* m_FFC1EnableCheckBox;
	QLabel* m_FFC1_SampleLineLabel;
	QLineEdit* m_FFC1_SampleLineLineEdit;
	QPushButton* m_FPN1EnablePushButton;
	QPushButton* m_PRNU1EnablePushButton;
	QPushButton* m_FFC1ParaReturnPushButton;
	QSpacerItem *m_verticalSpacer;

	QHBoxLayout* m_hlayout;
	QVBoxLayout* m_vlayout;

	std::shared_ptr<gcp2::Camera> m_pCamera;

};
#endif