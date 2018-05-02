#include "QISPCustomPlot.h"

QISPCustomPlot::QISPCustomPlot(QWidget *parent)
{
	this->setFixedHeight(500);

	this->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
		QCP::iSelectLegend | QCP::iSelectPlottables);
	this->legend->setVisible(true);
	this->legend->setFont(QFont("Helvetica", 9));
	this->addGraph();
	this->addGraph();

	this->graph(0)->setPen(QPen(QColor(0, 0, 0)));
	this->graph(1)->setPen(QPen(QColor(255, 0, 0)));
	this->graph(0)->setName("value1");
	this->graph(1)->setName("value2");
	this->graph(0)->rescaleAxes();
	this->graph(1)->rescaleAxes(true);

	this->xAxis->setLabel("FrameCount");
	this->yAxis->setLabel("Value");
	this->setBackground(QColor(100, 100, 100));
	this->axisRect()->setupFullAxesBox();
	// set title of plot:
	this->plotLayout()->insertRow(0);
	this->plotLayout()->addElement(0, 0, new QCPTextElement(this, "Curve", QFont("sans", 12, QFont::Bold)));
	// 设置x/y轴文本色、轴线色、字体等
	this->xAxis->setTickLabelColor(Qt::white);
	this->xAxis->setLabelColor(QColor(0, 160, 230));
	this->xAxis->setBasePen(QPen(QColor(32, 178, 170)));
	this->xAxis->setTickPen(QPen(QColor(128, 0, 255)));
	this->xAxis->setSubTickPen(QColor(255, 165, 0));
	QFont xFont = this->xAxis->labelFont();
	xFont.setPixelSize(20);
	this->xAxis->setLabelFont(xFont);

	this->yAxis->setTickLabelColor(Qt::white);
	this->yAxis->setLabelColor(QColor(0, 160, 230));
	this->yAxis->setBasePen(QPen(QColor(32, 178, 170)));
	this->yAxis->setTickPen(QPen(QColor(128, 0, 255)));
	this->yAxis->setSubTickPen(QColor(255, 165, 0));
	QFont yFont = this->yAxis->labelFont();
	yFont.setPixelSize(20);
	this->yAxis->setLabelFont(yFont);
	connect(this, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
	connect(this, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));
}

QISPCustomPlot::~QISPCustomPlot()
{
}

void QISPCustomPlot::mouseWheel()
{
	// if an axis is selected, only allow the direction of that axis to be zoomed
	// if no axis is selected, both directions may be zoomed

	if (this->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
		this->axisRect()->setRangeZoom(this->xAxis->orientation());
	else if (this->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
		this->axisRect()->setRangeZoom(this->yAxis->orientation());
	else
		this->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
}
void QISPCustomPlot::mousePress()
{
	// if an axis is selected, only allow the direction of that axis to be dragged
	// if no axis is selected, both directions may be dragged

	if (this->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
		this->axisRect()->setRangeDrag(this->xAxis->orientation());
	else if (this->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
		this->axisRect()->setRangeDrag(this->yAxis->orientation());
	else
		this->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
}