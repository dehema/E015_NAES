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

//值范围
const class ValRange
{
public:
	int lower;
	int upper;
	int defaultVal;
	ValRange(int _lower = 0, int _upper = 0, int _defaultVal = 0)
	{
		lower = _lower;
		upper = _upper;
		defaultVal = _defaultVal;
	}
};

//核提参数限制
const class AXEParamsLimit
{
public:
	//体系容量
	ValRange volume = ValRange(1, 1000, 800);
	//混合速度
	ValRange mixSpeed = ValRange(200, 3000, 1000);
	//混合底部位置
	ValRange mixBottomPos = ValRange(0, 50, 10);
	//混合顶部位置
	ValRange mixTopPos = ValRange(0, 100, 50);
	//吸磁位置
	ValRange magnetPos = ValRange(0, 100, 10);
	//温度
	ValRange temperature = ValRange(25, 120, 50);
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