#include "ProcessParamsDialog.h"

ProcessParamsDialog::ProcessParamsDialog(QWidget* parent, AXEStepData& _stepData, AXEParamsType _paramsType) :
	BaseDialog(parent), stepData(_stepData), paramsType(_paramsType)
{
	setModal(true);
	setSize(420, 400);

	switch (_paramsType)
	{
	case ProcessParamsDialog::Mix:
		setTitle(GetLang("1708420379"));
		break;
	case ProcessParamsDialog::Magnet:
		setTitle(GetLang("1708430054"));
		break;
	case ProcessParamsDialog::Wait:
		setTitle(GetLang("1708430055"));
		break;
	}

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
		editMixSpeed->setPlaceholderText(QString("%1%-%2%").
			arg(QString::number(paramsLimit.mixSpeed.lower)).
			arg(QString::number(paramsLimit.mixSpeed.upper)));
		editMixSpeed->setValidator(new QIntValidator(
			paramsLimit.mixSpeed.lower,
			paramsLimit.mixSpeed.upper,
			this));
		editMixSpeed->setMaxLength(4);
		layoutMain->addWidget(editMixSpeed, row++, 1);

		//混合振幅底部位置
		QLabel* lbMixPos = getNewLbCommon("1708420334");
		lbMixPos->setText(GetLang("1708420334") + "(%)");
		layoutMain->addWidget(lbMixPos, row, 0);

		editMixPos = getNewLineEdit();
		editMixPos->setText(QString::number((stepData.mixPos)));
		editMixPos->setPlaceholderText(QString("%1%-%2%").
			arg(QString::number(paramsLimit.mixBottomPos.lower)).
			arg(QString::number(paramsLimit.mixBottomPos.upper)));
		editMixPos->setValidator(new QIntValidator(
			paramsLimit.mixBottomPos.lower,
			paramsLimit.mixBottomPos.upper,
			this));
		editMixPos->setMaxLength(3);
		layoutMain->addWidget(editMixPos, row++, 1);

		//混合振幅顶部位置
		QLabel* lbMixAmplitude = getNewLbCommon("1708420335");
		lbMixAmplitude->setText(GetLang("1708420335") + "(%)");
		layoutMain->addWidget(lbMixAmplitude, row, 0);

		editMixAmplitude = getNewLineEdit();
		editMixAmplitude->setText(QString::number((stepData.mixAmplitude)));
		editMixAmplitude->setPlaceholderText(QString("%1%-%2%").
			arg(QString::number(paramsLimit.mixTopPos.lower)).
			arg(QString::number(paramsLimit.mixTopPos.upper)));
		editMixAmplitude->setValidator(new QIntValidator(
			paramsLimit.mixTopPos.lower,
			paramsLimit.mixTopPos.upper,
			this));
		editMixAmplitude->setMaxLength(3);
		layoutMain->addWidget(editMixAmplitude, row++, 1);
	}
	else if (paramsType == AXEParamsType::Magnet)
	{
		//吸磁时间
		QLabel* lbMagnetTime = getNewLbCommon();
		lbMagnetTime->setText(GetLang("1708420092") + "(Sec)");
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
		editAdsorbPosition->setPlaceholderText(QString("%1%-%2%").
			arg(QString::number(paramsLimit.magnetPos.lower)).
			arg(QString::number(paramsLimit.magnetPos.upper)));
		editAdsorbPosition->setValidator(new QIntValidator(
			paramsLimit.magnetPos.lower,
			paramsLimit.magnetPos.upper,
			this));
		editAdsorbPosition->setMaxLength(3);
		layoutMain->addWidget(editAdsorbPosition, row++, 1);
	}
	else if (paramsType == AXEParamsType::Wait)
	{
		//等待时间
		QLabel* lbWaitTime = getNewLbCommon();
		lbWaitTime->setText(GetLang("1708420090") + "(Sec)");
		layoutMain->addWidget(lbWaitTime, row, 0);

		editWaitTime = getNewLineEdit();
		editWaitTime->setText(QString::number((stepData.waitTime)));
		editWaitTime->setMaxLength(4);
		layoutMain->addWidget(editWaitTime, row++, 1);

		//是否加热
		QLabel* lbMixTime = getNewLbCommon("1708420339");
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
		editHeat->setPlaceholderText(QString("%1%-%2%").
			arg(QString::number(paramsLimit.temperature.lower)).
			arg(QString::number(paramsLimit.temperature.upper)));
		editHeat->setValidator(new QIntValidator(
			paramsLimit.temperature.lower,
			paramsLimit.temperature.upper,
			this));
		editHeat->setMaxLength(3);
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
		if (mixSpeed < paramsLimit.mixSpeed.lower || mixSpeed > paramsLimit.mixSpeed.upper)
		{
			HGT::Error(this, GetLang("1708419637"), GetLang("1708420413")
				.arg(paramsLimit.mixSpeed.lower)
				.arg(paramsLimit.mixSpeed.upper)
				, QMessageBox::Yes);
			return false;
		}
		//混合振幅底部位置
		int mixPos = editMixPos->text().toInt();
		if (mixPos < paramsLimit.mixBottomPos.lower || mixPos > paramsLimit.mixBottomPos.upper)
		{
			HGT::Error(this, GetLang("1708419637"), GetLang("1708430056")
				.arg(paramsLimit.mixBottomPos.lower)
				.arg(paramsLimit.mixBottomPos.upper), QMessageBox::Yes);
			return false;
		}
		//混合振幅顶部位置
		int mixAmplitude = editMixAmplitude->text().toInt();
		if (mixAmplitude < paramsLimit.mixTopPos.lower || mixAmplitude > paramsLimit.mixTopPos.upper)
		{
			HGT::Error(this, GetLang("1708419637"), GetLang("1708430057")
				.arg(paramsLimit.mixTopPos.lower)
				.arg(paramsLimit.mixTopPos.upper)
				, QMessageBox::Yes);
			return false;
		}
		if (mixPos > mixAmplitude)
		{
			HGT::Error(this, GetLang("1708419637"), GetLang("1708430064"), QMessageBox::Yes);
			return false;
		}
	}
	else if (paramsType == AXEParamsType::Magnet)
	{
		//吸磁位置
		int dsorbPosition = editAdsorbPosition->text().toInt();
		if (dsorbPosition < paramsLimit.magnetPos.lower || dsorbPosition > paramsLimit.magnetPos.upper)
		{
			HGT::Error(this, GetLang("1708419637"), GetLang("1708420415")
				.arg(paramsLimit.magnetPos.lower)
				.arg(paramsLimit.magnetPos.upper)
				, QMessageBox::Yes);
			return false;
		}
	}
	else if (paramsType == AXEParamsType::Wait)
	{
		//温度状态
		int targetTemp = editHeat->text().toInt();
		if (targetTemp < paramsLimit.temperature.lower || targetTemp > paramsLimit.temperature.upper)
		{
			HGT::Error(this, GetLang("1708419637"), GetLang("1708420416")
				.arg(paramsLimit.temperature.lower)
				.arg(paramsLimit.temperature.upper)
				, QMessageBox::Yes);
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