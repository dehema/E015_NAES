#include "AXEMgr.h"


AXEMgr::AXEMgr()
{
	configFolderPath = QCoreApplication::applicationDirPath() + "/Solution/AXE/ProcessInfo/";
	magnetSpeedStr.append(GetLang("1708420098"));
	magnetSpeedStr.append(GetLang("1708420097"));
	magnetSpeedStr.append(GetLang("1708420096"));
}

AXEMgr::~AXEMgr()
{
}

AXEProcessData AXEMgr::getProcessByName(QString _processName)
{
	AXEProcessData processData;
	QString path = configFolderPath + _processName + ".json";
	QFile file(path);
	if (!file.exists())
		return processData;
	if (file.open(QFile::ReadOnly))
	{
		return getPrecessByByte(file.readAll());
	}
	return processData;
}

QString AXEMgr::getStepJsonStr(AXEStepData _stepData)
{
	QJsonObject obj_root;
	obj_root.insert("stepIndex", _stepData.stepIndex);
	obj_root.insert("column", _stepData.column);
	obj_root.insert("stepName", _stepData.stepName);
	obj_root.insert("waitTime", _stepData.waitTime);
	obj_root.insert("mixTime", _stepData.mixTime);
	obj_root.insert("mixSpeed", _stepData.mixSpeed);
	obj_root.insert("magnetTime", _stepData.magnetTime);
	obj_root.insert("magnetSpeed", _stepData.magnetSpeed);
	obj_root.insert("volume", _stepData.volume);
	obj_root.insert("mixPos", _stepData.mixPos);
	obj_root.insert("mixAmplitude", _stepData.mixAmplitude);
	obj_root.insert("adsorbPosition", _stepData.adsorbPosition);
	obj_root.insert("heatStatus", _stepData.heatStatus);
	obj_root.insert("targetTemp", _stepData.targetTemp);
	QJsonDocument doc(obj_root);
	QString jsonStr = doc.toJson();
	return jsonStr;
}

QJsonArray AXEMgr::getStepJsonArray(QList<AXEStepData> _stepList)
{
	QJsonArray arraySpool;
	for (AXEStepData _stepData : _stepList)
	{
		QJsonObject objSpool;
		objSpool.insert("stepIndex", _stepData.stepIndex);
		objSpool.insert("column", _stepData.column);
		objSpool.insert("stepName", _stepData.stepName);
		objSpool.insert("waitTime", _stepData.waitTime);
		objSpool.insert("mixTime", _stepData.mixTime);
		objSpool.insert("mixSpeed", _stepData.mixSpeed);
		objSpool.insert("magnetTime", _stepData.magnetTime);
		objSpool.insert("magnetSpeed", _stepData.magnetSpeed);
		objSpool.insert("volume", _stepData.volume);
		objSpool.insert("mixPos", _stepData.mixPos);
		objSpool.insert("mixAmplitude", _stepData.mixAmplitude);
		objSpool.insert("adsorbPosition", _stepData.adsorbPosition);
		objSpool.insert("heatStatus", _stepData.heatStatus);
		objSpool.insert("targetTemp", _stepData.targetTemp);
		arraySpool.append(objSpool);
	}
	return arraySpool;
}

QList<AXEStepData> AXEMgr::getStepModelsByValue(QJsonValue _jsonValue)
{
	QList<AXEStepData> list;
	QJsonArray contentArray = _jsonValue.toArray();
	for (int i = 0; i < contentArray.count(); i++)
	{
		AXEStepData stepData;
		QJsonObject obj = contentArray[i].toObject();
		stepData.stepIndex = obj.take("stepIndex").toInt();
		stepData.column = obj.take("column").toInt();
		stepData.stepName = obj.take("stepName").toString();
		stepData.waitTime = obj.take("waitTime").toInt();
		stepData.mixTime = obj.take("mixTime").toInt();
		stepData.mixSpeed = obj.take("mixSpeed").toInt();
		stepData.magnetTime = obj.take("magnetTime").toInt();
		stepData.magnetSpeed = obj.take("magnetSpeed").toInt();
		stepData.volume = obj.take("volume").toInt();
		stepData.mixPos = obj.take("mixPos").toInt();
		stepData.mixAmplitude = obj.take("mixAmplitude").toInt();
		stepData.adsorbPosition = obj.take("adsorbPosition").toInt();
		stepData.heatStatus = obj.take("heatStatus").toInt();
		stepData.targetTemp = obj.take("targetTemp").toInt();
		list.append(stepData);
	}
	return list;
}

