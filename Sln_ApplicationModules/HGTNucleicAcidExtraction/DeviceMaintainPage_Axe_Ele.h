#pragma once
#include "DeviceMaintainPage_Axe_Base.h"

class DeviceMaintainPage_Axe_Ele :public DeviceMaintainPage_Axe_Base
{
	Q_OBJECT
public:
	DeviceMaintainPage_Axe_Ele(QWidget* _parent, DeviceControlService _handle);
	~DeviceMaintainPage_Axe_Ele() {
		if (axeService != nullptr) axeService->disable();
	};

	protected slots:
	void slot_btnStepMonitorRunClicked();
	void slot_btnStepMonitorStopClicked();
	void slot_btnStepMonitorZeroClicked();
	void slot_btnStepMonitorAbsposRunClicked();
	void slot_btnSetStepMonitorStatusClicked();
	void slot_btnLockStepMonitorClicked();
	void slot_cbMonitorNumberChanged(int);
	void slot_cbMonitorAbsNumberChanged(int);

private:
	/* ����������� */
	QPushButton *m_btnStepMonitorRun;
	QLabel *m_lbMonitorNumber;
	QComboBox *m_cbMonitorNumber;
	QLabel *m_lbMonitorDirection;
	QComboBox *m_edtMonitorDirection;
	QLabel *m_lbMonitorSpeed;
	HLineEdit *m_edtMonitorSpeed;
	QLabel *m_lbMonitorDistance;
	HLineEdit* m_edtMonitorDistance;

	/* �������ֹͣ */
	QPushButton *m_btnStepMonitorStop;
	QComboBox *m_cbStopMonitorNumber;

	/* ����������� */
	QPushButton *m_btnStepMonitorZero;
	QComboBox *m_cbZeroMonitorNumber;

	/* �����������λ������ */
	QPushButton *m_btnStepMonitorAbsRun;
	QLabel *m_lbMonitorAbsNumber;
	QComboBox *m_cbMonitorAbsNumber;
	QLabel *m_lbMonitorAbsDistance;
	HLineEdit *m_edtMonitorAbsDistance;

	/* ��������ѻ����� */
	QPushButton *m_btnSetStepMonitorStatus;
	QLabel *m_lbMonitorSetNumber;
	QComboBox *m_cbMonitorSetNumber;
	QLabel *m_lbMonitorSetStatus;
	HLineEdit *m_edtMonitorSetStatus;

	/* ����������� */
	QPushButton *m_btnStepMonitorLock;

	/* ֱ��������� */
	QPushButton *m_btnDCMonitorRun;
	QLabel *m_lbDCMonitorSpeed;
	HLineEdit *m_edtDCMonitorSpeed;

	/* ֱ�������ͣ */
	QPushButton *m_btnDCMonitorStop;

	HLineEdit *m_edtMoveSpeed;
	HLineEdit *m_edtX;
	HLineEdit *m_edtY;
	HLineEdit *m_edtZ;
	HLineEdit *m_edtR;
	QComboBox *m_cbxHandType;

	//-------------------------field-------------------------
	const int axeNumber = 1;

	void setConnection();

	//-------------------------function-------------------------
protected:
	QLabel* getNewLbCommon(QString _langID)override
	{
		QLabel* lb = DeviceMaintainPage_Axe_Base::getNewLbCommon(_langID);
		lb->setFixedWidth(70);
		return lb;
	}

	QPushButton* getNewBtCommon(QString _langID) override
	{
		QPushButton* bt = DeviceMaintainPage_Axe_Base::getNewBtCommon(_langID);
		bt->setFixedWidth(130);
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
		cb->setFixedWidth(160);
		return cb;
	}
};

