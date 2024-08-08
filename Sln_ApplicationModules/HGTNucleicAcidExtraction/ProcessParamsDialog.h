#pragma once
#include "Common/BaseDialog.h"
#include "Common\UIUtility.h"
#include "AXEMgr.h"

class ProcessParamsDialog : public BaseDialog
{
	Q_OBJECT
public:
	enum AXEParamsType
	{
		Mix,
		Magnet,
		Wait,
	};

	ProcessParamsDialog(QWidget* parent, AXEStepData& stepData, AXEParamsType _paramsType);
	~ProcessParamsDialog() {};

	//----------------------UI----------------------
private:
	//»ìºÏ
	HLineEdit* editMixTime;
	HLineEdit* editMixSpeed;
	HLineEdit* editMixPos;
	HLineEdit* editMixAmplitude;

	//Îü´Å
	HLineEdit* editMagnetTime;
	QComboBox* cbMagnetSpeed;
	HLineEdit* editAdsorbPosition;

	//µÈ´ý
	HLineEdit* editWaitTime;
	QComboBox* cbWaitHeatStatus;
	HLineEdit* editHeat;

	//----------------------field----------------------
	const int widgetWidth = 120;
	AXEStepData& stepData;
	AXEParamsType paramsType;
	//----------------------function----------------------
	QLabel* getNewLbCommon(QString _langID = nullptr) override;
	HLineEdit* getNewLineEdit() override;
	QComboBox* getNewComboxBox(QStringList _langIDs = {}) override;

	bool checkProcessParams();

	public slots:
	void slot_onclickSure();
};

