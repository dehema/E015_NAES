#pragma once
#include "QtWidgets/QTableView.h"
#include "QtWidgets/QScrollBar.h"
#include "HTableViewItemModel.h"

//��װ�ı�� �й�����������ҳ������������Ӧλ��
class HTableView : public QTableView
{
	Q_OBJECT

public:
	explicit HTableView(QWidget* parent = nullptr);
	~HTableView() {};

	//------------------------field------------------------
	//�и�
	const int rowHeight = 30;
	//��ǰҳ��
	int pageIndex = 1;

	//------------------------function------------------------
	//������
	int getRowSum();
	//��ҳ��
	int getPageSum();
	//ÿҳ�м���
	int getRowSumPerPage();
	//��һҳ
	void moveToLastPage();
	//��һҳ
	void moveToNextPage();
	//����ҳ��
	void setPageIndexVal(int _index);
	//����ĳһҳ
	void movePageTo(int _pageIndex);
	void setModel(HTableViewItemModel* model);
	void setModel(QStandardItemModel* model);

	public slots:
	//����ĳһ������
	void moveRowTo(int _index);

signals:
	//��ǰҳ��ı�ʱ
	void signal_onPageIndexChange(int _pageIndex);
};

