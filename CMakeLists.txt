cmake_minimum_required(VERSION 3.0)

project(libuma)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(libusb REQUIRED)

include(style)
include(cppcheck)

include_directories(include ${LIBUSB_INCLUDE_DIR})

add_custom_target(readme
	SOURCES readme.md
)

add_library(uma SHARED
	include/libuma/retcode.h
	include/libuma/usb/device_info.h
	include/libuma/usb/message.h

	src/usb/message.c

	# base system
	src/retcode.c

	include/libuma/init.h
	src/init.c

	# Device
	include/libuma/device/type.h
	include/libuma/device/internal.h
	include/libuma/device/handler.h
	src/device/handler.c
	include/libuma/device/transfer.h
	src/device/transfer.c

	# USB
	include/libuma/usb/sync.h
	src/usb/sync.c
)

target_link_libraries(uma ${LIBUSB_LIBRARIES})
validate_style(uma)
validate_cppcheck(uma)


add_executable(mooltipass_list
	tools/list/main.c
)

target_link_libraries(mooltipass_list uma)
validate_style(mooltipass_list)
validate_cppcheck(mooltipass_list)

install(TARGETS mooltipass_list
	DESTINATION bin
)

add_executable(mooltipass_cmd
	tools/cmd/main.c
)

target_link_libraries(mooltipass_cmd uma)
validate_style(mooltipass_cmd)
validate_cppcheck(mooltipass_cmd)

install(TARGETS mooltipass_cmd
	DESTINATION bin
)
