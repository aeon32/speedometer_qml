SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)
#set(CMAKE_SYSTEM_PROCESSOR arm)

SET (ROOT_PATH /mnt/pi)
SET (MYQTDIR /home/user/Qt5.11.3/5.11.3/gcc_64/)

# specify the cross compiler
#SET(CMAKE_C_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")
#SET(CMAKE_CXX_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")
#SET(CMAKE_C_COMPILER  /usr/bin/arm-linux-gnueabihf-gcc-5 )
#SET(CMAKE_CXX_COMPILER  /usr/bin/arm-linux-gnueabihf-g++-5 )


SET(CMAKE_C_COMPILER /home/user/projects/raspberry_tools/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER /home/user/projects/raspberry_tools/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++)


SET(CMAKE_LIBRARY_ARCHITECTURE arm-linux-gnueabihf)

SET(HOST_ARCHITECTURE x86_64-linux-gnu)

#SET(CMAKE_PREFIX_PATH /usr/lib/${HOST_ARCHITECTURE}/cmake;)
SET(MY_MOC ${MYQTDIR}/bin/moc)
SET(MY_UIC ${MYQTDIR}/bin/uic)
SET(MY_RCC ${MYQTDIR}/bin/rcc)




# where is the target environment 
SET(CMAKE_FIND_ROOT_PATH  ${ROOT_PATH})
SET(CMAKE_SYSROOT ${ROOT_PATH})
LINK_DIRECTORIES("${ROOT_PATH}/usr/lib" "${ROOT_PATH}/lib/${CMAKE_LIBRARY_ARCHITECTURE}" "${ROOT_PATH}/usr/lib/${CMAKE_LIBRARY_ARCHITECTURE}")

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#SET(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE NEVER)
#SET(CMAKE_EXE_LINKER_FLAGS "-Wl,--dynamic-linker=${ROOT_PATH}/lib/ld-linux.so.3")
SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE   armhf)
SET(CPACK_SYSTEM_NAME armhf)
SET(CPACK_DEBIAN_PACKAGE_DEPENDS "qml-module-qtquick-controls(>=5.3),libqt5network5(>=5.3) ")