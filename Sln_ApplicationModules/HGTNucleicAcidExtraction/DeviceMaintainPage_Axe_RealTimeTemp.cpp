#include "DeviceMaintainPage_Axe_RealTimeTemp.h"

DeviceMaintainPage_Axe_RealTimeTemp::DeviceMaintainPage_Axe_RealTimeTemp(QWidget * _parent, DeviceControlService _handle) : DeviceMaintainPage_Axe_Base(_parent, _handle)
{
	m_hShow = getNewHBoxLayout(widgetBaseContent);
	m_hShow->setContentsMargins(20, 22, 20, 30);

	initPlot(0, 600, 0, 100);
	initRealtimeShow();

	m_hShow->addWidget(m_imageScrollArea, 0, Qt::AlignLeft);
	m_hShow->addWidget(m_frmSetting, 0, Qt::AlignLeft);

	m_axe = _handle.axeService;
	if (m_axe != nullptr)
	{
		connect(m_axe, SIGNAL(signal_sendCurTempToUI(int, HeatBoardData)), this, SLOT(slot_recvCurTempData(int, HeatBoardData)));
	}

	m_sec = 0;
	m_graphChannel1 = nullptr;
	m_graphChannel2 = nullptr;
	m_graphChannel3 = nullptr;
	m_graphChannel4 = nullptr;
}


void DeviceMaintainPage_Axe_RealTimeTemp::initPlot(double x_start, double x_end, double y_start, double y_end)
{
	customplot = new QCustomPlot();
	customplot->setFixedSize(QSize(900, 660));

	customplot->legend->setBorderPen(Qt::NoPen);

	m_imageScrollArea = getNewScrollArea();
	m_imageScrollArea->setFixedSize(QSize(920, 700));
	m_imageScrollArea->setAlignment(Qt::AlignCenter);
	m_imageScrollArea->setFrameShape(QFrame::NoFrame);
	m_imageScrollArea->setWidget(customplot);
	m_imageScrollArea->setBackgroundRole(QPalette::Shadow);
	customplot->xAxis->setRange(x_start, x_end);
	customplot->yAxis->setRange(y_start, y_end);

	customplot->setBackground(QColor(0x1b, 0x0d, 0x57));
	customplot->addGraph(customplot->yAxis, customplot->xAxis);
	customplot->axisRect()->setupFullAxesBox(true);

	customplot->xAxis->setTickLabelColor(Qt::white);
	customplot->xAxis->setLabelColor(Qt::white);
	customplot->xAxis->setBasePen(QPen(QColor(32, 178, 170)));
	customplot->xAxis->setTickPen(QPen(QColor(128, 0, 255)));
	customplot->xAxis->setSubTickPen(QColor(255, 165, 0));
	QFont xFont = customplot->xAxis->labelFont();
	xFont.setPixelSize(20);
	customplot->xAxis->setLabelFont(xFont);

	customplot->yAxis->setTickLabelColor(Qt::white);
	customplot->yAxis->setLabelColor(QColor(0, 160, 230));
	//customplot->yAxis->setBasePen(QPen(QColor(32, 178, 170)));
	//customplot->yAxis->setTickPen(QPen(QColor(128, 0, 255)));
	//customplot->yAxis->setSubTickPen(QColor(255, 165, 0));
	QFont yFont = customplot->yAxis->labelFont();
	yFont.setPixelSize(20);
	customplot->yAxis->setLabelFont(yFont);

	//customplot->xAxis->setRangeReversed(true);
	//customplot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
	//customplot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

	customplot->xAxis->grid()->setZeroLinePen(QPen(QColor(32, 178, 170)));
	customplot->yAxis->grid()->setZeroLinePen(QPen(QColor(32, 178, 170)));
	//customplot->xAxis->setBasePen(QPen(Qt::gray,1));
	customplot->yAxis->setBasePen(QPen(Qt::gray, 1));
	customplot->xAxis2->setBasePen(QPen(Qt::gray, 1));
	customplot->yAxis2->setBasePen(QPen(Qt::gray, 1));

	customplot->xAxis->setVisible(true);
	customplot->yAxis->setVisible(true);
	customplot->axisRect()->setVisible(true);
}