AXEProcessData AXEMgr::getPrecessByByte(QByteArray _byteArray)
{
	AXEProcessData processData;
	QJsonDocument jsonDocu = QJsonDocument::fromJson(_byteArray.toStdString().data());
	if (jsonDocu.isObject())
	{
		QJsonObject obj_root = jsonDocu.object();
		processData.processName = obj_root.value("processName").toString();
		processData.stepCount = obj_root.value("stepCount").toInt();
		processData.duration = obj_root.value("duration").toInt();
		processData.volumeProteaseK = obj_root.value("volumeProteaseK").toInt();
		processData.volumeSample = obj_root.value("volumeSample").toInt();
		processData.isPublish = obj_root.value("isPublish").toBool();
		processData.createDate = obj_root.value("createDate").toInt();
		processData.stepsList = getStepModelsByValue(obj_root.value("stepsParamList"));
	}
	return processData;
}

QString AXEMgr::getPrecessJsonStr(AXEProcessData _processData)
{
	QJsonObject obj_root;
	obj_root.insert("processName", _processData.processName);
	obj_root.insert("stepCount", _processData.stepCount);
	obj_root.insert("duration", _processData.duration);
	obj_root.insert("volumeProteaseK", _processData.volumeProteaseK);
	obj_root.insert("volumeSample", _processData.volumeSample);
	obj_root.insert("isPublish", _processData.isPublish);
	obj_root.insert("createDate", _processData.createDate);
	obj_root.insert("stepsParamList", getStepJsonArray(_processData.stepsList));
	QJsonDocument doc(obj_root);
	QString jsonStr = doc.toJson();
	return jsonStr;
}

QList<QString> AXEMgr::checkKitTips(AXEProcessData _processModel)
{
	QList<QString> tipsList = QList<QString>();
	if (_processModel.processName.isEmpty())
	{
		tipsList.append(GetLang("1708420481"));
	}
	return tipsList;
}

QString AXEMgr::getMagnetSpeedStr(int _speed)
{
	switch (_speed)
	{
	case 1:
	default:
		return GetLang("1708420098");
	case 2:
		return GetLang("1708420097");
	case 3:
		return GetLang("1708420096");
		break;
	}
}

QList<AXEProcessData> AXEMgr::getAllProcess()
{
	QList<AXEProcessData> dataList = {};
	QDir dir(AXEMgr::ins().configFolderPath);
	dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
	dir.setSorting(QDir::DirsFirst);
	QFileInfoList list = dir.entryInfoList();
	for (int i = 0; i < list.count(); ++i) {
		QFileInfo fileInfo = list.at(i);
		QString suffix = fileInfo.suffix();
		QString path = fileInfo.absoluteFilePath();
		if (suffix == "json")
		{
			QFile file(path);
			if (file.open(QFile::ReadOnly))
			{
				QByteArray byteArray = file.readAll();
				file.close();
				AXEProcessData data = AXEMgr::ins().getPrecessByByte(byteArray);
				dataList.append(data);
			}
		}
	}
	return dataList;
}

QList<QString> AXEMgr::getAllProcessNames()
{
	QList<QString> strList = {};
	QDir dir(AXEMgr::ins().configFolderPath);
	dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
	dir.setSorting(QDir::DirsFirst);
	QFileInfoList list = dir.entryInfoList();
	for (int i = 0; i < list.count(); ++i) {
		QFileInfo fileInfo = list.at(i);
		QString suffix = fileInfo.suffix();
		QString path = fileInfo.absoluteFilePath();
		if (suffix == "json")
		{
			strList.append(fileInfo.baseName());
		}
	}
	return strList;
}
