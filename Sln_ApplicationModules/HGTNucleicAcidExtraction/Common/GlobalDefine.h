#pragma once
#include <QtCore/QString>
#include <QtCore/QList>

#include "./public/IFAXEService.h"

using namespace std;


//设备句柄
struct DeviceControlService
{
	IFAXEService *axeService;						//核酸提取仪

	DeviceControlService()
	{
		axeService = nullptr;
	}
};


class GlobalDefine
{
public:

};

//语言项
enum class LangType
{
	CN,
	EN
};