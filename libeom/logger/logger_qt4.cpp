// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-

#include "logger.h"
#include <qmutex.h>
#include <qfileinfo.h>
#include <qdir.h>
#include <iostream>
#include <fstream>




namespace eom {
/***********************************************************************************************
**                               Реализация CLogger
**
************************************************************************************************/
class CLoggerStreamStaticImpl {
public:
    QMutex mutex;
    //уровень логирования при выводе на экран
    LoggerStream::LogLevel currentLogLevel;
    //уровень логирования при выводе в файл
    LoggerStream::LogLevel fileLogLevel;
    //имя файла - лога
    QString fileLogName;
    //
    QFile fileLogFile;
    QTextStream fileLog;


    //префикс
    QString prefix;

    QTextStream  myCout;
    QTextStream  myCerr;

    QTextCodec * cStringCodec;

    bool threaded;





    CLoggerStreamStaticImpl():
        mutex(QMutex::Recursive),threaded(false), myCout(stdout, QIODevice::WriteOnly),
        myCerr(stderr,QIODevice::WriteOnly), fileLog(&fileLogFile), cStringCodec(NULL){

        currentLogLevel = LoggerStream::LOG_TRACE;
        fileLogLevel = LoggerStream::LOG_NOLOG;



    };

    ~CLoggerStreamStaticImpl() {

    };

    void lock() {
        if (threaded)
            mutex.lock();
    };

    void unlock() {
        if (threaded)
            mutex.unlock();
    };

    void setCStringEncoding(const char * encoding) {
        QTextCodec * codec = QTextCodec::codecForName(encoding);
        if (codec) {
            cStringCodec = codec;
        };

    };

};


CLoggerStreamStaticImpl logStaticData;


LoggerStream & endl(LoggerStream & outs) {
    if (outs.log)
        if (outs.level==LoggerStream::LOG_ERROR || outs.level==LoggerStream::LOG_WARNING )
            logStaticData.myCerr<<::endl;
        else
            logStaticData.myCout<<::endl;
    if (outs.writeToFile)
        logStaticData.fileLog<<::endl;

    if (outs.isLocked) {
        outs.isLocked = false;
        logStaticData.unlock();
    };
    return outs;
};


NullLoggerStream & endl(NullLoggerStream & outs) {
	return outs;
};


LoggerStream & colorL(LoggerStream & outs) {
	return outs;
};


LoggerStream::LoggerStream(LoggerStream::LogLevel level):isLocked(false),level(level) {
    log = (level <= logStaticData.currentLogLevel) && (level!=LOG_NOLOG);
    writeToFile = (level<=logStaticData.fileLogLevel) && (level != LOG_NOLOG);

};

LoggerStream::~LoggerStream() {
    if (isLocked)
        logStaticData.unlock();

};


LoggerStream &  LoggerStream::operator<<(char c) {
    if (!isLocked)
        logStaticData.lock();
    isLocked = true;
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<c;
        else
            logStaticData.myCout<<c;
    if (writeToFile)
        logStaticData.fileLog<<c;
    return *this;
};


void LoggerStream::writePrefixAndLock() {
    if (!isLocked) {
        logStaticData.lock();
        writeToFile = writeToFile && logStaticData.fileLogFile.isOpen();
        if (!logStaticData.prefix.isEmpty()) {
            if (log)
                if (level==LOG_ERROR || level==LOG_WARNING)
                    logStaticData.myCerr<<logStaticData.prefix;
                else
                    logStaticData.myCout<<logStaticData.prefix;
            if (writeToFile)
                logStaticData.fileLog<<logStaticData.prefix;

        };
        isLocked = true;
    };
    isLocked = true;

};

LoggerStream &  LoggerStream::operator<<(unsigned char c) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<c;
        else
            logStaticData.myCout<<c;
    if (writeToFile)
        logStaticData.fileLog<<c;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(signed char c) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<c;
        else
            logStaticData.myCout<<c;
    if (writeToFile)
        logStaticData.fileLog<<c;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(const char *s) {
    writePrefixAndLock();
    if (logStaticData.cStringCodec && (log || writeToFile)) {
        QString aux = logStaticData.cStringCodec->toUnicode(s);
        if (log)
            if (level==LOG_ERROR || level==LOG_WARNING)
                logStaticData.myCerr<<aux;
            else
                logStaticData.myCout<<aux;
        if (writeToFile)
            logStaticData.fileLog<<aux;

    } else {
        if (log)
            if (level==LOG_ERROR || level==LOG_WARNING)
                logStaticData.myCerr<<QString(s);
            else
                logStaticData.myCout<<QString(s);
        if (writeToFile)
            logStaticData.fileLog<<QString(s);

    };


    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(const unsigned char *s) {
    writePrefixAndLock();
    if (logStaticData.cStringCodec && (log || writeToFile)) {
        QString aux = logStaticData.cStringCodec->toUnicode((const char *) (s));
        if (log)
            if (level==LOG_ERROR || level==LOG_WARNING)
                logStaticData.myCerr<<aux;
            else
                logStaticData.myCout<<aux;
        if (writeToFile)
            logStaticData.fileLog<<aux;

    } else {
        if (log)
            if (level==LOG_ERROR || level==LOG_WARNING)
                logStaticData.myCerr<<s;
            else
                logStaticData.myCout<<s;
        if (writeToFile)
            logStaticData.fileLog<<s;

    };


    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(const void *p)  {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<p;
        else
            logStaticData.myCout<<p;
    if (writeToFile)
        logStaticData.fileLog<<p;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(int n) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<n;
        else
            logStaticData.myCout<<n;
    if (writeToFile)
        logStaticData.fileLog<<n;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(unsigned int n) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<n;
        else
            logStaticData.myCout<<n;
    if (writeToFile)
        logStaticData.fileLog<<n;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(long n) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<n;
        else
            logStaticData.myCout<<n;
    if (writeToFile)
        logStaticData.fileLog<<n;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(unsigned long n) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<n;
        else
            logStaticData.myCout<<n;
    if (writeToFile)
        logStaticData.fileLog<<n;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(long long n) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<n;
        else
            logStaticData.myCout<<n;
    if (writeToFile)
        logStaticData.fileLog<<n;
    isLocked = true;
    return *this;
};


LoggerStream &  LoggerStream::operator<<(unsigned long long n) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<n;
        else
            logStaticData.myCout<<n;
    if (writeToFile)
        logStaticData.fileLog<<n;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(short n) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<n;
        else
            logStaticData.myCout<<n;
    if (writeToFile)
        logStaticData.fileLog<<n;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(unsigned short n) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<n;
        else
            logStaticData.myCout<<n;
    if (writeToFile)
        logStaticData.fileLog<<n;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(bool b) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<b;
        else
            logStaticData.myCout<<b;
    if (writeToFile)
        logStaticData.fileLog<<b;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(double n) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<n;
        else
            logStaticData.myCout<<n;
    if (writeToFile)
        logStaticData.fileLog<<n;
    isLocked = true;
    return *this;
};

LoggerStream &  LoggerStream::operator<<(float n) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<n;
        else
            logStaticData.myCout<<n;
    if (writeToFile)
        logStaticData.fileLog<<n;
    isLocked = true;
    return *this;
};


LoggerStream &  LoggerStream::operator << (const std::string & value) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<QString::fromStdString(value);
        else
            logStaticData.myCout<<QString::fromStdString(value);
    if (writeToFile)
        logStaticData.fileLog<<QString::fromStdString(value);
    isLocked = true;
    return *this;
};


