#pragma once
#include "UIUtility.h"

class IBaseView
{
public:
	IBaseView();
	~IBaseView();
	QWidget* widgetBaseContent = nullptr;
};

