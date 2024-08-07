#pragma once
#include <QtCore/QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>



struct basic_data {
	QString database_workpath;  //数据库工作空间
	QString connect_name;   //链接名字
	QString database_name;  //数据库名字
	QString user_name;
	QString password;
};

class ConnectDatabase : public QObject
{
	Q_OBJECT

private:
	struct basic_data m_im;
	static ConnectDatabase *m_dbInstance;
	static bool m_bInit;

public:
	explicit ConnectDatabase(QObject *parent = nullptr);
	~ConnectDatabase();

	static ConnectDatabase *getDB();

	int getRowCounts(QString tableName);

	static void Release();

public:
	QSqlDatabase m_db;

private:
	bool initDB();


	/*Name           create_workpace
	 *功能            创建数据库的保存空间
	 *input           QString workpath
	 *output           NUll
	* result              创建工作文件夹
   */
	void create_workpace(QString database_workpath);

	/*
	*Name       connect_to_database
	*功能        一：创建创建链接 二;创建数据库 三：设置数据库使用者以及密码
	*input      五个参数，依次是：数据库工作空间，链接名称，数据库名称，用户名，密码
	*output     null
	*
	*/
	bool create_database(QString database_workpath, QString connect_name, QString database_name, QString user_name, QString password);

	bool create_tables();

	bool execSQL(QString statement);

	void initBasicData();
};
