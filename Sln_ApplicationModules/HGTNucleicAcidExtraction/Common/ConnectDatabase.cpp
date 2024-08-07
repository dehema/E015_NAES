#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QDebug>
#include <QtCore/QPluginLoader>
#include <QtWidgets/QApplication>
//#include "../messages/HGTMessageBox.h"
#include "ConnectDatabase.h"

//#include "../LogService/Logger.h"

//using HGT::Log;
//using HGT::Logger;

ConnectDatabase* ConnectDatabase::m_dbInstance = new ConnectDatabase();
bool ConnectDatabase::m_bInit = false;

ConnectDatabase::ConnectDatabase(QObject *parent) : QObject(parent)
{
/*
#if defined(__UNIX) || defined(unix)
	QString path = QDir::currentPath();
	QApplication::addLibraryPath(path + QString("/plugins"));
	QPluginLoader loader(path + QString("/plugins/sqldrivers/libsqlite3.so"));

#else
	//QString path = QApplication::applicationDirPath();
	//QApplication::addLibraryPath(path + QString("/plugins"));
	//QPluginLoader loader(path + QString("/plugins/sqldrivers/qsqlite.dll"));

#endif
*/
	initBasicData();
}

void ConnectDatabase::initBasicData()
{
	m_im.database_workpath = QString("QPCRDatabase");
	m_im.connect_name = QString("QPCRDB");
	m_im.database_name = QString("QPCRTaskDB");
	m_im.user_name = QString("hgt");
	m_im.password = QString("123456");
}

ConnectDatabase *ConnectDatabase::getDB()
{
	if (m_dbInstance != nullptr && m_bInit)
		return m_dbInstance;

	if (!m_dbInstance->initDB())
	{
		delete m_dbInstance;
		m_dbInstance = nullptr;
	}

	return m_dbInstance;
}

void ConnectDatabase::Release()
{

}

bool ConnectDatabase::initDB()
{
	create_workpace(m_im.database_workpath);
	m_bInit = create_database(m_im.database_workpath, m_im.connect_name, m_im.database_name, m_im.user_name, m_im.password);

	return m_bInit;
}

ConnectDatabase::~ConnectDatabase()
{

}

void ConnectDatabase::create_workpace(QString database_workpath)
{
	QDir dir;
	QFile file(database_workpath);

	if (file.exists())
		return;

	dir.mkdir(database_workpath);
	if (!dir.exists())
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "Create DBFile fail";
	}
	else
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "Create DBFile Success";
	}
}


bool ConnectDatabase::create_database(QString database_workpath, QString connect_name, QString database_name, QString user_name, QString password)
{
	if (QSqlDatabase::contains(connect_name))
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "connect exists";
		m_db = QSqlDatabase::database(connect_name);
	}
	else
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "start create main thread db";
		m_db = QSqlDatabase::addDatabase("QSQLITE", connect_name);
		QString dbpath = QApplication::applicationDirPath() + "/" + database_workpath.append("/").append(database_name).append(".db");
		m_db.setDatabaseName(dbpath);
		m_db.open();
		QString err1 = m_db.lastError().driverText();
		QString err2 = m_db.lastError().nativeErrorCode();
	}

	if (!QSqlDatabase::contains(connect_name))
		return false;

	if (!create_tables())
		return false;

	return true;
}

