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

//ֵ��Χ
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

//�����������
const class AXEParamsLimit
{
public:
	//��ϵ����
	ValRange volume = ValRange(1, 1000, 800);
	//����ٶ�
	ValRange mixSpeed = ValRange(200, 3000, 1000);
	//��ϵײ�λ��
	ValRange mixBottomPos = ValRange(0, 50, 10);
	//��϶���λ��
	ValRange mixTopPos = ValRange(0, 100, 50);
	//����λ��
	ValRange magnetPos = ValRange(0, 100, 10);
	//�¶�
	ValRange temperature = ValRange(25, 120, 50);
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