void DeviceMaintainPage_Axe_RealTimeTemp::initRealtimeShow()
{
	m_ckAutoGetTemp = getNewCheckBox("1708420231");
	connect(m_ckAutoGetTemp, SIGNAL(stateChanged(int)), this, SLOT(slot_onStateChanged(int)));

	m_frmSetting = getNewFrame();
	m_frmSetting->setFixedSize(300, 700);

	m_vShow = getNewVBoxLayout(m_frmSetting);
	m_vShow->setAlignment(Qt::AlignCenter);

	m_gbZoom = getNewGroupBox("1708420232");
	m_gbZoom->setFixedSize(260, 180);
	QVBoxLayout *vZoom = getNewVBoxLayout(m_gbZoom);
	vZoom->setAlignment(Qt::AlignCenter);

	m_lbXStart = getNewLbCommon();
	m_lbXStart->setText("X1");
	m_lbXStart->setFixedWidth(45);
	m_lbXStart->setAlignment(Qt::AlignCenter);

	m_edtXStart = getNewLineEdit();
	m_edtXStart->setFixedWidth(70);

	m_lbXEnd = getNewLbCommon();
	m_lbXEnd->setText("X2");
	m_lbXEnd->setFixedWidth(45);
	m_lbXEnd->setAlignment(Qt::AlignCenter);

	m_edtXEnd = getNewLineEdit();
	m_edtXEnd->setFixedWidth(70);

	QWidget *widTemp1 = getNewWidgetCommon();
	QHBoxLayout *m_hbTemp1 = getNewHBoxLayout(widTemp1);
	m_hbTemp1->addWidget(m_lbXStart);
	m_hbTemp1->addWidget(m_edtXStart);
	m_hbTemp1->addWidget(m_lbXEnd);
	m_hbTemp1->addWidget(m_edtXEnd);

	m_lbYStart = getNewLbCommon();
	m_lbYStart->setText("Y1");
	m_lbYStart->setFixedWidth(45);
	m_lbYStart->setAlignment(Qt::AlignCenter);

	m_edtYStart = getNewLineEdit();
	m_edtYStart->setFixedWidth(70);

	m_lbYEnd = getNewLbCommon();
	m_lbYEnd->setText("Y2");
	m_lbYEnd->setFixedWidth(45);
	m_lbYEnd->setAlignment(Qt::AlignCenter);

	m_edtYEnd = getNewLineEdit();
	m_edtYEnd->setFixedWidth(70);

	QWidget *widTemp2 = getNewWidgetCommon();
	QHBoxLayout *m_hbTemp2 = getNewHBoxLayout(widTemp2);
	m_hbTemp2->addWidget(m_lbYStart);
	m_hbTemp2->addWidget(m_edtYStart);
	m_hbTemp2->addWidget(m_lbYEnd);
	m_hbTemp2->addWidget(m_edtYEnd);

	m_btnConfirm = getNewBtCommon("1708419640");
	connect(m_btnConfirm, SIGNAL(clicked()), this, SLOT(slot_modifyPlot()));

	vZoom->addWidget(widTemp1);
	vZoom->addWidget(widTemp2);
	vZoom->addWidget(m_btnConfirm, 0, Qt::AlignCenter);

	m_gbTShow = getNewGroupBox("1708420288");
	m_gbTShow->setFixedSize(260, 180);
	QVBoxLayout *vTShow = getNewVBoxLayout(m_gbTShow);
	vTShow->setAlignment(Qt::AlignCenter);
	vTShow->setContentsMargins(0, 20, 0, 0);

	m_lbT1 = getNewLbCommon();
	m_lbT1->setText("T1");
	m_lbT1->setFixedWidth(45);
	m_lbT1->setAlignment(Qt::AlignCenter);

	m_edtT1 = getNewLineEdit();
	m_edtT1->setFixedWidth(70);

	m_lbT2 = getNewLbCommon();
	m_lbT2->setText("T2");
	m_lbT2->setFixedWidth(45);
	m_lbT2->setAlignment(Qt::AlignCenter);

	m_edtT2 = getNewLineEdit();
	m_edtT2->setFixedWidth(70);

	QWidget *widTemp3 = getNewWidgetCommon();
	QHBoxLayout *m_hbTemp3 = getNewHBoxLayout(widTemp3);
	m_hbTemp3->addWidget(m_lbT1);
	m_hbTemp3->addWidget(m_edtT1);
	m_hbTemp3->addWidget(m_lbT2);
	m_hbTemp3->addWidget(m_edtT2);

	m_lbT3 = getNewLbCommon();
	m_lbT3->setText("T3");
	m_lbT3->setFixedWidth(45);
	m_lbT3->setAlignment(Qt::AlignCenter);

	m_edtT3 = getNewLineEdit();
	m_edtT3->setFixedWidth(70);

	m_lbT4 = getNewLbCommon();
	m_lbT4->setText("T4");
	m_lbT4->setFixedWidth(45);
	m_lbT4->setAlignment(Qt::AlignCenter);

	m_edtT4 = getNewLineEdit();
	m_edtT4->setFixedWidth(70);

	QWidget *widTemp4 = getNewWidgetCommon();
	QHBoxLayout *m_hbTemp4 = getNewHBoxLayout(widTemp4);
	m_hbTemp4->addWidget(m_lbT3);
	m_hbTemp4->addWidget(m_edtT3);
	m_hbTemp4->addWidget(m_lbT4);
	m_hbTemp4->addWidget(m_edtT4);

	m_btnClear = getNewBtCommon("1708420251");
	connect(m_btnClear, SIGNAL(clicked()), this, SLOT(slot_clearTShow()));

	vTShow->addWidget(widTemp3);
	vTShow->addWidget(widTemp4);
	vTShow->addWidget(m_btnClear, 0, Qt::AlignCenter);

	m_vShow->setSpacing(20);
	m_vShow->addWidget(m_ckAutoGetTemp, 0, Qt::AlignCenter);
	m_vShow->addWidget(m_gbZoom);
	m_vShow->addWidget(m_gbTShow);
}

