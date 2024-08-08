#include "ProcessParamsDialog.h"


ProcessParamsDialog::ProcessParamsDialog(QWidget* parent, AXEStepData& _stepData, AXEParamsType _paramsType) :
	BaseDialog(parent), stepData(_stepData), paramsType(_paramsType)
{
	setModal(true);
	setSize(420, 400);

	QGridLayout* layoutMain = getNewGridLayout(widgetBaseContent);
	layoutMain->setContentsMargins(40, 0, 40, 0);
	layoutMain->setHorizontalSpacing(10);
	layoutMain->setVerticalSpacing(20);
	layoutMain->setAlignment(Qt::AlignCenter);

	int row = 0;
	if (paramsType == AXEParamsType::Mix)
	{
		//混合时间
		QLabel* lbMixTime = getNewLbCommon();
		lbMixTime->setText(GetLang("1708420091") + "(Sec)");
		layoutMain->addWidget(lbMixTime, row, 0);

		editMixTime = getNewLineEdit();
		editMixTime->setText(QString::number(stepData.mixTime));
		editMixTime->setMaxLength(4);
		layoutMain->addWidget(editMixTime, row++, 1);

		//混合速度
		QLabel* lbMixSpeed = getNewLbCommon("1708420093");
		lbMixSpeed->setText(GetLang("1708420093") + "(PRM)");
		layoutMain->addWidget(lbMixSpeed, row, 0);

		editMixSpeed = getNewLineEdit();
		editMixSpeed->setText(QString::number((stepData.mixSpeed)));
		editMixSpeed->setPlaceholderText("200-3000%");
		editMixSpeed->setMaxLength(4);
		editMixSpeed->setValidator(UIUtility::ins().RegExpNumber);
		layoutMain->addWidget(editMixSpeed, row++, 1);

		//混合振幅底部位置
		QLabel* lbMixPos = getNewLbCommon("1708420334");
		lbMixPos->setText(GetLang("1708420334") + "(%)");
		layoutMain->addWidget(lbMixPos, row, 0);

		editMixPos = getNewLineEdit();
		editMixPos->setText(QString::number((stepData.mixPos)));
		editMixPos->setPlaceholderText("0-50%");
		editMixPos->setMaxLength(3);
		editMixPos->setValidator(UIUtility::ins().RegExpNumber);
		layoutMain->addWidget(editMixPos, row++, 1);

		//混合振幅顶部位置
		QLabel* lbMixAmplitude = getNewLbCommon("1708420335");
		lbMixAmplitude->setText(GetLang("1708420335") + "(%)");
		layoutMain->addWidget(lbMixAmplitude, row, 0);

		editMixAmplitude = getNewLineEdit();
		editMixAmplitude->setText(QString::number((stepData.mixAmplitude)));
		editMixAmplitude->setPlaceholderText("0-100%");
		editMixAmplitude->setMaxLength(3);
		editMixAmplitude->setValidator(UIUtility::ins().RegExpNumber);
		layoutMain->addWidget(editMixAmplitude, row++, 1);
	}
	else if (paramsType == AXEParamsType::Magnet)
	{
		//吸磁时间
		QLabel* lbMagnetTime = getNewLbCommon("1708420092");
		layoutMain->addWidget(lbMagnetTime, row, 0);

		editMagnetTime = getNewLineEdit();
		editMagnetTime->setText(QString::number((stepData.magnetTime)));
		editMagnetTime->setMaxLength(4);
		layoutMain->addWidget(editMagnetTime, row++, 1);

		//吸磁速度
		QLabel* lbMagnetSpeed = getNewLbCommon("1708420332");
		layoutMain->addWidget(lbMagnetSpeed, row, 0);

		cbMagnetSpeed = getNewComboxBox(AXEMgr::ins().magnetSpeedStr);
		cbMagnetSpeed->setValidator(UIUtility::ins().RegExpNumber);
		cbMagnetSpeed->setCurrentIndex(stepData.magnetSpeed - 1);
		layoutMain->addWidget(cbMagnetSpeed, row++, 1);

		//吸磁位置
		QLabel* lbAdsorbPosition = getNewLbCommon();
		lbAdsorbPosition->setText(GetLang("1708420336") + "(%)");
		layoutMain->addWidget(lbAdsorbPosition, row, 0);

		editAdsorbPosition = getNewLineEdit();
		editAdsorbPosition->setText(QString::number((stepData.adsorbPosition)));
		editAdsorbPosition->setPlaceholderText("1-100%");
		editAdsorbPosition->setMaxLength(3);
		editAdsorbPosition->setValidator(UIUtility::ins().RegExpNumber);
		layoutMain->addWidget(editAdsorbPosition, row++, 1);
	}
	else if (paramsType == AXEParamsType::Wait)
	{
		//等待时间
		QLabel* lbWaitTime = getNewLbCommon("1708420092");
		layoutMain->addWidget(lbWaitTime, row, 0);

		editWaitTime = getNewLineEdit();
		editWaitTime->setText(QString::number((stepData.waitTime)));
		editWaitTime->setMaxLength(4);
		layoutMain->addWidget(editWaitTime, row++, 1);

		//是否加热
		QLabel* lbMixTime = getNewLbCommon("1708420332");
		layoutMain->addWidget(lbMixTime, row, 0);

		cbWaitHeatStatus = getNewComboxBox({ "1708420165","1708420164" });
		cbWaitHeatStatus->setValidator(UIUtility::ins().RegExpNumber);
		cbWaitHeatStatus->setCurrentIndex(stepData.heatStatus);
		layoutMain->addWidget(cbWaitHeatStatus, row++, 1);

		//目标温度
		QLabel* lbTemperature = getNewLbCommon();
		lbTemperature->setText(GetLang("1708420338") + QString::fromLocal8Bit("(℃)"));
		layoutMain->addWidget(lbTemperature, row, 0);

		editHeat = getNewLineEdit();
		editHeat->setText(QString::number((stepData.targetTemp)));
		editHeat->setPlaceholderText("25-120");
		editHeat->setMaxLength(3);
		editHeat->setValidator(UIUtility::ins().RegExpNumber);
		layoutMain->addWidget(editHeat, row++, 1);
	}

	QPushButton* btSure = getNewBtCommon("1708419640");
	connect(btSure, SIGNAL(clicked()), this, SLOT(slot_onclickSure()));
	QWidget* widgetSure = getNewWidgetCommon(this);
	widgetSure->setFixedSize(200, 35);
	layoutMain->addWidget(widgetSure, row, 0, 1, 2, Qt::AlignCenter);
	QHBoxLayout* layoutSure = getNewHBoxLayout(widgetSure);
	layoutSure->setAlignment(Qt::AlignCenter);
	layoutSure->addWidget(btSure);
}

