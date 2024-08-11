#pragma once
#include "Common\BaseDialog.h"
#include "DeviceMaintainPage_Axe_Base.h"
#include "DeviceMaintainPage_Axe_Ele.h"
#include "DeviceMaintainPage_Axe_Temp.h"
#include "DeviceMaintainPage_Axe_RealTimeTemp.h"
#include "DeviceMaintainPage_Axe_Equip.h"
#include "DeviceMaintainPage_Axe_Setting.h"
#include "DeviceMaintainPage_Axe_Process.h"
#include "DeviceMaintainPage_Axe_Status.h"

class DeviceMaintainDialog : public BaseDialog
{
	Q_OBJECT
public:
	enum AXEPageGroup
	{
		//电机
		Axe_Ele,
		//温控板
		Axe_Temp,
		//实时温度
		Axe_RealTimeTemp,
		//其他设备
		Axe_Equip,
		//高级设置
		Axe_Setting,
		//流程
		Axe_Process,
		//状态查询
		Axe_Status,
	};

	DeviceMaintainDialog(QWidget* _parent, DeviceControlService deviceHandle);
	~DeviceMaintainDialog() {};

	//-------------------------------ui-------------------------------
	QHBoxLayout* layoutMain;
	QButtonGroup* bgMenu;

	QWidget* widgetPage;
	DeviceMaintainPage_Axe_Base* currPage;

	//菜单
	QWidget* widgetMenu;
	QVBoxLayout* layoutMenu;
	//-------------------------------field-------------------------------
	DeviceControlService deviceHandle;

	//---------------------电机---------------------
	DeviceMaintainPage_Axe_Ele* widgetEle;
	//---------------------温控板---------------------
	DeviceMaintainPage_Axe_Temp* widgetTemp;
	//---------------------实时温度---------------------
	DeviceMaintainPage_Axe_RealTimeTemp* widgetRealTimeTemp;
	//---------------------其他设备---------------------
	DeviceMaintainPage_Axe_Equip* widgetEquip;
	//---------------------高级设置---------------------
	DeviceMaintainPage_Axe_Setting* widgetSetting;
	//---------------------流程---------------------
	DeviceMaintainPage_Axe_Process* widgetProcess;
	//---------------------状态查询---------------------
	DeviceMaintainPage_Axe_Status* widgetStatus;
	//-------------------------------function-------------------------------

	private slots:
	void slot_onclickBgMenu(int _index);
};

