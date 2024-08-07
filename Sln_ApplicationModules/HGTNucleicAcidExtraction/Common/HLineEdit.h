#pragma once
#include <QtWidgets/QLineEdit>
#include "../../Sln_CommonLibrary/HGTSoftKeyboardService/SoftKeyboardService.h"
class HLineEdit :
    public QLineEdit
{
    Q_OBJECT
public:
    HLineEdit();
	HLineEdit(QWidget *parent);
    virtual ~HLineEdit();

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

private:
    IFSoftKeyboardService *m_keyboard;

public slots:
    void slot_getInput(const QString &data);
};

