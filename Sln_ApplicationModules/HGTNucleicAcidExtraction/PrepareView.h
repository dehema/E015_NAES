#pragma once
#include "Common/BasePageContent.h"
#include "DeviceMaintainDialog.h"
#include "Common/UIUtility.h"
#include "AxeThread.h"
#include "AXEMgr.h"

class PrepareView:public BasePageContent
{
	Q_OBJECT
private:
	enum BtType {
		Continue,
		Pause,
		Reset,
		Close,
	};
public:
	PrepareView(QWidget *parent);
	~PrepareView() {};

	//--------------------UI--------------------
	QGridLayout* layoutMain;

	//--------------------field--------------------
	QButtonGroup* btGroup;
	//Ïß³Ì
	AxeThread* axeThread;

	//--------------------function--------------------
};

