# - Try to find libusb
# Once done this will define
#  LIBUSB_FOUND - system has libusb
#  LIBUSB_INCLUDE_DIR - the libusb include directory
#  LIBUSB_LIBRARIES - libusb library
#

# Find libusb header and library
find_path(LIBUSB_INCLUDE_DIR
	libusb-1.0/libusb.h
)

find_library(LIBUSB_LIBRARIES
	NAMES usb-1.0
)

# Give output, should this be wished (this handles also QUIET and REQUIRED
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(libusb DEFAULT_MSG LIBUSB_LIBRARIES LIBUSB_INCLUDE_DIR)
mark_as_advanced(LIBUSB_LIBRARIES)
mark_as_advanced(LIBUSB_INCLUDE_DIR)
