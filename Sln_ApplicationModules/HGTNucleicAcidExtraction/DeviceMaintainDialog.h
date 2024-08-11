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
		//���
		Axe_Ele,
		//�¿ذ�
		Axe_Temp,
		//ʵʱ�¶�
		Axe_RealTimeTemp,
		//�����豸
		Axe_Equip,
		//�߼�����
		Axe_Setting,
		//����
		Axe_Process,
		//״̬��ѯ
		Axe_Status,
	};

	DeviceMaintainDialog(QWidget* _parent, DeviceControlService deviceHandle);
	~DeviceMaintainDialog() {};

	//-------------------------------ui-------------------------------
	QHBoxLayout* layoutMain;
	QButtonGroup* bgMenu;

	QWidget* widgetPage;
	DeviceMaintainPage_Axe_Base* currPage;

	//�˵�
	QWidget* widgetMenu;
	QVBoxLayout* layoutMenu;
	//-------------------------------field-------------------------------
	DeviceControlService deviceHandle;

	//---------------------���---------------------
	DeviceMaintainPage_Axe_Ele* widgetEle;
	//---------------------�¿ذ�---------------------
	DeviceMaintainPage_Axe_Temp* widgetTemp;
	//---------------------ʵʱ�¶�---------------------
	DeviceMaintainPage_Axe_RealTimeTemp* widgetRealTimeTemp;
	//---------------------�����豸---------------------
	DeviceMaintainPage_Axe_Equip* widgetEquip;
	//---------------------�߼�����---------------------
	DeviceMaintainPage_Axe_Setting* widgetSetting;
	//---------------------����---------------------
	DeviceMaintainPage_Axe_Process* widgetProcess;
	//---------------------״̬��ѯ---------------------
	DeviceMaintainPage_Axe_Status* widgetStatus;
	//-------------------------------function-------------------------------

	private slots:
	void slot_onclickBgMenu(int _index);
};

