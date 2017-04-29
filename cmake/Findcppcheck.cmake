#.rst:
# Findcppcheck
# -----------
#
# This module looks for cppcheck
#
# cppcheck is a static code analysis tool.  Please see http://cppcheck.sourceforge.net/
#
# This modules defines the following variables:
#
# ::
#
#    CPPCHECK_BIN       = The path to the doxygen command.
#    CPPCHECK_FOUND     = Was Doxygen found or not?
#    CPPCHECK_VERSION   = The version reported by doxygen --version
#

find_program(CPPCHECK_BIN
	NAMES cppcheck
	DOC "cppcheck binary file path"
)

if(CPPCHECK_BIN)
  execute_process(COMMAND ${CPPCHECK_BIN} "--version" OUTPUT_VARIABLE CPPCHECK_OUTPUT_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
  string(REGEX MATCH "[0-9]+[.].*" CPPCHECK_VERSION ${CPPCHECK_OUTPUT_VERSION})
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(cppcheck REQUIRED_VARS CPPCHECK_BIN VERSION_VAR CPPCHECK_VERSION)
mark_as_advanced(CPPCHECK_BIN)
