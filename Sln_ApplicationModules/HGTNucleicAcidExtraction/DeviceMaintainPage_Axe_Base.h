#pragma once
#include "common\BaseView.h"
class DeviceMaintainPage_Axe_Base : public BaseView
{
public:
	DeviceMaintainPage_Axe_Base(QWidget* _parent, DeviceControlService _handle);
	~DeviceMaintainPage_Axe_Base() {};


	QList<QWidget*> signalWidgetList;
	DeviceControlService deviceHandle;
	//������
	IFAXEService* axeService = nullptr;
	//����״̬
	AXEModuleStatus* axeStatus;

	bool setWidgetsBlockSignal(bool _isBlock);
	void addSignalWidget(QWidget* _widget);
};

