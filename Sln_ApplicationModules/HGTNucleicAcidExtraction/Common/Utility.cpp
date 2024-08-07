#include "Utility.h"


QString Utility::loadStyleFile()
{
	QString path = QCoreApplication::applicationDirPath() + "/qss/qss_mainView.qss";
	QFile qss(path);
	if (!qss.exists())
	{
		Log("读取失败");
		return QString();
	}
	qss.open(QFile::ReadOnly);
	QString str = qss.readAll();
	qss.close();
	return str;
}

void Utility::loadLangFile(int _langType)
{
	auto loadFile = [this](QString _fileName) {
		QString path = QCoreApplication::applicationDirPath() + "/lang/%1.json";
		path = path.arg(_fileName);
		QFile langFile(path);
		if (!langFile.exists())
			return;
		Log(QString::fromLocal8Bit("读取语言文件") + path);
		langFile.open(QFile::ReadOnly);
		QString str = langFile.readAll();
		langFile.close();
		QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
		if (jsonDoc.isObject())
		{
			QJsonObject jsonObj = jsonDoc.object();
			for (QString key : jsonObj.keys())
			{
				langDict[key] = jsonObj.take(key).toString();
			}
		}
	};
	langDict.clear();
	langType = (LangType)_langType;
	switch (langType)
	{
	case LangType::CN:
	{
		loadFile("cn");
		break;
	}
	case LangType::EN:
	{
		loadFile("en");
		break;
	}
	}
}

QString Utility::getLang(QString _id)
{
	if (langDict.contains(_id))
		return langDict[_id];
	return _id;
}

QString Utility::getLang(const char* _id)
{
	if (langDict.contains(_id))
		return langDict[_id];
	QString str = QString::fromLocal8Bit(_id);
	if (langDict.contains(str))
	{
		QString res = langDict[str];
		return res;
	}
	return _id;
}

bool Utility::isChineseUTF8(const char* str) {
	while (*str) {
		unsigned char ch = static_cast<unsigned char>(*str);
		// 检查是否是中文字符的开头字节（0xE4-0xE9）
		if (ch >= 0xE4 && ch <= 0xE9) {
			return true;
		}
		++str;
	}
	return false;
}

QMap<QString, QString> Utility::getDiagramFuncNames()
{
	QMap<QString, QString> map;
	map["getFuncTrue"] = "1708420189";
	return map;
}

bool Utility::getFuncTrue()
{
	return true;
}

QDate Utility::stringToDate(QString str)
{
	QStringList strList = str.split("-");
	if (strList.count() != 3)
	{
		return QDate::currentDate();
	}
	return QDate(strList[0].toInt(), strList[1].toInt(), strList[2].toInt());
}

QString Utility::dateToString(QDate _date)
{
	return _date.toString("yyyy-MM-dd");
}

QString Utility::secondToString(int _second)
{
	int min = qFloor(_second / 60.0f);
	int sec = _second % 60;
	QString minStr = QString::number(min).rightJustified(2, '0');
	QString secStr = QString::number(sec).rightJustified(2, '0');
	return minStr + ":" + secStr;
}

QString Utility::secondToMinute(int _second)
{
	int min = qCeil(_second / 60.0f);
	QString str = GetLang("1708430045").arg(min);
	return str;
}
