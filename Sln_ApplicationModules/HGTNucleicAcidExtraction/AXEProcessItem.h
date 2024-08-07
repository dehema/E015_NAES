#pragma once
#include "common/BaseView.h"
#include "common/UIUtility.h"
#include "AXEProcessItem_Icon.h"

class AXEProcessItem :public BaseView
{
public:
	AXEProcessItem(QWidget *parent);
	~AXEProcessItem() {};

	//-----------------------UI-----------------------
	AXEProcessItem_Icon *icon;
	QLabel* lb;


	//-----------------------field-----------------------

	//-----------------------function-----------------------
	void setText(QString str);
	void setFixedSize(int width, int height);
};

