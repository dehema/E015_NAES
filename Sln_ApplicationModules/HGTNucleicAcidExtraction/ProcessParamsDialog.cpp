#include "ProcessParamsDialog.h"


ProcessParamsDialog::ProcessParamsDialog(QWidget* parent) : BaseDialog(parent)
{
	setModal(true);
	setSize(420, 450);

	QGridLayout* layoutMain = getNewGridLayout(widgetBaseContent);
	layoutMain->setAlignment(Qt::AlignCenter);

	//混合时间
	QLabel* lbMixTime = getNewLbCommon("1708420091");
	layoutMain->addWidget(lbMixTime, 0, 0);

	//混合速度
	QLabel* lbMixSpeed = getNewLbCommon("1708420093");
	layoutMain->addWidget(lbMixSpeed, 1, 0);

	//混合振幅底部位置
	QLabel* lbMixPos = getNewLbCommon("1708420334");
	layoutMain->addWidget(lbMixPos, 2, 0);

	//混合振幅顶部位置
	QLabel* lbMixAmplitude = getNewLbCommon("1708420335");
	layoutMain->addWidget(lbMixAmplitude, 3, 0);

	QPushButton* btSure = getNewBtCommon("1708419640");
	QWidget* widgetSure = getNewWidgetCommon(this);
	widgetSure->setFixedSize(getBaseContentWidth(), 35);
	layoutMain->addWidget(widgetSure, 4, 0);
	QHBoxLayout* layoutSure = getNewHBoxLayout(widgetSure);
	layoutSure->addWidget(btSure);
}