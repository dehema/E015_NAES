#pragma once
#include "DeviceMaintainPage_Axe_Base.h"

class DeviceMaintainPage_Axe_Status :public DeviceMaintainPage_Axe_Base
{
	Q_OBJECT
public:
	DeviceMaintainPage_Axe_Status(QWidget* _parent, DeviceControlService _handle);
	~DeviceMaintainPage_Axe_Status()
	{
		if (axeService != nullptr) axeService->disable();
	}

	protected slots:
	void slot_onStateChanged(int);
	void slot_recvAxeStatusData(int axeNumber, AXEModuleStatus status);

private:
	void initAreas();
	void initWidgetArea1();
	void initWidgetArea2();
	void initWidgetArea4();
	void initWidgetArea5();
	void initWidgetArea8();
	void initWidgetArea11();
	void setConnection();

private:
	QTabWidget *m_mainTab;
	QWidget *m_stepMonitor;
	QVBoxLayout *m_vblMain;

	QFrame *m_qfmArea1;
	QFrame *m_qfmArea3;
	QFrame *m_qfmArea5;
	QFrame *m_qfmArea8;
	QFrame *m_qfmArea11;

	QHBoxLayout *m_hblArea1;
	QHBoxLayout *m_hblArea2;
	QHBoxLayout *m_hblArea4;
	QHBoxLayout *m_hblArea5;
	QHBoxLayout *m_hblArea8;
	QHBoxLayout *m_hblArea11;

	/* ´®¿Ú¶Ë¿ÚºÅ*/
	QComboBox* m_cbComNumber;

	/* ×Ô¶¯»ñÈ¡×´Ì¬¸´Ñ¡¿ò */
	QCheckBox *m_ckAutoGetStatus;

	QLabel *m_lbStepMonitorStatus;
	QLabel *m_lbSMChannel1;
	HLineEdit *m_edtSMChannel1;
	QLabel *m_lbSMChannel2;
	HLineEdit *m_edtSMChannel2;
	QLabel *m_lbSMChannel3;
	HLineEdit *m_edtSMChannel3;
	QLabel *m_lbSMChannel4;
	HLineEdit *m_edtSMChannel4;
	QLabel *m_lbSMChannel5;
	HLineEdit *m_edtSMChannel5;

	/* ÎÂ¿Ø°å×´Ì¬ */
	QLabel *m_lbHeatBoardStatus;
	QLabel *m_lbHBChannel1;
	HLineEdit *m_edtHBChannel1;
	QLabel *m_lbHBChannel2;
	HLineEdit *m_edtHBChannel2;
	QLabel *m_lbHBChannel3;
	HLineEdit *m_edtHBChannel3;
	QLabel *m_lbHBChannel4;
	HLineEdit *m_edtHBChannel4;

	/* ·çÉÈ×´Ì¬ */
	QLabel *m_lbFanStatus;
	HLineEdit *m_edtFanStatus;

	/* ×ÏÍâµÆ×´Ì¬ */
	QLabel *m_lbUVStatus;
	HLineEdit *m_edtUVStatus;

	/* ´Å°ôÌ×ÔÚÎ»×´Ì¬ */
	QLabel *m_lbSleeveStatus;
	HLineEdit *m_edtSleeveStatus;

	/* Ô¤ÖÃ°åÔÚÎ»×´Ì¬ */
	QLabel *m_lbPBStatus;
	HLineEdit *m_edtPBStatus;

	/* ²ÕÃÅ×´Ì¬ */
	QLabel *m_lbDoorStatus;
	HLineEdit *m_edtDoorStatus;

	/* Á÷³ÌÊ¶±ðID */
	QLabel *m_lbProcessID;
	HLineEdit *m_edtProcessID;

	/* ºËËáÌáÈ¡ÒÇ×´Ì¬ */
	QLabel *m_lbAxeStatus;
	HLineEdit *m_edtAxeStatus;

	/* ´Å°ôÌ×À¬»øºÐ×´Ì¬ */
	QLabel *m_lbTrashBoxStatus;
	HLineEdit *m_edtTrashBoxStatus;

	/* ´Å°ôÌ×ºÐ×´Ì¬ */
	QLabel *m_lbSleeveBoxStatus;
	HLineEdit *m_edtSleeveBoxStatus;

	/* ÕÕÃ÷µÆ×´Ì¬ */
	QLabel *m_lbFloodLightStatus;
	HLineEdit *m_edtFloodLightStatus;

	//-------------------------field-------------------------
	const int axeNumber = 1;
	bool m_bOpen;

	//-------------------------function-------------------------
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
};
