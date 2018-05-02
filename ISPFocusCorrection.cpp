#include "Camera.h"
#include "CameraItem.h"
#include "CameraWidget.h"
#include "QISPCustomPlot.h"
#include "qtest.h"
#include "ISPFocusCorrection.h"
#include "iport.h"
#include "ISPDockWidget.h"
ISPFocusCorrection::ISPFocusCorrection(QWidget * parent, Qt::WindowFlags f):
m_firstFocusWnPosLabel(new QLabel(this)),
m_firstFocusWnPosLineEdit(new QLineEdit(this)),
m_FocusWnWidthLabel(new QLabel(this)),
m_FocusWnWidthLineEdit(new QLineEdit(this)),
m_displayFrameCountLabel(new QLabel(this)),
m_displayFrameCountLineEdit(new QLineEdit(this)),
m_displayPlotCheckBox(new QCheckBox(this)),
m_displayPlotPushButton(new QPushButton(this)),
m_customPlot(new QISPCustomPlot(this)),
m_verticalSpacer(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding)),
m_hlayout_1(new QHBoxLayout),
m_hlayout_2(new QHBoxLayout),
m_hlayout_3(new QHBoxLayout),
m_hlayout_4(new QHBoxLayout),
m_vlayout(new QVBoxLayout(this)),
m_pCamera(nullptr),
m_tAutoPlot(new QTimer),
m_pCamItem(nullptr),
m_nDisplayFrameCount(0), m_nCount(0),
m_pTableWidget(new QTableWidget),
m_bExit(true)
//m_pXItem(new QTableWidgetItem), m_pY1Item(new QTableWidgetItem), m_pY2Item(new QTableWidgetItem)
{
	m_firstFocusWnPosLabel->setText(QApplication::translate("MainWindow", "\345\267\246-\345\257\271\347\204\246\347\252\227\345\217\243\350\265\267\347\202\271 (iv_position)", Q_NULLPTR));
	m_FocusWnWidthLabel->setText(QApplication::translate("MainWindow", "\345\257\271\347\204\246\347\252\227\345\217\243\345\256\275\345\272\246(iv_width)\357\274\232", Q_NULLPTR));
	m_displayFrameCountLabel->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\270\247\346\225\260\357\274\232", Q_NULLPTR));
	m_displayPlotCheckBox->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\257\271\347\204\246\346\233\262\347\272\277", Q_NULLPTR));
	m_displayPlotPushButton->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272", Q_NULLPTR));

	m_hlayout_1->addWidget(m_firstFocusWnPosLabel);
	m_hlayout_1->addWidget(m_firstFocusWnPosLineEdit);

	m_hlayout_2->addWidget(m_FocusWnWidthLabel);
	m_hlayout_2->addWidget(m_FocusWnWidthLineEdit);

	m_hlayout_3->addWidget(m_displayFrameCountLabel);
	m_hlayout_3->addWidget(m_displayFrameCountLineEdit);

	m_hlayout_4->addWidget(m_displayPlotCheckBox);
	m_hlayout_4->addWidget(m_displayPlotPushButton);

	m_vlayout->addLayout(m_hlayout_1);
	m_vlayout->addLayout(m_hlayout_2);
	m_vlayout->addLayout(m_hlayout_3);
	m_vlayout->addLayout(m_hlayout_4);

	m_vlayout->addItem(m_verticalSpacer);
	m_vlayout->addWidget(m_pTableWidget);
	m_vlayout->addWidget(m_customPlot);

	if (m_pTableWidget->columnCount() < 3)
		m_pTableWidget->setColumnCount(3);

	QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
	m_pTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
	__qtablewidgetitem->setText(QApplication::translate("MainWindow", "FrameCount", Q_NULLPTR));
	QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
	m_pTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
	__qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Value1", Q_NULLPTR));
	QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
	m_pTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
	__qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Value2", Q_NULLPTR));

	//m_pTableWidget->setCellWidget(0, 2, m_customPlot);
	
	if (m_pTableWidget->rowCount() < 80)
		m_pTableWidget->setRowCount(80);
	m_pTableWidget->setObjectName(QStringLiteral("tableWidget_2"));
	m_pTableWidget->setAutoScroll(true);
	m_pTableWidget->setRowCount(80);

	m_pTableWidget->horizontalHeader()->setVisible(true);
	m_pTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
	m_pTableWidget->horizontalHeader()->setHighlightSections(false);
	m_pTableWidget->horizontalHeader()->setStretchLastSection(false);

	m_pTableWidget->verticalHeader()->setVisible(false);
	m_pTableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
	m_pTableWidget->verticalHeader()->setStretchLastSection(false);

	//m_pXItem->setBackgroundColor(QColor(255, 255, 255));
	//m_pXItem->setTextColor(QColor(200, 111, 100));
	//m_pXItem->setFont(QFont("Helvetica"));

	//m_pY1Item->setBackgroundColor(QColor(255, 255, 255));
	//m_pY1Item->setTextColor(QColor(0, 0, 0));
	//m_pY1Item->setFont(QFont("Helvetica"));

	//m_pY2Item->setBackgroundColor(QColor(255, 255, 255));
	//m_pY2Item->setTextColor(QColor(255, 0, 0));
	//m_pY2Item->setFont(QFont("Helvetica"));

	connect(m_firstFocusWnPosLineEdit, SIGNAL(returnPressed()), this, SLOT(on_firstFocusWnPosLineEdit_returnPressed()));
	connect(m_FocusWnWidthLineEdit, SIGNAL(returnPressed()), this, SLOT(on_FocusWnWidthLineEdit_returnPressed()));
	connect(m_displayFrameCountLineEdit, SIGNAL(returnPressed()), this, SLOT(on_displayFrameCountLineEdit_returnPressed()));
	connect(m_displayFrameCountLineEdit, SIGNAL(editingFinished()), this, SLOT(on_displayFrameCountLineEdit_returnPressed()));
	connect(m_displayPlotCheckBox, SIGNAL(clicked(bool)), this, SLOT(on_displayPlotCheckBox_clicked(bool)));
	connect(m_displayPlotPushButton, SIGNAL(clicked()), this, SLOT(on_displayPlotPushButton_clicked()));

	
	connect(m_tAutoPlot, SIGNAL(timeout()), this, SLOT(autoPlot()));//自动刷新相机

}

