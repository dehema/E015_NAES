#pragma once
#include "DeviceMaintainPage_Axe_Base.h"
#include "Common/QCustomPlot.h"

class DeviceMaintainPage_Axe_RealTimeTemp : public DeviceMaintainPage_Axe_Base
{
	Q_OBJECT
public:
	DeviceMaintainPage_Axe_RealTimeTemp(QWidget * _parent, DeviceControlService _handle);
	~DeviceMaintainPage_Axe_RealTimeTemp() {};

	/* 第二个界面 */
	QHBoxLayout *m_hShow;
	QVBoxLayout *m_vShow;
	QScrollArea *m_imageScrollArea;
	QWidget *m_widShow;
	QWidget *m_curTempCurve;

	/* 自动获取状态复选框 */
	QCheckBox *m_ckAutoGetTemp;
	QFrame *m_frmSetting;
	QGroupBox *m_gbZoom;
	QLabel *m_lbXStart;
	HLineEdit *m_edtXStart;
	QLabel *m_lbXEnd;
	HLineEdit *m_edtXEnd;
	QLabel *m_lbYStart;
	HLineEdit *m_edtYStart;
	QLabel *m_lbYEnd;
	HLineEdit *m_edtYEnd;
	QPushButton *m_btnConfirm;

	/* 通道温度 */
	QLabel *m_lbT1;
	HLineEdit *m_edtT1;
	QLabel *m_lbT2;
	HLineEdit *m_edtT2;
	QLabel *m_lbT3;
	HLineEdit *m_edtT3;
	QLabel *m_lbT4;
	HLineEdit *m_edtT4;
	QGroupBox *m_gbTShow;
	QPushButton *m_btnClear;

	/* 实时温度查询曲线*/
	int m_sec;
	QVector <double> m_x1;
	QVector <double> m_y1;
	QVector <double> m_x2;
	QVector <double> m_y2;
	QVector <double> m_x3;
	QVector <double> m_y3;
	QVector <double> m_x4;
	QVector <double> m_y4;

	QCPGraph* m_graphChannel1;
	QCPGraph* m_graphChannel2;
	QCPGraph* m_graphChannel3;
	QCPGraph* m_graphChannel4;
	QMutex mutex;

	IFAXEService *m_axe;

	QCustomPlot *customplot;

	//-------------------------function-------------------------
	void initPlot(double x_start, double x_end, double y_start, double y_end);
	void initRealtimeShow();
	void clearVec();
	void showLegend();

protected:
	QLabel* getNewLbCommon(QString _langID = nullptr)override
	{
		QLabel* lb = DeviceMaintainPage_Axe_Base::getNewLbCommon(_langID);
		lb->setFixedWidth(70);
		return lb;
	}

	QPushButton* getNewBtCommon(QString _langID = nullptr) override
	{
		QPushButton* bt = DeviceMaintainPage_Axe_Base::getNewBtCommon(_langID);
		bt->setFixedWidth(160);
		return bt;
	}

	HLineEdit * getNewLineEdit() override
	{
		HLineEdit* edit = DeviceMaintainPage_Axe_Base::getNewLineEdit();
		edit->setFixedWidth(100);
		return edit;
	}

	QComboBox * getNewComboxBox(QStringList _langIDs = {}) override
	{
		QComboBox* cb = DeviceMaintainPage_Axe_Base::getNewComboxBox(_langIDs);
		cb->setFixedWidth(160);
		return cb;
	}

	protected slots:
	void slot_onStateChanged(int);
	void slot_recvCurTempData(int axeNumber, HeatBoardData data);
	void slot_modifyPlot();
	void slot_clearTShow();
};