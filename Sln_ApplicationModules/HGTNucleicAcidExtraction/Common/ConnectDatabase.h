#pragma once
#include <QtCore/QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>



struct basic_data {
	QString database_workpath;  //���ݿ⹤���ռ�
	QString connect_name;   //��������
	QString database_name;  //���ݿ�����
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
	 *����            �������ݿ�ı���ռ�
	 *input           QString workpath
	 *output           NUll
	* result              ���������ļ���
   */
	void create_workpace(QString database_workpath);

	/*
	*Name       connect_to_database
	*����        һ�������������� ��;�������ݿ� �����������ݿ�ʹ�����Լ�����
	*input      ��������������ǣ����ݿ⹤���ռ䣬�������ƣ����ݿ����ƣ��û���������
	*output     null
	*
	*/
	bool create_database(QString database_workpath, QString connect_name, QString database_name, QString user_name, QString password);

	bool create_tables();

	bool execSQL(QString statement);

	void initBasicData();
};
