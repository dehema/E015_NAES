#pragma once
#include "DeviceMaintainPage_Axe_Base.h"

class DeviceMaintainPage_Axe_Setting :public DeviceMaintainPage_Axe_Base
{
	Q_OBJECT
public:
	DeviceMaintainPage_Axe_Setting(QWidget* _parent, DeviceControlService _handle);
	~DeviceMaintainPage_Axe_Setting()
	{
		if (m_axe != nullptr) m_axe->disable();
	}

	protected slots:
	void slot_btnQueryDoorPosClicked();
	void slot_btnSetDoorPosClicked();
	void slot_btnQueryFixedPosClicked();
	void slot_btnSetFixedPosClicked();
	//void slot_btnGetSleeveSpeedClicked();
	//void slot_btnSetSleeveSpeedClicked();
	void slot_btnGetSleevePosClicked();
	void slot_btnSetSleevePosClicked();
	void slot_btnGetBarPosClicked();
	void slot_btnSetBarPosClicked();
	void slot_btnGetHorPosClicked();
	void slot_btnSetHorPosClicked();
	//void slot_btnQueryLoadingPosClicked();
	//void slot_btnSetLoadingPosClicked();

private:
	void initAreas();
	void initWidgetArea1();
	void initWidgetArea2();
	//void initWidgetArea4();
	void initWidgetArea5();
	void initWidgetArea6();
	void initWidgetArea7();
	//void initWidgetArea8();
	void setConnection();

private:
	QTabWidget *m_mainTab;
	QWidget *m_stepMonitor;
	QVBoxLayout *m_vblMain;

	QWidget *m_qfmArea1;
	QWidget *m_qfmArea2;
	QWidget *m_qfmArea3;
	QWidget *m_qfmArea5;
	QWidget *m_qfmArea6;
	QWidget *m_qfmArea7;
	QWidget *m_qfmArea8;

	QHBoxLayout *m_hblArea2;
	QHBoxLayout *m_hblArea3;
	QHBoxLayout *m_hblArea4;
	QHBoxLayout *m_hblArea5;
	QHBoxLayout *m_hblArea6;
	QHBoxLayout *m_hblArea7;
	QHBoxLayout *m_hblArea8;

	/* ���ڶ˿ں�*/
	QComboBox* m_cbComNumber;

	/* ������λ�ò�ѯ ���� */
	QPushButton *m_btnQueryDoorPos;
	QPushButton *m_btnSetDoorPos;
	QLabel *m_lbSetBZero;
	HLineEdit *m_edtSetBZero;
	QLabel *m_lbSetAZero;
	HLineEdit *m_edtSetAzero;

	/* �̶�λ�ò�ѯ ���� */
	QPushButton *m_btnQueryFixedPos;
	QPushButton *m_btnSetFixedPos;
	QLabel *m_lbFixedXpos;
	HLineEdit *m_edtFixedXpos;
	QLabel *m_lbFixedYpos;
	HLineEdit *m_edtFixedYpos;
	QLabel *m_lbFixedZpos;
	HLineEdit *m_edtFixedZpos;

	/* �Ű���λ�ò�ѯ ���� */
	QPushButton *m_btnGetMagneticSleevePos;
	QPushButton *m_btnSetMagneticSleevePos;
	/* �Ű��׶��� */
	QLabel *m_lbSleeveTopPos;
	HLineEdit *m_edtSleeveTopPos;
	/* �Լ��б��� */
	QLabel *m_lbKitBoxPos;
	HLineEdit *m_edtKitBoxPos;
	/* �Լ��б���ײ� */
	QLabel *m_lbKitBoxBottom;
	HLineEdit *m_edtBitBoxBottom;

	/* ������ȡ�ǴŰ�λ�ò�ѯ */
	QPushButton *m_btnGetMagneticBarPos;
	QPushButton *m_btnSetMagneticBarPos;
	//����λ
	QLabel *m_lbGetBarAfterZero;
	HLineEdit *m_edtGetBarAfterZero;
	//����λ
	QLabel *m_lbGetBarBeforeZero;
	HLineEdit *m_edtGetBarBeforeZero;

	/* ˮƽλ�ò�ѯ���� */
	QPushButton *m_btnGetHorPos;
	QPushButton *m_btnClearHorPos;
	QPushButton *m_btnSetHorPos;
	QLabel *m_lbGetHorPos1;
	HLineEdit *m_edtGetHorPos1;
	QLabel *m_lbGetHorPos2;
	HLineEdit *m_edtGetHorPos2;
	QLabel *m_lbGetHorPos3;
	HLineEdit *m_edtGetHorPos3;
	QLabel *m_lbGetHorPos4;
	HLineEdit *m_edtGetHorPos4;
	QLabel *m_lbGetHorPos5;
	HLineEdit *m_edtGetHorPos5;
	QLabel *m_lbGetHorPos6;
	HLineEdit *m_edtGetHorPos6;

	//-------------------------field-------------------------
	const int axeNumber = 1;
	IFAXEService *m_axe;
	bool m_bOpen;

	//-------------------------function-------------------------
protected:
	QLabel* getNewLbCommon(QString _langID = nullptr)override
	{
		QLabel* lb = DeviceMaintainPage_Axe_Base::getNewLbCommon(_langID);
		lb->setMinimumWidth(90);
		return lb;
	}

	QPushButton* getNewBtCommon(QString _langID = nullptr) override
	{
		QPushButton* bt = DeviceMaintainPage_Axe_Base::getNewBtCommon(_langID);
		bt->setFixedWidth(120);
		return bt;
	}

	HLineEdit * getNewLineEdit() override
	{
		HLineEdit* edit = DeviceMaintainPage_Axe_Base::getNewLineEdit();
		edit->setFixedWidth(70);
		return edit;
	}

	QComboBox * getNewComboxBox(QStringList _langIDs = {}) override
	{
		QComboBox* cb = DeviceMaintainPage_Axe_Base::getNewComboxBox(_langIDs);
		cb->setFixedWidth(160);
		return cb;
	}
};
