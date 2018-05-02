#pragma once
#ifndef ISPCC_H
#define ISPCC_H
#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QApplication>
#include <memory>
#include "ISPRegisterDef.h"
namespace gcp2 {
	class Camera;
}
class ISPCC: public QWidget
{
	Q_OBJECT
public:
	ISPCC(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ISPCC();
private slots:
	void on_CCMEnableCheckBox_clicked(bool);
	void on_matrixComfirmPushButton_clicked(bool);
	void CTchose(int index);
private:
	QCheckBox* m_CCMEnableCheckBox;
	QLabel* m_CTChoseLabel;
	QComboBox* m_CTChoseComboBox;
	QLabel* m_CMatrixLabel;
	QLineEdit* m_A11LineEdit;
	QLineEdit* m_A12LineEdit;
	QLineEdit* m_A13LineEdit;
	QLineEdit* m_A21LineEdit;
	QLineEdit* m_A22LineEdit;
	QLineEdit* m_A23LineEdit;
	QLineEdit* m_A31LineEdit;
	QLineEdit* m_A32LineEdit;
	QLineEdit* m_A33LineEdit;
	QPushButton* m_matrixComfirmPushButton;
	QPushButton* m_resetPushButton;
	QSpacerItem *m_verticalSpacer;
	QHBoxLayout* m_hlayout_1;
	QHBoxLayout* m_hlayout_2;
	QVBoxLayout* m_vlayout;
	QGridLayout* m_gridlayout;
	std::shared_ptr<gcp2::Camera> m_pCamera;

};
#endif
