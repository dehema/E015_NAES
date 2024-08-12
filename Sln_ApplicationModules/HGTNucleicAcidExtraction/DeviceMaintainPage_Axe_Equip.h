#pragma once
#include "DeviceMaintainPage_Axe_Base.h"

class DeviceMaintainPage_Axe_Equip :public DeviceMaintainPage_Axe_Base
{
	Q_OBJECT
private:
	enum BtType
	{
		//减少紫外线时间
		SubtractUVTime,
		//增加紫外线时间
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

	/* 核酸提取仪编号 */
	QComboBox *m_cbAXENumber;

	/* 串口端口号*/
	QComboBox* m_cbComNumber;

	/* 风扇开启 */
	QPushButton *m_btnFanStart;

	/* 风扇关闭 */
	QPushButton *m_btnFanStop;

	/* 紫外灯开启 */
	QPushButton *m_btnUVStart;

	HLineEdit* editUVTime;
	QTime timeUV = QTime(0, 30);
	QTimer* timerUV;

	/* 紫外灯关闭 */
	QPushButton *m_btnUVStop;

	/* 舱门开启 */
	QPushButton *m_btnDoorOpen;

	/* 舱门关闭 */
	QPushButton *m_btnDoorClose;

	/* 照明灯打开 */
	QPushButton *m_btnLightOpen;

	/* 照明灯关闭 */
	QPushButton *m_btnLightClose;

	/* 装载磁棒套 */
	QPushButton *m_btnLoadSleeve;
	QLabel *m_lbLoadColumn;
	QComboBox *m_edtLoadColumn;

	/* 卸载磁棒套 */
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
