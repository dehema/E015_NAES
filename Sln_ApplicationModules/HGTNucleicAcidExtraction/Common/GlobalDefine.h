#pragma once
#include <QtCore/QString>
#include <QtCore/QList>

#include "./public/IFAXEService.h"

using namespace std;


//�豸���
struct DeviceControlService
{
	IFAXEService *axeService;						//������ȡ��

	DeviceControlService()
	{
		axeService = nullptr;
	}
};


class GlobalDefine
{
public:

};

//������
enum class LangType
{
	CN,
	EN
};