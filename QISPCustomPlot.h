#pragma once

#include "qcustomplot.h"

class QISPCustomPlot : public QCustomPlot
{
	Q_OBJECT
public:
	QISPCustomPlot(QWidget *parent);
	~QISPCustomPlot();
private slots:
	void mouseWheel();
	void mousePress();
};
