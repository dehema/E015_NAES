#pragma once
#include "DeviceMaintainPage_Axe_Base.h"

class DeviceMaintainPage_Axe_Equip :public DeviceMaintainPage_Axe_Base
{
	Q_OBJECT
private:
	enum BtType
	{
		//����������ʱ��
		SubtractUVTime,
		//����������ʱ��
		AddUVTime,
	};

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
	QButtonGroup* btGroup;

	QTabWidget *m_mainTab;
	QWidget *m_stepMonitor;
	QVBoxLayout *m_vblMain;

	/* ������ȡ�Ǳ�� */
	QComboBox *m_cbAXENumber;

	/* ���ڶ˿ں�*/
	QComboBox* m_cbComNumber;

	/* ���ȿ��� */
	QPushButton *m_btnFanStart;

	/* ���ȹر� */
	QPushButton *m_btnFanStop;

	/* ����ƿ��� */
	QPushButton *m_btnUVStart;

	HLineEdit* editUVTime;
	QTime timeUV = QTime(0, 30);
	QTimer* timerUV;

	/* ����ƹر� */
	QPushButton *m_btnUVStop;

	/* ���ſ��� */
	QPushButton *m_btnDoorOpen;

	/* ���Źر� */
	QPushButton *m_btnDoorClose;

	/* �����ƴ� */
	QPushButton *m_btnLightOpen;

	/* �����ƹر� */
	QPushButton *m_btnLightClose;

	/* װ�شŰ��� */
	QPushButton *m_btnLoadSleeve;
	QLabel *m_lbLoadColumn;
	QComboBox *m_edtLoadColumn;

	/* ж�شŰ��� */
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

	QPushButton* getNewBtCommon(QString _langID = "") override
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

	private slots:
	void slot_onclickBtGroup(int _index);
};
