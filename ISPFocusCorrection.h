#pragma once
#ifndef ISPFOCUSCORRECTION_H
#define ISPFOCUSCORRECTION_H
#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QTableWidget>
#include <memory>
#include "ISPRegisterDef.h"
namespace gcp2 {
	class Camera;
}
class CameraItem;
class QISPCustomPlot;
class ISPFocusCorrection :public QWidget
{
	Q_OBJECT
public:
	ISPFocusCorrection(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ISPFocusCorrection();
private slots:
	void on_firstFocusWnPosLineEdit_returnPressed();
	void on_FocusWnWidthLineEdit_returnPressed();
	void on_displayFrameCountLineEdit_returnPressed();
	void on_displayPlotPushButton_clicked();
	void on_displayPlotCheckBox_clicked(bool);
	void autoPlot();
private:
	QLabel*  m_firstFocusWnPosLabel;
	QLineEdit* m_firstFocusWnPosLineEdit;
	QLabel* m_FocusWnWidthLabel;
	QLineEdit* m_FocusWnWidthLineEdit;
	QLabel* m_displayFrameCountLabel;
	QLineEdit* m_displayFrameCountLineEdit;
	QCheckBox* m_displayPlotCheckBox;
	QPushButton* m_displayPlotPushButton;
	QISPCustomPlot* m_customPlot;
	QSpacerItem *m_verticalSpacer;
	QHBoxLayout* m_hlayout_1;
	QHBoxLayout* m_hlayout_2;
	QHBoxLayout* m_hlayout_3;
	QHBoxLayout* m_hlayout_4;
	QVBoxLayout* m_vlayout;
	
	std::shared_ptr<gcp2::Camera> m_pCamera;
	QTimer* m_tAutoPlot;
	CameraItem* m_pCamItem;
	int m_nDisplayFrameCount, m_nCount;
	QTableWidget* m_pTableWidget;
	bool m_bExit;
	//QTableWidgetItem *m_pXItem, *m_pY1Item, *m_pY2Item;
};

#endif