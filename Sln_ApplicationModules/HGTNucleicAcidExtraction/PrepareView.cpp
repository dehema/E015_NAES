#include "PrepareView.h"

PrepareView::PrepareView(QWidget *parent) :BasePageContent(parent)
{
	axeThread = dynamic_cast<AxeThread*>(Utility::ins().axeThread);

	btGroup = new QButtonGroup();
	//UI
	layoutMain = getNewGridLayout(this);
	layoutMain->setContentsMargins(Page_Dialog_Padding_Left, Page_Dialog_Padding_Top, Page_Dialog_Padding_Right, Page_Dialog_Padding_Bottom);
	layoutMain->setHorizontalSpacing(40);
	layoutMain->setVerticalSpacing(30);
	layoutMain->setAlignment(Qt::AlignCenter);

	//舱门开启
	QPushButton* btOpenDoor = getNewBtLarge("1708420293");
	layoutMain->addWidget(btOpenDoor, 0, 0);
	connect(btOpenDoor, &QAbstractButton::clicked, this, [=]() {
		Utility::ins().deviceHandle.axeService->openDoor(1);
	});

	//舱门关闭
	QPushButton* btCloseDoor = getNewBtLarge("1708420294");
	layoutMain->addWidget(btCloseDoor, 0, 1);
	connect(btCloseDoor, &QAbstractButton::clicked, this, [=]() {
		Utility::ins().deviceHandle.axeService->closeDoor(1);
	});

	//装载枪头
	QComboBox* cbLoadAxeTips = getNewComboxBoxLarge();
	cbLoadAxeTips->addItems({ "1,7","2,8","3,9","4,10","5,11","6,12" });
	layoutMain->addWidget(cbLoadAxeTips, 1, 0);

	QPushButton* btLoadAxeTips = getNewBtLarge("1708420400");
	layoutMain->addWidget(btLoadAxeTips, 1, 1);
	connect(btLoadAxeTips, &QAbstractButton::clicked, this, [=]() {
		Utility::ins().deviceHandle.axeService->loadMagneticBarSleeve(1, cbLoadAxeTips->currentIndex() + 1);
	});

	//卸载枪头
	QComboBox* cbUnloadAxeTips = getNewComboxBoxLarge();
	cbUnloadAxeTips->addItems({ "1,7","2,8","3,9","4,10","5,11","6,12" });
	layoutMain->addWidget(cbUnloadAxeTips, 2, 0);

	QPushButton* btUnloadAxeTips = getNewBtLarge("1708420401");
	layoutMain->addWidget(btUnloadAxeTips, 2, 1);
	connect(btUnloadAxeTips, &QAbstractButton::clicked, this, [=]() {
		Utility::ins().deviceHandle.axeService->unloadMagneticBarSleeve(1, cbUnloadAxeTips->currentIndex() + 1);
	});
}