void DeviceMaintainPage_Axe_RealTimeTemp::slot_onStateChanged(int state)
{
	if (state == Qt::Checked)
	{
		clearVec();
		m_sec = 0;
		customplot->clearGraphs();
		customplot->replot();
		m_graphChannel1 = nullptr;
		m_graphChannel2 = nullptr;
		m_graphChannel3 = nullptr;
		m_graphChannel4 = nullptr;
		m_axe->setAutoGetCurTemp(true);
	}
	else
	{
		clearVec();
		m_axe->setAutoGetCurTemp(false);
	}
}

void DeviceMaintainPage_Axe_RealTimeTemp::clearVec()
{
	QVector<double> x1;
	QVector<double> x2;
	QVector<double> x3;
	QVector<double> x4;

	QVector<double> y1;
	QVector<double> y2;
	QVector<double> y3;
	QVector<double> y4;

	m_x1.swap(x1);
	m_x2.swap(x2);
	m_x3.swap(x3);
	m_x4.swap(x4);

	m_y1.swap(y1);
	m_y2.swap(y2);
	m_y3.swap(y3);
	m_y4.swap(y4);

	m_x1.clear();
	m_x2.clear();
	m_x3.clear();
	m_x4.clear();

	m_y1.clear();
	m_y2.clear();
	m_y3.clear();
	m_y4.clear();
}

