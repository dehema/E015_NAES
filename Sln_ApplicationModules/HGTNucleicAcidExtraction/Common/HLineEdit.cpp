#include "HLineEdit.h"
#include <QtGui/QMouseEvent>
#include <iostream>

HLineEdit::HLineEdit()
{
}


HLineEdit::HLineEdit(QWidget *parent)
{
	setParent(parent);
}

HLineEdit::~HLineEdit()
{

}

// single click for the Linux platform
void HLineEdit::mousePressEvent(QMouseEvent *event)
{
#if defined(__UNIX) || defined(unix)
    if (this->isReadOnly())
        return;

    m_keyboard = getSoftKeyboardService(this);
    if (m_keyboard == nullptr)
        return;

    m_keyboard->setChineseInputSupported(true);

    connect(m_keyboard, SIGNAL(signal_sendPinyin(const QString &)), this, SLOT(slot_getInput(const QString &)));
    m_keyboard->setCurrentString(this->text());
    m_keyboard->setValidator((QValidator *)this->validator());
    m_keyboard->showKeyboard();
    this->update();
#endif
}

// double click for the Windows platform
void HLineEdit::mouseDoubleClickEvent(QMouseEvent *event)
{
#if defined WIN32   //for WIN32
    if (this->isReadOnly())
        return;

    m_keyboard = getSoftKeyboardService(this);
    if (m_keyboard == nullptr)
        return;
    m_keyboard->setChineseInputSupported(true);

    if (event->button() == Qt::LeftButton)
    {
        connect(m_keyboard, SIGNAL(signal_sendPinyin(const QString &)), this, SLOT(slot_getInput(const QString &)));
        m_keyboard->setCurrentString(this->text());
        m_keyboard->setValidator((QValidator *)this->validator());
        m_keyboard->showKeyboard();
    }
    this->update();
#endif
}

void HLineEdit::slot_getInput(const QString &data)
{
    this->setText(data);
    disconnect(m_keyboard, SIGNAL(signal_sendPinyin(const QString &)), this, SLOT(slot_getInput(const QString &)));
}
