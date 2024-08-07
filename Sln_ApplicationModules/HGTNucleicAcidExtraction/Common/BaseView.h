#pragma once
#include "BaseWidget.h"

class BaseView :public BaseWidget
{
public:
	BaseView(QWidget* _parent = nullptr);
	~BaseView() {};

	int getContentWidth();
};