void DeviceMaintainPage_Axe_RealTimeTemp::slot_recvCurTempData(int axeNumber, HeatBoardData heatBoardData)
{
	mutex.lock();
	double y1 = heatBoardData.degree[0];
	double x1 = m_sec;

	if (y1 - InitDegree < 0.00001f)
	{
		double x1 = m_sec;
	}

	double y2 = heatBoardData.degree[1];
	double x2 = m_sec;

	double y3 = heatBoardData.degree[2];
	double x3 = m_sec;

	double y4 = heatBoardData.degree[3];
	double x4 = m_sec;

	m_edtT1->clear();
	m_edtT2->clear();
	m_edtT3->clear();
	m_edtT4->clear();

	m_edtT1->setText(QString::number(y1, 'f', 1));
	m_edtT2->setText(QString::number(y2, 'f', 1));
	m_edtT3->setText(QString::number(y3, 'f', 1));
	m_edtT4->setText(QString::number(y4, 'f', 1));

	m_x1.append(x1);
	m_y1.append(y1);

	m_x2.append(x2);
	m_y2.append(y2);

	m_x3.append(x3);
	m_y3.append(y3);

	m_x4.append(x4);
	m_y4.append(y4);

	QPen drawPen;
	if (m_graphChannel1 == nullptr)
	{
		drawPen.setColor(QColor(0xea, 0x4d, 0x76));
		drawPen.setWidth(1);
		m_graphChannel1 = customplot->addGraph();
		m_graphChannel1->setPen(drawPen);
		m_graphChannel1->setLineStyle(QCPGraph::lsLine);
		m_graphChannel1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1.0));
	}
	m_graphChannel1->setData(m_x1, m_y1);

	if (m_graphChannel2 == nullptr)
	{
		drawPen.setColor(QColor(0xE3, 0xCF, 0x57));
		drawPen.setWidth(1);
		m_graphChannel2 = customplot->addGraph();
		m_graphChannel2->setPen(drawPen);
		m_graphChannel2->setLineStyle(QCPGraph::lsLine);
		m_graphChannel2->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1.0));
	}
	m_graphChannel2->setData(m_x2, m_y2);

	if (m_graphChannel3 == nullptr)
	{
		drawPen.setColor(QColor(0x00, 0xff, 0xff));
		drawPen.setWidth(1);
		m_graphChannel3 = customplot->addGraph();
		m_graphChannel3->setPen(drawPen);
		m_graphChannel3->setLineStyle(QCPGraph::lsLine);
		m_graphChannel3->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1.0));
	}
	m_graphChannel3->setData(m_x3, m_y3);

	if (m_graphChannel4 == nullptr)
	{
		drawPen.setColor(QColor(0x22, 0x8b, 0x22));
		drawPen.setWidth(1);
		m_graphChannel4 = customplot->addGraph();
		m_graphChannel4->setPen(drawPen);
		m_graphChannel4->setLineStyle(QCPGraph::lsLine);
		m_graphChannel4->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1.0));
		showLegend();
	}
	m_graphChannel4->setData(m_x4, m_y4);

	customplot->replot();

	m_sec++;
	mutex.unlock();
}


void DeviceMaintainPage_Axe_RealTimeTemp::showLegend()
{
	//Í¼Àý
	customplot->legend->setVisible(true);
	customplot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);
	customplot->legend->setBrush(QColor(255, 255, 255, 150));
	customplot->legend->setMargins(QMargins(0, 0, 0, 0));
	customplot->legend->setFont(QFont("Helvetica", 9));
	QStringList names;
	names << QString::fromLocal8Bit("T1") << QString::fromLocal8Bit("T2") << QString::fromLocal8Bit("T3") << QString::fromLocal8Bit("T4");
	for (int i = 0; i < 4; ++i) {
		customplot->graph(i)->setName(names[i]);//ÉèÖÃÃû³Æ
	}
}

void DeviceMaintainPage_Axe_RealTimeTemp::slot_modifyPlot()
{
	if (m_edtXStart->text().isEmpty() || m_edtXEnd->text().isEmpty() || \
		m_edtYStart->text().isEmpty() || m_edtYEnd->text().isEmpty())
		return;

	int xStart = m_edtXStart->text().toInt();
	int xEnd = m_edtXEnd->text().toInt();
	int yStart = m_edtYStart->text().toInt();
	int yEnd = m_edtYEnd->text().toInt();

	mutex.lock();
	customplot->xAxis->setRange(xStart, xEnd);
	customplot->yAxis->setRange(yStart, yEnd);
	customplot->replot();
	mutex.unlock();
}

void DeviceMaintainPage_Axe_RealTimeTemp::slot_clearTShow()
{
	m_edtT1->clear();
	m_edtT2->clear();
	m_edtT3->clear();
	m_edtT4->clear();
}