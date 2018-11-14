// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-


/*******************************************************************************
**      В модуле описываются классы для формирования логов
**
********************************************************************************/

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <sstream>
#include <exception>


#ifdef USE_QT4
#include <QtCore>
#elif USE_QT3
#include <qstring.h>
#include <qvariant.h>
#endif


/**
 * Поток для вывода отладочной информации
 *
**/
namespace eom {
class LoggerStream;
class NullLoggerStream;
typedef LoggerStream  & (*loggerstream_manipulator )(LoggerStream &);



/**
 * Функция для установки цвета
 *
**/
class colorM {
public:
    unsigned char color;

    colorM(unsigned char newColor);
};

/**
 * Манипулятор, обрывающий вывод и переводящий на новую строку
**/
LoggerStream  & endl(LoggerStream &);
NullLoggerStream  & endl(NullLoggerStream &);


class CLoggerStreamStaticImpl;
class  LoggerStream {
    friend class CLoggerStreamStaticImpl;
    friend LoggerStream  & endl(LoggerStream &);
public:

    //Уровень логирования
    enum LogLevel {
        LOG_TRACE   = 4,
        LOG_DEBUG1  = 3,
        LOG_INFO    = 2,
        LOG_WARNING = 1,
        LOG_ERROR   = 0,
        LOG_NOLOG   =-1
    };

    //функция выставляет уровень логирования при выводе на экран
    //Где-нить в main.cpp пишем LoggerStream::setLogLevel(LoggerStream::LOG_DEBUG1) и радуемся
    static void setLogLevel(LogLevel newLevel);

    //использовать блокировки при выводе из разных потоков. Следует вызывать строго до их создания
    static void setThreaded(bool threaded);

    static LogLevel getLogLevel();

    static LogLevel getFileLogLevel();

    static bool isThreaded();


#if defined(USE_QT4) || defined(USE_QT3)
    //функция задаёт уровень логирования для вывода в файл и сам файл
    static void setFileLogLevel(const QString & fileName, LogLevel fileLevel);
    //функция задаёт префикс, который будет писаться каждый раз перед текстом основного сообщения
    static void setLogPrefix(const QString & prefix);
    //функция задаёт кодировку с-строк
    static void setCStringEncoding(const char * encoding);
#else
    //функция задаёт уровень логирования для вывода в файл и сам файл
    static void setFileLogLevel(const std::string & fileName, LogLevel fileLevel);
    //функция задаёт префикс, который будет писаться каждый раз перед текстом основного сообщения
    static void setLogPrefix(const std::string & prefix);

#endif


    //функция выдаёт true, если данный уровень нуждается в логировании
    static bool isLevelLogged(LogLevel level);



    //функция преобразует код, принятый в файле настроек, в формат LogLevel
    static LogLevel fromSettings(int levelCode);

    //новая версия. Используем её
    LoggerStream (LogLevel level);

    ~LoggerStream();

    LoggerStream &  operator<<(char c);
    LoggerStream &  operator<<(unsigned char c);
    LoggerStream &  operator<<(signed char c);
    LoggerStream &  operator<<(const char *s);
    LoggerStream &  operator<<(const unsigned char *s);
    LoggerStream &  operator<<(const void *p) ;
    LoggerStream &  operator<<(int n);
    LoggerStream &  operator<<(unsigned int n);
    LoggerStream &  operator<<(long n);
    LoggerStream &  operator<<(unsigned long n);

    LoggerStream &  operator<<(long long n);
    LoggerStream &  operator<<(unsigned long long n);

    LoggerStream &  operator<<(short n);
    LoggerStream &  operator<<(unsigned short n);

    LoggerStream &  operator<<(bool b);

    LoggerStream &  operator<<(double n);
    LoggerStream &  operator<<(float n);

    LoggerStream &  operator << (long double n);
    LoggerStream &  operator << (const std::string & value);
#if defined(USE_QT4) || defined(USE_QT3)
    LoggerStream &  operator << (const QString & value);
    LoggerStream &  operator << (const QVariant & value);
#endif
    LoggerStream & operator << (loggerstream_manipulator func);

    //Функция для установки цвета...
    LoggerStream & operator << (const colorM &);

    LoggerStream & operator << (const std::exception & exception ) ;

private:
    LoggerStream  ( const LoggerStream &);
    LoggerStream & operator = (const LoggerStream &);

    bool isLocked;
    LogLevel level;
    bool log;
    bool writeToFile;
    QTextStream outStream;
    QTextStream fileStream;
protected:
    void writePrefixAndLock();

};


/**
 * Манипулятор, обрывающий вывод и переводящий на новую строку
**/
NullLoggerStream  & endl(NullLoggerStream &);
typedef NullLoggerStream  & (*nullloggerstream_manipulator )(NullLoggerStream &);

class  NullLoggerStream {
    friend NullLoggerStream & endl(NullLoggerStream &);
public:
    inline NullLoggerStream &  operator<<(char c) {return *this;};
    inline NullLoggerStream &  operator<<(unsigned char c) {return *this;};
    inline NullLoggerStream &  operator<<(signed char c) {return *this;};
    inline NullLoggerStream &  operator<<(const char *s) {return *this;};
    inline NullLoggerStream &  operator<<(const unsigned char *s) {return *this;};
    inline NullLoggerStream &  operator<<(const void *p)  {return *this;};
    inline NullLoggerStream &  operator<<(int n) {return *this;};
    inline NullLoggerStream &  operator<<(unsigned int n) {return *this;};
    inline NullLoggerStream &  operator<<(long n) {return *this;};
    inline NullLoggerStream &  operator<<(unsigned long n) {return *this;};

