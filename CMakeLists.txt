cmake_minimum_required(VERSION 3.0)

project(libuma)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(libusb REQUIRED)

include(style)
include(cppcheck)

include_directories(include ${LIBUSB_INCLUDE_DIR})

add_library(uma SHARED
	include/libuma/retcode.h
	include/libuma/usb/device_info.h
	include/libuma/usb/message.h

	src/usb/message.c

	# base system
	src/retcode.c

	include/libuma/init.h
	src/init.c
)

target_link_libraries(uma ${LIBUSB_LIBRARIES})
validate_style(uma)
validate_cppcheck(uma)