QLabel* ProcessParamsDialog::getNewLbCommon(QString _langID)
{
	QLabel* lb = BaseDialog::getNewLbCommon(_langID);
	lb->setAlignment(Qt::AlignCenter);
	lb->setFixedSize(180, 35);
	if (!_langID.isEmpty())
		lb->setText(GetLang(_langID));
	return lb;
}

HLineEdit * ProcessParamsDialog::getNewLineEdit()
{
	HLineEdit* edit = BaseDialog::getNewLineEdit();
	edit->setFixedSize(widgetWidth, 35);
	return edit;
}

QComboBox* ProcessParamsDialog::getNewComboxBox(QStringList _langIDs)
{
	QComboBox* cb = BaseDialog::getNewComboxBox(_langIDs);
	cb->setFixedSize(widgetWidth, 35);
	return cb;
}

bool ProcessParamsDialog::checkProcessParams()
{
	if (paramsType == AXEParamsType::Mix)
	{
		//混合速度
		int mixSpeed = editMixSpeed->text().toInt();
		if (mixSpeed < 200 || mixSpeed > 3000)
		{
			HGT::Error(this, GetLang("1708419637"), GetLang("1708420413").arg(200).arg(3000), QMessageBox::Yes);
			return false;
		}
		//混合振幅底部位置
		int mixPos = editMixPos->text().toInt();
		if (mixPos < 0 || mixPos > 50)
		{
			HGT::Error(this, GetLang("1708419637"), GetLang("1708420413").arg(0).arg(50), QMessageBox::Yes);
			return false;
		}
		//混合振幅顶部位置
		int mixAmplitude = editMixAmplitude->text().toInt();
		if (mixPos < 0 || mixPos > 100)
		{
			HGT::Error(this, GetLang("1708419637"), GetLang("1708420413").arg(1).arg(100), QMessageBox::Yes);
			return false;
		}
	}
	else if (paramsType == AXEParamsType::Magnet)
	{
		//吸磁位置
		int dsorbPosition = editAdsorbPosition->text().toInt();
		if (dsorbPosition < 1 || dsorbPosition > 100)
		{
			HGT::Error(this, GetLang("1708419637"), GetLang("1708420415").arg(1).arg(100), QMessageBox::Yes);
			return false;
		}
	}
	else if (paramsType == AXEParamsType::Wait)
	{
		//温度状态
		int targetTemp = editHeat->text().toInt();
		if (targetTemp < 25 || targetTemp > 120)
		{
			HGT::Error(this, GetLang("1708419637"), GetLang("1708420416").arg(25).arg(120), QMessageBox::Yes);
			return false;
		}
	}
}

void ProcessParamsDialog::slot_onclickSure()
{
	if (!checkProcessParams())
	{
		return;
	}
	if (paramsType == AXEParamsType::Mix)
	{
		stepData.mixTime = editMixTime->text().toInt();
		stepData.mixSpeed = editMixSpeed->text().toInt();
		stepData.mixPos = editMixPos->text().toInt();
		stepData.mixAmplitude = editMixAmplitude->text().toInt();
	}
	else if (paramsType == AXEParamsType::Magnet)
	{
		stepData.magnetTime = editMagnetTime->text().toInt();
		stepData.magnetSpeed = cbMagnetSpeed->currentIndex() + 1;
		stepData.adsorbPosition = editAdsorbPosition->text().toInt();
	}
	else if (paramsType == AXEParamsType::Wait)
	{
		stepData.waitTime = editWaitTime->text().toInt();
		stepData.heatStatus = cbWaitHeatStatus->currentIndex();
		stepData.targetTemp = editHeat->text().toInt();
	}
	close();
}