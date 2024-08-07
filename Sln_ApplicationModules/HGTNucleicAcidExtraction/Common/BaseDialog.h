#pragma once
#include "PopDialog.h"
#include "BaseUI.h"
#include "IBaseView.h"

class BaseDialog :public QDialog, public BaseUI, public IBaseView
{
	Q_OBJECT
public:
	BaseDialog(QWidget* parent);
	~BaseDialog() {};
	//----------------------UI----------------------
	QPushButton* btBaseClose = nullptr;

	//function
	virtual void setSize(float _width, float _height);
	void setTitle(QString str);

	//���ڿ��
	int baseDialogWidth = WIN_WIDTH;
	//���ڸ߶�
	int baseDialogHeight = WIN_HEIGHT;
	//��ͷ�߶�
	const int widgetBaseTitleHeight = 45;
	float getBaseContentWidth() { return baseDialogWidth; }
	float getBaseContentHeight() { return baseDialogHeight - widgetBaseTitleHeight; }
	void resize();
	void setDialogCenter();
	virtual void closeDialog();
	private slots:
	void slot_onclickClose();

private:
	QWidget* widgetBaseTitle = nullptr;
	QHBoxLayout* layoutBaseTitle = nullptr;
	QLabel* lbBaseTitle = nullptr;
	QWidget* widgetBaseMain = nullptr;
	QWidget* widgetBaseContentBg = nullptr;
};

