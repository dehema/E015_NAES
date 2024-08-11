#pragma once
#include <QtWidgets/QStackedWidget>
#include "Common/QCustomPlot.h"
#include "DeviceMaintainPage_Axe_Base.h"

class DeviceMaintainPage_Axe_Temp :public DeviceMaintainPage_Axe_Base
{
	Q_OBJECT
public:
	DeviceMaintainPage_Axe_Temp(QWidget* _parent, DeviceControlService _handle);
	~DeviceMaintainPage_Axe_Temp() {
		if (axeService != nullptr) axeService->disable();
	};

	protected slots:
	void slot_btnGetCurrentDegreeClicked();
	void slot_btnStartHeatBoardClicked();
	void slot_btnStopHeatBoardClicked();
	void slot_btnQueryHeatBoardClicked();
	void slot_btnSetHeatBoardClicked();
	void slot_cbChannelNumberChanged(int);
	void slot_cbQueryChannelNumberChanged(int);
	void slot_cbSetChannelNumberChanged(int);
	void slot_btnQueryPidClicked();
	void slot_btnSetPidClicked();
	void slot_btnQueryControlCorrectedClicked();
	void slot_btnSetControlCorrectedClicked();
	void slot_btnQueryMeasureCorrectedClicked();
	void slot_btnSetMeasureCorrectedClicked();
	void slot_btnQueryLoadPolarityClicked();
	void slot_btnSetLoadPolarityClicked();
	void slot_bntRealtimeTempClicked();

private:
	void initAreas();
	void initWidgetArea1();
	void initWidgetArea2();
	void initWidgetArea4();
	void initWidgetArea5();
	void initWidgetArea6();
	void initWidgetArea7();
	void initWidgetArea8();
	void initWidgetArea9();
	void initWidgetArea10();
	void setConnection();
	void fillCbChannelItem(QComboBox* _cb);
	QLabel* getNewLabel(QString _str, int _width = 30);

private:
	QStackedWidget *m_mainStacked;
	QWidget *m_heatBoradCmd;
	QWidget *m_curTempCurve;

	QTabWidget *m_mainTab;
	QWidget *m_stepMonitor;
	QVBoxLayout *m_vblMain;

	QFrame *m_qfmArea1;
	QFrame *m_qfmArea2;
	QFrame *m_qfmArea3;
	QFrame *m_qfmArea5;
	QFrame *m_qfmArea6;
	QFrame *m_qfmArea7;
	QFrame *m_qfmArea8;
	QFrame *m_qfmArea9;
	QFrame *m_qfmArea10;

	QHBoxLayout *m_hblArea2;
	QHBoxLayout *m_hblArea3;
	QHBoxLayout *m_hblArea4;
	QHBoxLayout *m_hblArea5;
	QHBoxLayout *m_hblArea6;
	QHBoxLayout *m_hblArea7;
	QHBoxLayout *m_hblArea8;
	QHBoxLayout *m_hblArea9;
	QHBoxLayout *m_hblArea10;

	/* 实时温度显示 */
	QPushButton *m_btnRealtimeTemp;

	/* 温控板获取当前温度 */
	QPushButton *m_btnGetCurrentDegree;
	QComboBox *m_cbChannelNumber;
	QLabel *m_lbTemp1;
	HLineEdit *m_edtTemp1;
	QLabel *m_lbTemp2;
	HLineEdit *m_edtTemp2;
	QLabel *m_lbTemp3;
	HLineEdit *m_edtTemp3;
	QLabel *m_lbTemp4;
	HLineEdit *m_edtTemp4;

	/* 温控板开启 */
	QPushButton *m_btnHeatBoardStart;
	QComboBox *m_cbStartChannelNumber;

	/* 温控板关闭 */
	QPushButton *m_btnHeatBoardStop;
	QComboBox *m_cbStopChannelNumber;

	/* 温控板目标温度查询 */
	QPushButton *m_btnQueryHeatBoard;
	QComboBox *m_cbQueryChannelNumber;
	QLabel *m_lbQueryTemp1;
	HLineEdit *m_edtQueryTemp1;
	QLabel *m_lbQueryTemp2;
	HLineEdit *m_edtQueryTemp2;
	QLabel *m_lbQueryTemp3;
	HLineEdit *m_edtQueryTemp3;
	QLabel *m_lbQueryTemp4;
	HLineEdit *m_edtQueryTemp4;

	/* 温控板目标温度设置 */
	QPushButton *m_btnSetHeatBoard;
	QComboBox *m_cbSetChannelNumber;
	QLabel *m_lbSetTemp1;
	HLineEdit *m_edtSetTemp1;

	/* PID参数查询设置 */
	QPushButton *m_btnQueryPid;
	QPushButton *m_btnSetPid;
	QComboBox *m_cbPidChannelNumber;
	QLabel *m_lbPParam;
	HLineEdit *m_edtPParam;
	QLabel *m_lbIParam;
	HLineEdit *m_edtIParam;
	QLabel *m_lbDParam;
	HLineEdit *m_edtDParam;

	/* 控温修正值查询设置 */
	QPushButton *m_btnQueryControlCorrected;
	QPushButton *m_btnSetControlCorrected;
	QComboBox *m_cbControlChannelNumber;
	QLabel *m_lbControlCorrected;
	HLineEdit *m_edtControlCorrected;

	/* 测量修正值查询设置 */
	QPushButton *m_btnQueryMeasureCorrected;
	QPushButton *m_btnSetMeasureCorrected;
	QComboBox *m_cbMeasureChannelNumber;
	QLabel *m_lbMeasureCorrected;
	HLineEdit *m_edtMeasureCorrected;

	/* 负载极性查询设置 */
	QPushButton *m_btnQueryLoadPolarity;
	QPushButton *m_btnSetLoadPolarity;
	QComboBox *m_cbPolarityChannelNumber;
	QLabel *m_lbLoadPolarity;
	HLineEdit *m_edtLoadPolarity;

	QCustomPlot *customplot;
	QVector <double> m_cur_x;
	QVector <double> m_cur_y;
	QTimer* m_interTimer;
	QCPGraph *m_noColGraph;

	//-------------------------field-------------------------
	const int axeNumber = 1;
	bool m_bOpen;
	bool m_bShowRealTime;

	//-------------------------function-------------------------
protected:
	QLabel* getNewLbCommon(QString _langID = nullptr)override
	{
		QLabel* lb = DeviceMaintainPage_Axe_Base::getNewLbCommon(_langID);
		lb->setFixedWidth(70);
		return lb;
	}

	const int constBtWidth = 140;
	QPushButton* getNewBtCommon(QString _langID = nullptr) override
	{
		QPushButton* bt = DeviceMaintainPage_Axe_Base::getNewBtCommon(_langID);
		bt->setFixedWidth(constBtWidth);
		UIUtility::ins().adjustBtTextSize(bt);
		return bt;
	}

	HLineEdit * getNewLineEdit() override
	{
		HLineEdit* edit = DeviceMaintainPage_Axe_Base::getNewLineEdit();
		edit->setFixedWidth(70);
		return edit;
	}

	QComboBox * getNewComboxBox(QStringList _langIDs = {}) override
	{
		QComboBox* cb = DeviceMaintainPage_Axe_Base::getNewComboxBox(_langIDs);
		cb->setFixedWidth(110);
		return cb;
	}
};

