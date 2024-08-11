#include "DeviceMaintainPage_Axe_Base.h"

DeviceMaintainPage_Axe_Base::DeviceMaintainPage_Axe_Base(QWidget* _parent, DeviceControlService _handle) :
	BaseView(_parent), deviceHandle(_handle), axeService(_handle.axeService)
{
	axeStatus = &Utility::ins().axeStatus;
	this->setFixedSize(_parent->width(), _parent->height());
	this->move(0, 0);
}

bool DeviceMaintainPage_Axe_Base::setWidgetsBlockSignal(bool _isBlock)
{
	return false;
}

void DeviceMaintainPage_Axe_Base::addSignalWidget(QWidget * _widget)
{
}
