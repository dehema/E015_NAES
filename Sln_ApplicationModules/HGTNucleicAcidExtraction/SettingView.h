#pragma once
#include "Common/BasePageContent.h"
#include "DeviceMaintainDialog.h"

class SettingView : public BasePageContent
{
	Q_OBJECT
private:
	enum BtType {
		//�豸ά��
		DeviceMaintain,
	};

public:
	SettingView(QWidget *parent);
	~SettingView() {};

	//----------------------UI----------------------
	QGridLayout* layoutMain;
	QComboBox* cbLang;

	//----------------------field----------------------
	QButtonGroup* btGroup;

	//----------------------function----------------------

	public slots:
	void slot_onclickBt(int _index);
	void slot_onLangIndexChange(int _index);
};