LoggerStream &  LoggerStream::operator << (const QString & value) {
    if (value.isEmpty())
        return * this;
    if (!isLocked)
        logStaticData.lock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<value;
        else
            logStaticData.myCout<<value;
    if (writeToFile)
        logStaticData.fileLog<<value;
    isLocked = true;
    return *this;

};

LoggerStream &  LoggerStream::operator << (const QVariant & value) {
    QString strValue;
    if (!isLocked)
        logStaticData.lock();
    if (log || writeToFile) {
        strValue = value.isNull() ? QString("null") : value.toString();
        if (strValue.isEmpty()) return *this;
    };

    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<strValue;
        else
            logStaticData.myCout<<strValue;
    if (writeToFile)
        logStaticData.fileLog<<strValue;
    isLocked = true;
    return *this;


};


LoggerStream & LoggerStream::operator << (loggerstream_manipulator func) {
    func(*this);
    return *this;
};

//Функция для установки цвета...
LoggerStream & LoggerStream::operator << (const colorM &) {
	return *this;
};

LoggerStream & LoggerStream::operator << (const std::exception & exception ) {
    writePrefixAndLock();
    if (log)
        if (level==LOG_ERROR || level==LOG_WARNING)
            logStaticData.myCerr<<exception.what();
        else
            logStaticData.myCout<<exception.what();
    if (writeToFile)
        logStaticData.fileLog<<exception.what();
    isLocked = true;
    return *this;

};



