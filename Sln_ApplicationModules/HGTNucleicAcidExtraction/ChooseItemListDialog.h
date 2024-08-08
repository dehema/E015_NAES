#pragma once
#include "Common/BaseDialog.h"
class ChooseItemListDialog : public BaseDialog
{
	Q_OBJECT
public:
	ChooseItemListDialog(QWidget* _parent, QList<QString> _strList, QString _emptyTips = GetLang("1708420483"));
	~ChooseItemListDialog() {};
	//-------------------------ui-------------------------
	QVBoxLayout* layoutMain;
	QWidget* widgetScrollArea;
	QScrollArea* scrollArea;
	QWidget* widgetPage;
	QVBoxLayout* layoutItemIDs;
	QButtonGroup* buttonGroup;
	QList<QString> strList;

	//-------------------------field-------------------------
	int clickIndex = -1;

	//-------------------------function-------------------------
	int exec() override;
	void setSize(float _width, float _height) override;
	public slots:
	void slot_onclickButtonGroup(int _index);
};

