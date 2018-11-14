
SET CMAKE="C:\Programmer\Cmake\bin\cmake.exe"
SET QTDIR=C:\Programmer\Qt5.6.2\5.6\msvc2013_64\
SET TARGET_CONF=DEVELOP

%CMAKE%  -G"Visual Studio 12 2013 Win64" -DTARGET_CONF=%TARGET_CONF% -DQTDIR=%QTDIR% -DBOOST_ROOT="C:/Programmer/boost" ../


