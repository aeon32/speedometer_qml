SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)




SET(CMAKE_LIBRARY_ARCHITECTURE arm-linux-gnueabihf)


SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE   armhf)
SET(CPACK_SYSTEM_NAME armhf)
SET(CPACK_DEBIAN_PACKAGE_DEPENDS "qml-module-qtquick-controls(>=5.3),libqt5network5(>=5.3) ")