ISPFocusCorrection::~ISPFocusCorrection()
{
}
void ISPFocusCorrection::on_firstFocusWnPosLineEdit_returnPressed()
{
	quint32 srtInt16 = m_firstFocusWnPosLineEdit->text().toInt(nullptr, 10);

	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8 *)&srtInt16, FIRST_FOCUS_WN_POS_L, sizeof(quint32));
}
void ISPFocusCorrection::on_FocusWnWidthLineEdit_returnPressed()
{
	quint32 srtInt16 = m_FocusWnWidthLineEdit->text().toInt(nullptr, 10);

	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera)
		return;
	if (!(m_pCamera->GetCameraIPort()))
		return;
	m_pCamera->GetCameraIPort()->write((quint8 *)&srtInt16, FOCUS_WN_WIDTH_L, sizeof(quint32));
}
void ISPFocusCorrection::on_displayFrameCountLineEdit_returnPressed()
{
	m_nDisplayFrameCount = m_displayFrameCountLineEdit->text().toInt();
	m_pCamItem = ISPDockWidget::GetCameraItem();
	if (!m_pCamItem)
		return;
	m_customPlot->xAxis->setRange(0, m_nDisplayFrameCount);
	if (!m_pCamItem->GetCameraWidget()->GetXValue1())
		return;
}
void ISPFocusCorrection::on_displayPlotCheckBox_clicked(bool isClicked)
{
	if (isClicked)
		m_tAutoPlot->start(0);
	else
		m_tAutoPlot->stop();
}
void ISPFocusCorrection::on_displayPlotPushButton_clicked()
{
	if (!m_tAutoPlot->isActive())
		m_tAutoPlot->start(0);
}
void ISPFocusCorrection::autoPlot()
{
	m_pCamItem = ISPDockWidget::GetCameraItem();
	if (!m_pCamItem)
		return;
	m_pCamera = ISPDockWidget::GetCamera();
	if (!m_pCamera || !m_pCamera->IsConnected() || !m_pCamera->IsStreaming() || !m_pCamItem->GetCameraWidget()->GetXValue1())
		return;

	QVector<double> xFrameCount, yValue1, yValue2;
	int sum = m_pCamItem->GetCameraWidget()->GetXValue2()->size();
	if (sum >= m_nCount + m_nDisplayFrameCount)
	{
		if (m_bExit)
		{
			m_customPlot->yAxis->setRange(80 * m_pCamItem->GetCameraWidget()->GetYValue1()->at(0) / 100, 120 * m_pCamItem->GetCameraWidget()->GetYValue1()->at(0) / 100);
			m_bExit = false;
		}
		m_pTableWidget->setRowCount(m_nDisplayFrameCount);
		int i, j, k;
		 i =  j = k = 0;
		for (int frameCount = m_nCount; frameCount < sum; frameCount++)
		{
			/*QString value = QString::number(m_pCamItem->GetCameraWidget()->GetXValue1()->at(frameCount));
			m_pXItem->setText(value);
			m_pTableWidget->setItem(i, 0, m_pXItem);
			xFrameCount.append(m_pCamItem->GetCameraWidget()->GetYValue1()->at(frameCount));
			i++;*/
		//	QTableWidgetItem *xItem = new QTableWidgetItem(value);
			//xItem->setBackgroundColor(QColor(255, 255, 255));
			//xItem->setTextColor(QColor(200, 111, 100));
		//	xItem->setFont(QFont("Helvetica"));

			QString value = QString::number(m_pCamItem->GetCameraWidget()->GetXValue1()->at(frameCount));
			QTableWidgetItem *xItem = new QTableWidgetItem(value);
			xItem->setBackgroundColor(QColor(255, 255, 255));
			xItem->setTextColor(QColor(0, 0, 0));
			xItem->setFont(QFont("Helvetica"));
			m_pTableWidget->setItem(i, 0, xItem);
			xFrameCount.append(m_pCamItem->GetCameraWidget()->GetXValue1()->at(frameCount));
			i++;
			
		}
		for (int frameCount = m_nCount; frameCount < sum; frameCount++)
		{
			/*QString value = QString::number(m_pCamItem->GetCameraWidget()->GetYValue1()->at(frameCount));
			m_pY1Item->setText(value);
			m_pTableWidget->setItem(j, 1, m_pY1Item);
			yValue1.append(m_pCamItem->GetCameraWidget()->GetYValue1()->at(frameCount));
			j++;*/

			QString value = QString::number(m_pCamItem->GetCameraWidget()->GetYValue1()->at(frameCount));
			QTableWidgetItem *y1Item = new QTableWidgetItem(value);
			y1Item->setBackgroundColor(QColor(255, 255, 255));
			y1Item->setTextColor(QColor(0, 0, 0));
			y1Item->setFont(QFont("Helvetica"));
			m_pTableWidget->setItem(j, 1, y1Item);
			yValue1.append(m_pCamItem->GetCameraWidget()->GetYValue1()->at(frameCount));
			j++;
		}
		for (int frameCount = m_nCount; frameCount < sum; frameCount++)
		{
			////QTableWidgetItem y2Item;
			//QString value = QString::number(m_pCamItem->GetCameraWidget()->GetYValue2()->at(frameCount));
			//m_pY2Item->setText(value);
			//m_pTableWidget->setItem(k, 2, m_pY2Item);
			//yValue2.append(m_pCamItem->GetCameraWidget()->GetYValue2()->at(frameCount));
			//k++;

			QString value = QString::number(m_pCamItem->GetCameraWidget()->GetYValue2()->at(frameCount));
			QTableWidgetItem *y2Item = new QTableWidgetItem(value);
			y2Item->setBackgroundColor(QColor(255, 255, 255));
			y2Item->setTextColor(QColor(255, 0, 0));
			y2Item->setFont(QFont("Helvetica"));
			m_pTableWidget->setItem(k, 2, y2Item);
			yValue2.append(m_pCamItem->GetCameraWidget()->GetYValue2()->at(frameCount));
			k++;
		}
		m_customPlot->graph(0)->addData(xFrameCount, yValue1);
		m_customPlot->graph(1)->addData(xFrameCount, yValue2);
		double position = m_pCamItem->GetCameraWidget()->GetXValue1()->at(0);
		m_customPlot->xAxis->setRange(xFrameCount.at(0), m_nDisplayFrameCount - 1, Qt::AlignLeft);
		m_nCount++;
		m_customPlot->replot();
	}
}