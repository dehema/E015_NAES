#pragma once
#include "DeviceMaintainPage_Axe_Base.h"
#include "AXEMgr.h"

class DeviceMaintainPage_Axe_Process :public DeviceMaintainPage_Axe_Base
{
	Q_OBJECT
public:
	DeviceMaintainPage_Axe_Process(QWidget* _parent, DeviceControlService _handle);

	~DeviceMaintainPage_Axe_Process()
	{
		if (axeService != nullptr) axeService->disable();
	}

	protected slots:
	void slot_btnProcessControlClicked();
	void slot_btnGetProcessVerClicked();
	void slot_btnStartMixedProcess();
	void slot_btnStartHeatProcess();
	void slot_btnNextPageClicked();
	void slot_btnFrontPageClicked();

private:
	void initWidgetArea1();
	void initWidgetArea2();
	void initWidgetArea4();
	void initWidgetArea6();
	void setConnection();

private:
	QTabWidget *m_mainTab;
	QWidget *m_stepMonitor; QVBoxLayout *m_vblMain;
	QWidget *m_firstPage;
	QWidget *m_secondPage;

	QWidget *m_qfmArea1;
	QWidget *m_qfmArea2;
	QWidget *m_qfmArea3;
	QWidget *m_qfmArea5;
	QWidget *m_qfmArea6;

	QHBoxLayout *m_hblArea2;
	QHBoxLayout *m_hblArea3;
	QGridLayout *m_hblArea4;
	QGridLayout *m_hblArea6;

	/* ���ڶ˿ں�*/
	QComboBox* m_cbComNumber;

	/* ��һҳ */
	QPushButton *m_btnNextPage;
	/* ��һҳ */
	QPushButton *m_btnFrontPage;

	/* ������ȡ�����̿��� */
	QPushButton *m_btnProcessControl;
	QLabel *m_lbControlCmd;
	QComboBox *m_cbProcessControl;

	/* ���̰汾��ѯ */
	QPushButton *m_btnQueryProcessVer;
	QLabel *m_lbQueryProcessVer;
	HLineEdit *m_edtQueryProcessVer;

	/* -------�������--------- */
	QPushButton *m_btnMixedProcess;

	/* ����ʶ����*/
	QLabel *m_lbProcessID;
	HLineEdit *m_edtProcessID;

	/* �к� */
	QLabel *m_lbColumnNum;
	HLineEdit *m_edtColumnNum;

	/* ���ʱ�� */
	QLabel *m_lbMixedTime;
	HLineEdit *m_edtMixedTime;

	/* ����ٶ� */
	QLabel *m_lbMixedSpeed;
	HLineEdit *m_edtMixedSpeed;

	/* ����ʱ�� */
	QLabel *m_lbAdsorbTime;
	HLineEdit *m_edtAdsorbTime;

	/* �����ٶ� */
	QLabel *m_lbAdsorbSpeed;
	QComboBox *m_cbAdsorbSpeed;

	/* �ȴ�ʱ�� */
	QLabel *m_lbWaitTime;
	HLineEdit *m_edtWaitTime;

	/* �ݻ� */
	QLabel *m_lbVolume;
	HLineEdit *m_edtVolume;

	/* ���λ�� */
	QLabel *m_lbMixPosition;
	HLineEdit *m_edtMixPosition;

	/* ������ */
	QLabel *m_lbMixAmplitude;
	HLineEdit *m_edtMixAmplitude;

	/* ����λ�� */
	QLabel *m_lbAdsorbPosition;
	HLineEdit *m_edtAdsorbPosition;

	/* -------��������--------- */
	QPushButton *m_btnHeatProcess;
	/* ����ʶ����*/
	QLabel *m_lbHeatProcessID;
	HLineEdit *m_edtHeatProcessID;
	/* ��� */
	QLabel *m_lbGroupNum;
	QComboBox *m_cbGroupNum;
	/* Ŀ���¶� */
	QLabel *m_lbAimDegree;
	HLineEdit *m_edtAimDegree;
	/* �Ƿ����  */
	QLabel *m_lbIsHeat;
	QComboBox *m_cbIsHeat;

	//-------------------------field-------------------------
	const int axeNumber = 1;
	bool m_bOpen;

	//-------------------------function-------------------------
protected:
	QLabel* getNewLbCommon(QString _langID = nullptr)override
	{
		QLabel* lb = DeviceMaintainPage_Axe_Base::getNewLbCommon(_langID);
		lb->setFixedWidth(90);
		lb->setAlignment(Qt::AlignCenter);
		return lb;
	}

	QPushButton* getNewBtCommon(QString _langID = nullptr) override
	{
		QPushButton* bt = DeviceMaintainPage_Axe_Base::getNewBtCommon(_langID);
		bt->setFixedWidth(135);
		return bt;
	}

	HLineEdit * getNewLineEdit() override
	{
		HLineEdit* edit = DeviceMaintainPage_Axe_Base::getNewLineEdit();
		edit->setFixedWidth(90);
		return edit;
	}

	QComboBox * getNewComboxBox(QStringList _langIDs = {}) override
	{
		QComboBox* cb = DeviceMaintainPage_Axe_Base::getNewComboxBox(_langIDs);
		cb->setFixedWidth(90);
		return cb;
	}
};