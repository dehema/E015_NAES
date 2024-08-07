#pragma once
#include "Common/HButtonIcon.h"
class AXEProcessItem_Icon : public HButtonIcon
{
public:
	AXEProcessItem_Icon(QString _normalIcon, QString _hoverIcon);
	~AXEProcessItem_Icon() {};

protected:
	void enterEvent(QEvent *event) override;
	void leaveEvent(QEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
};

