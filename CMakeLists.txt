cmake_minimum_required(VERSION 3.0)

project(libuma)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(style)
include(cppcheck)
include(doxygen)
include(FeatureSummary)
include(cflags)

# Set C standard level
add_cflag("-std=c11")

# Set FORITY cmake variable
set(FORTIFY ${FORTIFY} CACHE STRING "Set fortify source level. This can only be use with -O greater than 1. The value can be Empty to disable it, 1 for safe hardening and 2 for strongest hardening")


# Set default Warnings
add_cflag_if_supported("-Wall")
add_cflag_if_supported("-Wextra")
add_cflag_if_supported("-Wshadow")
add_cflag_if_supported("-fstrict-aliasing")
add_cflag_if_supported("-Wformat")
add_cflag_if_supported("-Wformat-security")
add_cflag_if_supported("-Wmaybe-uninitialized")
add_cflag_if_supported("-Wmissing-variable-declarations")
add_cflag_if_supported("-Wshorten-64-to-32")
add_cflag_if_supported("-Wimplicit-function-declaration")
add_cflag_if_supported("-Wredundant-decls")
add_cflag_if_supported("-Wno-missing-field-initializers")
add_cflag_if_supported("-Wundef")

# Set default optimizations
add_cflag_if_supported("-flto")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--no-add-needed -Wl,--as-needed -Wl,--no-undefined")
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-add-needed -Wl,--as-needed")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-add-needed -Wl,--as-needed")

# Basic hardening
if(FORTIFY)
	add_cflag_if_supported("-D_FORTIFY_SOURCE=${FORTIFY}")
endif()
add_cflag_if_supported("-fstack-protector-strong")
add_cflag_if_supported("-fpic")
add_cflag_if_supported("-Wstrictoverflow")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-z,relro -Wl,-z,now")
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,-z,relro -Wl,-z,now")

find_package(libusb 1.0 REQUIRED)
set_package_properties(libusb PROPERTIES
	DESCRIPTION "A cross-platform user library to access USB devices"
	URL "http://libusb.info/"
	PURPOSE "USB communication with mooltipass"
)

include_directories(include ${LIBUSB_INCLUDE_DIR})

add_custom_target(readme
	SOURCES readme.md
)

add_library(uma SHARED
	include/libuma/retcode.h
	include/libuma/usb/device_info.h
	include/libuma/usb/message.h

	src/usb/message.c

	# Commands
	include/libuma/command/type.h
	include/libuma/command/original.h
	include/libuma/command/utils.h

	src/command/utils.c
	src/command/original.c

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
add_documentation(uma)

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

feature_summary(
	WHAT ALL
)