bool ConnectDatabase::create_tables()
{
	if (!m_db.open())
		return false;

	//bool bSuc = false;
	//QSqlQuery query(m_db);


	QStringList tables;
	tables.append(m_db.tables());

	QString tablelist = "list:\n";
	int tableSize = tables.size();

	for (int i = 0; i < tables.size(); i++)
	{
		tablelist += QString::number(i + 1) + ". " + tables.at(i);
	}

	//qDebug() << tables;

	tablelist = tablelist.toUpper();
	if (tablelist.contains("DEVICEINFO") && tablelist.contains("DEVICEACTION"))
	{
		m_db.close();
		return true;
	}

	//Log(Logger::HGT_STATUS, HGT::General) << "start create table";
	bool bSuc = false;
	QSqlQuery query(m_db);

	/* 任务表 */
	bSuc = query.exec("CREATE TABLE TaskInfo ("
		"taskid VARCHAR(40) PRIMARY KEY, "
		"taskstatus INTEGER NOT NULL, "
		"priority INTEGER NOT NULL, "
		"processname VARCHAR(40) NOT NULL, "
		"samplecount INTEGER NOT NULL, "
		"curnode INTEGER NOT NULL, "
		"curnodename VARCHAR(40), "
		"curactiono INTEGER NOT NULL, "
		"nodestatus INTEGER NOT NULL, "
		"errno INTEGER NOT NULL,  "
		"createtime VARCHAR(40) NOT NULL, "
		"starttime VARCHAR(40), "
		"finishtime VARCHAR(40))");


	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create TaskInfo table failed";
		m_db.close();
		return false;
	}

	/* 样本源表 */
	bSuc = query.exec("CREATE TABLE SampleMetaData ("
		"taskid VARCHAR(40) NOT NULL, "
		"execorder INTEGER NOT NULL, "
		"testitem VARCHAR(40) NOT NULL, "
		"kitname VARCHAR(40) NOT NULL, "
		"sampletype INTEGER NOT NULL, "
		"samplestatus INTEGER NOT NULL, "
		"holeposition INTEGER NOT NULL, "
		"barcode VARCHAR(40) NOT NULL, "
		"createtime VARCHAR(40) NOT NULL, "
		"PRIMARY KEY (taskid, execorder))");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create SampleInfo table failed";
		m_db.close();
		return false;
	}

	/* 检测项目表 */
	bSuc = query.exec("CREATE TABLE TestItemInfo ("
		"testitem VARCHAR(40) NOT NULL, "
		"kitname VARCHAR(40) NOT NULL, "
		"templateid VARCHAR(40) NOT NULL, "
		"axeprocess VARCHAR(40) NOT NULL, "
		"pcrconfig VARCHAR(40) NOT NULL, "
		"modifytime VARCHAR(40) NOT NULL, "
		"PRIMARY KEY (testitem, templateid))");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create KitInfo table failed";
		m_db.close();
		return false;
	}

	/* 体系表 */
	bSuc = query.exec("CREATE TABLE KitInfo ("
		"templateid VARCHAR(40) NOT NULL, "
		"columnid INTEGER NOT NULL, "
		"kitname VARCHAR(40) NOT NULL, "
		"arow INTEGER NOT NULL, "
		"brow INTEGER NOT NULL, "
		"alot VARCHAR(40), "
		"blot VARCHAR(40), "
		"avolume INTEGER , "
		"bvolume INTEGER, "
		"modifytime VARCHAR(40) NOT NULL, "
		"PRIMARY KEY(templateid, columnid))");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create KitInfo table failed";
		m_db.close();
		return false;
	}

	/* 体系模板表 */
	bSuc = query.exec("CREATE TABLE KitTemplate ("
		"templateid VARCHAR(40) PRIMARY KEY, "
		"defaulttemp INTEGER NOT NULL, "
		"templatename VARCHAR(40) NOT NULL, "
		"username VARCHAR(40) NOT NULL, "
		"modifytime VARCHAR(40) NOT NULL)");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create KitInfo table failed";
		m_db.close();
		return false;
	}

	/* 样本表 */
	bSuc = query.exec("CREATE TABLE SampleInfo ("
		"sampleid VARCHAR(40) NOT NULL, "
		"sampletype INTEGER NOT NULL, "
		"samplestatus INTEGER NOT NULL, "
		"holeposition INTEGER NOT NULL, "
		"barcode VARCHAR(40) NOT NULL, "
		"createtime VARCHAR(40) NOT NULL, "
		"PRIMARY KEY (sampleid, holeposition))");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create SampleInfo table failed";
		m_db.close();
		return false;
	}

	/* 耗材使用记录表 */
	bSuc = query.exec("CREATE TABLE MaterialRecord ("
		"recordid INTERGER PRIMARY KEY, "
		"materialname VARCHAR(40) NOT NULL, "
		"usecount INTEGER NOT NULL, "
		"createtime VARCHAR(40) NOT NULL)");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create SampleInfo table failed";
		m_db.close();
		return false;
	}

	/* 设备表 */
	bSuc = query.exec("CREATE TABLE DeviceInfo ("
		"deviceid INTEGER PRIMARY KEY, "
		"devicetype INTEGER NOT NULL, "
		"devicename VARCHAR(64) NOT NULL, "
		"createtime VARCHAR(40) NOT NULL)");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create DeviceInfo table failed";
		m_db.close();
		return false;
	}

	/* 设备动作列表 */
	bSuc = query.exec("CREATE TABLE DeviceAction ("
		"deviceid INTEGER NOT NULL, "
		"actionid INTEGER NOT NULL, "
		"actionname VARCHAR(64) NOT NULL, "
		"subprocessid INTEGER, "
		"paramtext VARCHAR(128), "
		"PRIMARY KEY (deviceid, actionid))");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create DeviceAction table failed";
		m_db.close();
		return false;
	}

	/* 特定动作表 */
	bSuc = query.exec("CREATE TABLE ActionInfo ("
		"motionid INTEGER PRIMARY KEY, "
		"deviceid INTEGER NOT NULL, "
		"devicename VARCHAR(64) NOT NULL, "
		"actionid INTEGER NOT NULL, "
		"actionname VARCHAR(64) NOT NULL, "
		"subprocessid INTEGER NOT NULL, "
		"subprocessname VARCHAR(64) NOT NULL, "
		"paraminfo VARCHAR(128), "
		"execorder INTEGER NOT NULL)");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create ActionInfo table failed";
		m_db.close();
		return false;
	}

	/* 子流程表 */
	bSuc = query.exec("CREATE TABLE SubProcessInfo ("
		"subprocessid INTEGER PRIMARY KEY, "
		"subprocessname VARCHAR(64) NOT NULL, "
		"motioncount INTEGER NOT NULL, "
		"createtime VARCHAR(40) NOT NULL)");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create SubProcessInfo table failed";
		m_db.close();
		return false;
	}

	/* 流程表 */
	bSuc = query.exec("CREATE TABLE ProcessInfo ("
		"processid INTEGER PRIMARY KEY, "
		"processname VARCHAR(64) NOT NULL, "
		"subprocesscount INTEGER NOT NULL, "
		"subprocessidlist VARCHAR(64) NOT NULL, "
		"createtime VARCHAR(40) NOT NULL)");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create SubProcessInfo table failed";
		m_db.close();
		return false;
	}

	/* 坐标别名 */
	bSuc = query.exec("CREATE TABLE CoordinateRecord ("
		"coorname VARCHAR(64) PRIMARY KEY, "
		"xval INTEGER NOT NULL, "
		"yval INTEGER NOT NULL, "
		"zval INTEGER NOT NULL)");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create SubProcessInfo table failed";
		m_db.close();
		return false;
	}

	/* 正在使用的耗材记录 */
	bSuc = query.exec("CREATE TABLE UsingMaterial ("
		"materialname VARCHAR(64) PRIMARY KEY, "
		"row INTEGER NOT NULL, "
		"column INTEGER NOT NULL, "
		"currow INTEGER NOT NULL, "
		"curcolumn INTEGER NOT NULL, "
		"modifytime VARCHAR(40))");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create SubProcessInfo table failed";
		m_db.close();
		return false;
	}

	/* 用户表 */
	bSuc = query.exec("CREATE TABLE UserInfo ("
		"userid INTEGER PRIMARY KEY autoincrement,"
		"username VARCHAR(40) NOT NULL UNIQUE, "
		"password VARCHAR(40) NOT NULL, "
		"createtime VARCHAR(40) NOT NULL default current_timestamp,"
		"lastlogintime VARCHAR(40), "
		"lastlogouttime VARCHAR(40), "
		"comment VARCHAR(40), "
		"authority INTEGER NOT NULL default 2) ");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create SubProcessInfo table failed";
		m_db.close();
		return false;
	}

	



	/* QPCR表 */
	bSuc = query.exec("CREATE TABLE QPCR_Info ("
		"taskid VARCHAR(40) PRIMARY KEY,"
		"taskstatus INTEGER NOT NULL, "
		"sampleid VARCHAR(40) NOT NULL, "
		"methodname VARCHAR(40) NOT NULL,"
		"holeposition INTEGER NOT NULL, "
		"kitname VARCHAR(40) NOT NULL, "
		"createtime VARCHAR(40) NOT NULL default current_timestamp,"
		"starttime VARCHAR(40), "
		"finishtime VARCHAR(40))");

	if (!bSuc)
	{
		//Log(Logger::HGT_STATUS, HGT::General) << "create SubProcessInfo table failed";
		m_db.close();
		return false;
	}
	
	m_db.close();

	return true;
}

int ConnectDatabase::getRowCounts(QString tableName)
{
	int count = 0;

	if (!m_db.open())
		return 0;

	QSqlQuery query(m_db);
	QString queryString = QString("SELECT count(*) FROM %1").arg(tableName);
	if (!query.exec(queryString))
	{
		qDebug() << query.lastError().text();
		return 0;
	}

	if (query.next())
		count = query.value(0).toInt();

	m_db.close();

	return count;
}

bool ConnectDatabase::execSQL(QString statement)
{
	QSqlQuery query(m_db);
	if (m_db.open()) {
		qDebug() << "open db";
		if (query.exec(statement))
		{
			m_db.close();
			return true;
		}
		else
		{
			qDebug() << "query fail " << query.lastError();
			m_db.close();
			return false;
		}
	}
	qDebug() << "db open fail";
	return false;
}
