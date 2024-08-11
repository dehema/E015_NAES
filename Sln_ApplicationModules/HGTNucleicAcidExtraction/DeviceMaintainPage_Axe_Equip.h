#pragma once
#include "DeviceMaintainPage_Axe_Base.h"

class DeviceMaintainPage_Axe_Equip :public DeviceMaintainPage_Axe_Base
{
	Q_OBJECT
public:
	DeviceMaintainPage_Axe_Equip(QWidget* _parent, DeviceControlService _handle);
	~DeviceMaintainPage_Axe_Equip() {
		if (axeService != nullptr) axeService->disable();
	};

	protected slots:
	void slot_btnStartFanClicked();
	void slot_btnStopFanClicked();
	void slot_btnStartUVClicked();
	void slot_btnStopUVClicked();
	void slot_btnOpenDoorClicked();
	void slot_btnCloseDoorClicked();
	void slot_btnLightOpenClicked();
	void slot_btnLightCloseClicked();
	void slot_btnLoadSleeveClicked();
	void slot_btnUnloadSleeveClicked();

private:
	void setConnection();

private:
	QTabWidget *m_mainTab;
	QWidget *m_stepMonitor;
	QVBoxLayout *m_vblMain;

	/* ºËËáÌáÈ¡ÒÇ±àºÅ */
	QComboBox *m_cbAXENumber;

	/* ´®¿Ú¶Ë¿ÚºÅ*/
	QComboBox* m_cbComNumber;

	/* ·çÉÈ¿ªÆô */
	QPushButton *m_btnFanStart;

	/* ·çÉÈ¹Ø±Õ */
	QPushButton *m_btnFanStop;

	/* ×ÏÍâµÆ¿ªÆô */
	QPushButton *m_btnUVStart;

	HLineEdit* editUVTime;
	QTime timeUV = QTime(0, 15);
	QTimer* timerUV;

	/* ×ÏÍâµÆ¹Ø±Õ */
	QPushButton *m_btnUVStop;

	/* ²ÕÃÅ¿ªÆô */
	QPushButton *m_btnDoorOpen;

	/* ²ÕÃÅ¹Ø±Õ */
	QPushButton *m_btnDoorClose;

	/* ÕÕÃ÷µÆ´ò¿ª */
	QPushButton *m_btnLightOpen;

	/* ÕÕÃ÷µÆ¹Ø±Õ */
	QPushButton *m_btnLightClose;

	/* ×°ÔØ´Å°ôÌ× */
	QPushButton *m_btnLoadSleeve;
	QLabel *m_lbLoadColumn;
	QComboBox *m_edtLoadColumn;

	/* Ð¶ÔØ´Å°ôÌ× */
	QPushButton *m_btnUnloadSleeve;
	QLabel *m_lbUnloadColumn;
	QComboBox *m_edtUnloadColumn;

	//-------------------------field-------------------------
	bool m_bOpen;
	const int axeNumber = 1;

	//-------------------------function-------------------------
	void refreshEditUVTime();

protected:
	QLabel* getNewLbCommon(QString _langID)override
	{
		QLabel* lb = DeviceMaintainPage_Axe_Base::getNewLbCommon(_langID);
		lb->setFixedWidth(70);
		return lb;
	}

	QPushButton* getNewBtCommon(QString _langID) override
	{
		QPushButton* bt = DeviceMaintainPage_Axe_Base::getNewBtCommon(_langID);
		bt->setFixedWidth(150);
		return bt;
	}

	HLineEdit * getNewLineEdit() override
	{
		HLineEdit* edit = DeviceMaintainPage_Axe_Base::getNewLineEdit();
		edit->setFixedWidth(150);
		return edit;
	}

	QComboBox * getNewComboxBox(QStringList _langIDs = {}) override
	{
		QComboBox* cb = DeviceMaintainPage_Axe_Base::getNewComboxBox(_langIDs);
		cb->setFixedWidth(150);
		return cb;
	}
};