void LoggerStream::setLogLevel(LoggerStream::LogLevel newLogLevel) {
    logStaticData.lock();
    logStaticData.currentLogLevel = newLogLevel;
    logStaticData.unlock();
};

void LoggerStream::setFileLogLevel(const QString & fileName, LoggerStream::LogLevel fileLevel) {
    logStaticData.lock();
    if (fileLevel == LOG_NOLOG) {
        if (logStaticData.fileLogFile.isOpen()) {
            logStaticData.fileLog.flush();
            logStaticData.fileLogFile.close();

        };
        logStaticData.fileLogName = QString::null;
    } else {
        if ( logStaticData.fileLogName!= fileName || !logStaticData.fileLogFile.isOpen()) {
            logStaticData.fileLog.flush();
            if (logStaticData.fileLogFile.isOpen())
                logStaticData.fileLogFile.close();
            //создаём каталог (если он не существует)
            QFileInfo info (fileName);
            QDir rootDir("/");

            bool createDir  = rootDir.mkpath(info.canonicalPath());

            if (createDir) {
                logStaticData.fileLogFile.setFileName(fileName);
                logStaticData.fileLogFile.open(QIODevice::WriteOnly);
            };
            if (!logStaticData.fileLogFile.isOpen()) {
                logStaticData.myCerr<< (QString("Cannot open log file ") + fileName + (" for writing")) <<::endl;
            };
        };
    };
    logStaticData.fileLogLevel = fileLevel;
    logStaticData.unlock();
};



std::string getShortPathToFileWithLineNumberForLogXXXYYY(const char * file,unsigned int line, bool useLevelValue) {

    if (!useLevelValue || (logStaticData.currentLogLevel>=LoggerStream::LOG_TRACE) || (logStaticData.currentLogLevel>=LoggerStream::LOG_TRACE)) {
        std::string res(file);
        size_t lastSlash = res.find_last_of('/');
        if (lastSlash != std::string::npos)
            res = res.substr(lastSlash+1, res.length()-lastSlash-1);


        std::ostringstream outputStream;
        outputStream << res<< ":" <<line;
        return outputStream.str();

    } else {
        return std::string();
    };

};

std::string  getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY (const char * funcName, const char * fileName,unsigned int line, bool useLevelValue ) {
    if (!useLevelValue || (logStaticData.currentLogLevel>=LoggerStream::LOG_TRACE) || (logStaticData.fileLogLevel>=LoggerStream::LOG_TRACE)) {
        std::string res(fileName);
        size_t lastSlash = res.find_last_of('/');
        if (lastSlash != std::string::npos)
            res = res.substr(lastSlash+1, res.length()-lastSlash-1);


        std::ostringstream outputStream;
        outputStream << res<< ":" <<funcName<<":"<<line;
        return outputStream.str();
    } else {
        return std::string();
    };

};



LoggerStream::LogLevel LoggerStream::fromSettings(int logLevel) {
    LogLevel level;
    switch (logLevel) {
    case 0:
        level = LoggerStream::LOG_NOLOG;
        break;
    case 1:
        level = LoggerStream::LOG_ERROR;
        break;
    case 2:
        level = LoggerStream::LOG_WARNING;
        break;
    case 3:
        level = LoggerStream::LOG_INFO;
        break;
    case 4:
        level = LoggerStream::LOG_DEBUG1;
        break;
    case 5:
        level = LoggerStream::LOG_TRACE;
        break;
    default:
        level = LoggerStream::LOG_ERROR;
        break;
    };
    return level;
};


bool LoggerStream::isLevelLogged(LogLevel level) {
    logStaticData.lock();
    bool log = (level <= logStaticData.currentLogLevel) && (level!=LOG_NOLOG);
    bool writeToFile = (level<=logStaticData.fileLogLevel) && (level != LOG_NOLOG);
    logStaticData.unlock();
    return log && writeToFile;

};

void LoggerStream::setLogPrefix(const QString & prefix) {
    logStaticData.lock();
    logStaticData.prefix = prefix;
    logStaticData.unlock();
};

void LoggerStream::setThreaded(bool threaded) {
    logStaticData.threaded = threaded;
};

bool LoggerStream::isThreaded() {
    return logStaticData.threaded;
};

LoggerStream::LogLevel LoggerStream::getLogLevel() {
    return logStaticData.currentLogLevel;

};
LoggerStream::LogLevel LoggerStream::getFileLogLevel() {
    return logStaticData.fileLogLevel;
};

void LoggerStream::setCStringEncoding(const char * encoding) {
    logStaticData.lock();

    logStaticData.setCStringEncoding(encoding);
    logStaticData.unlock();
};

};

