#pragma once
#ifndef ISPWB_H
#define ISPWB_H
#include <QWidget>
#include <QCheckBox>
#include <QGroupBox>
#include <QRadioButton>
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
class ISPWB:public QWidget
{
	Q_OBJECT
public:
	ISPWB(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
//	ISPWB(QWidget * parent, Qt::WindowFlags f);
	~ISPWB();
private slots:
	void on_AWBEnableCheckBox_clicked(bool);
	void on_AWBStaticModeRadioButton_clicked(bool);
	void on_AWBSmartModeRadioButton_clicked(bool);
	void on_SampleLineNumLineEdit_returnPressed();
	void on_startXPosLineEdit_returnPressed();
	void on_startYPosLineEdit_returnPressed();
	void on_rGainLineEdit_returnPressed();
	void on_gGainLineEdit_returnPressed();
	void on_bGainLineEdit_returnPressed();
	void on_gainCalOnceEnablePushButton_clicked();
	void on_rReadPushButton_clicked();
	void on_gReadPushButton_clicked();
	void on_bReadPushButton_clicked();
private:
	QCheckBox* m_WBEnableCheckBox;
	QGroupBox* m_correctionMode;
	QRadioButton* m_staticModeRadioButton;
	QRadioButton* m_smartModeRadioButton;
	QLabel* m_SampleLineLabel;
	QLineEdit* m_SampleLineLineEdit;
	QLabel* m_startXPosLabel;
	QLineEdit* m_startXPosLineEdit;
	QLabel* m_startYPosLabel;
	QLineEdit* m_startYPosLineEdit;

	QLabel* m_rGainLabel;
	QLineEdit* m_rGainLineEdit;
	QLabel* m_rReadGainLabel;
	QPushButton* m_rReadPushButton;

	QLabel* m_gGainLabel;
	QLineEdit* m_gGainLineEdit;
	QLabel* m_gReadGainLabel;
	QPushButton* m_gReadPushButton;

	QLabel* m_bGainLabel;
	QLineEdit* m_bGainLineEdit;
	QLabel* m_bReadGainLabel;
	QPushButton* m_bReadPushButton;

	QPushButton* m_sampleEnablePushButton;
	QSpacerItem *m_verticalSpacer;

	QHBoxLayout* m_hlayout_1;
	QHBoxLayout* m_hlayout_2;
	QHBoxLayout* m_hlayout_3;
	QHBoxLayout* m_hlayout_4;
	QHBoxLayout* m_hlayout_5;
	QHBoxLayout* m_hlayout_6;
	QHBoxLayout* m_hlayout_7;
	QVBoxLayout* m_vlayout;
	std::shared_ptr<gcp2::Camera> m_pCamera;
	bool m_bStaticMode, m_bSmartMode;
};
#endif

