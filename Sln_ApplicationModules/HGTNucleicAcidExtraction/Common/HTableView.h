#pragma once
#include "QtWidgets/QTableView.h"
#include "QtWidgets/QScrollBar.h"
#include "HTableViewItemModel.h"

//封装的表格 有滚动条，上下页跳到滚动条对应位置
class HTableView : public QTableView
{
	Q_OBJECT

public:
	explicit HTableView(QWidget* parent = nullptr);
	~HTableView() {};

	//------------------------field------------------------
	//行高
	const int rowHeight = 30;
	//当前页数
	int pageIndex = 1;

	//------------------------function------------------------
	//总行数
	int getRowSum();
	//总页数
	int getPageSum();
	//每页有几行
	int getRowSumPerPage();
	//上一页
	void moveToLastPage();
	//下一页
	void moveToNextPage();
	//设置页码
	void setPageIndexVal(int _index);
	//跳到某一页
	void movePageTo(int _pageIndex);
	void setModel(HTableViewItemModel* model);
	void setModel(QStandardItemModel* model);

	public slots:
	//跳到某一条数据
	void moveRowTo(int _index);

signals:
	//当前页码改变时
	void signal_onPageIndexChange(int _pageIndex);
};