    inline NullLoggerStream &  operator<<(long long n) {return *this;};
    inline NullLoggerStream &  operator<<(unsigned long long n) {return *this;};

    inline NullLoggerStream &  operator<<(short n) {return *this;};
    inline NullLoggerStream &  operator<<(unsigned short n) {return *this;};

    inline NullLoggerStream &  operator<<(bool b) {return *this;};

    inline NullLoggerStream &  operator<<(double n) {return *this;};
    inline NullLoggerStream &  operator<<(float n) {return *this;};

    inline NullLoggerStream &  operator << (long double n) {return *this;};
    inline NullLoggerStream &  operator << (const std::string & value) {return *this;};
#if defined(USE_QT4) || defined(USE_QT3)
    inline NullLoggerStream &  operator << (const QString & value) {return *this;};
#endif
    inline NullLoggerStream & operator << (nullloggerstream_manipulator  func) {return *this;};

    //Функция для установки цвета...
    inline NullLoggerStream & operator << (const colorM &) {return *this;};

    inline NullLoggerStream & operator << (const std::exception & exception )  {return *this;};

    inline NullLoggerStream() {};
private:
    NullLoggerStream  ( const NullLoggerStream &);
    NullLoggerStream & operator = (const NullLoggerStream &);

};



std::string  getShortPathToFileWithLineNumberForLogXXXYYY (const char * fileName,const char * line, bool useLevelValue );
std::string  getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY (const char * funcName, const char * fileName,unsigned int line, bool useLevelValue );

};//namespace eom






#define EOM_FILE_AND_LINE  (eom::getShortPathToFileWithLineNumberForLogXXXYYY(__FILE__,__LINE__,false))
#define EOM_FILE_LINE_FUNCTION  (eom::getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY(__func__,__FILE__,__LINE__,false))



#ifdef DEVELOP_FLAGS
    #define EOM_LOG_TRACE (eom::LoggerStream(eom::LoggerStream::LOG_TRACE))
    #define EOM_LOG_DEBUG (eom::LoggerStream(eom::LoggerStream::LOG_DEBUG1))
    #define EOM_LOG_ERROR (eom::LoggerStream(eom::LoggerStream::LOG_ERROR))
    #define EOM_LOG_WARNING (eom::LoggerStream(eom::LoggerStream::LOG_WARNING))
    #define EOM_LOG_INFO (eom::LoggerStream(eom::LoggerStream::LOG_INFO))


    #define EOM_LOG_DEBUG_HERE (eom::LoggerStream(eom::LoggerStream::LOG_DEBUG1)<<eom::getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY(__FUNCTION__, __FILE__, __LINE__,true)<<" ")
    #define EOM_LOG_ERROR_HERE (eom::LoggerStream(eom::LoggerStream::LOG_ERROR)<<eom::getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY(__FUNCTION__, __FILE__, __LINE__,true)<<" ")
    #define EOM_LOG_WARNING_HERE (eom::LoggerStream(eom::LoggerStream::LOG_WARNING)<<eom::getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY(__FUNCTION__, __FILE__, __LINE__,true)<<" ")
    #define EOM_LOG_INFO_HERE (eom::LoggerStream(eom::LoggerStream::LOG_INFO)<<eom::getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY(__FUNCTION__, __FILE__, __LINE__,true)<<" ")


    #define EOM_LOG_TRACE_HERE (eom::LoggerStream(eom::LoggerStream::LOG_TRACE)<<eom::getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY(__FUNCTION__, __FILE__, __LINE__,true)<<" ")
#else
    #define EOM_LOG_TRACE (eom::LoggerStream(eom::LoggerStream::LOG_TRACE))
    #define EOM_LOG_DEBUG (eom::LoggerStream(eom::LoggerStream::LOG_DEBUG1))
    #define EOM_LOG_ERROR (eom::LoggerStream(eom::LoggerStream::LOG_ERROR))
    #define EOM_LOG_WARNING (eom::LoggerStream(eom::LoggerStream::LOG_WARNING))
    #define EOM_LOG_INFO (eom::LoggerStream(eom::LoggerStream::LOG_INFO))


    #define EOM_LOG_DEBUG_HERE (eom::LoggerStream(eom::LoggerStream::LOG_DEBUG1)<<eom::getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY(__FUNCTION__, __FILE__, __LINE__,true)<<" ")
    #define EOM_LOG_ERROR_HERE (eom::LoggerStream(eom::LoggerStream::LOG_ERROR)<<eom::getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY(__FUNCTION__, __FILE__, __LINE__,true)<<" ")
    #define EOM_LOG_WARNING_HERE (eom::LoggerStream(eom::LoggerStream::LOG_WARNING)<<eom::getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY(__FUNCTION__, __FILE__, __LINE__,true)<<" ")
    #define EOM_LOG_INFO_HERE (eom::LoggerStream(eom::LoggerStream::LOG_INFO)<<eom::getShortPathToFileWithLineNumberAndFunctionNameForLogXXXYYY(__FUNCTION__, __FILE__, __LINE__,true)<<" ")


    #define EOM_LOG_TRACE_HERE (eom::NullLoggerStream())
#endif



#endif
