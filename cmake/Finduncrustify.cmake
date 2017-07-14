#.rst:
# Finduncrustify
# -----------
#
# This module looks for uncrustify
#
# uncrustify is a static code analysis tool.  Please see http://uncrustify.sourceforge.net/
#
# This modules defines the following variables:
#
# ::
#
#    UNCRUSTIFY_BIN       = The path to the doxygen command.
#    UNCRUSTIFY_FOUND     = Was Doxygen found or not?
#    UNCRUSTIFY_VERSION   = The version reported by doxygen --version
#

find_program(UNCRUSTIFY_BIN
	NAMES uncrustify
	DOC "uncrustify binary file path"
)

if(UNCRUSTIFY_BIN)
  execute_process(COMMAND ${UNCRUSTIFY_BIN} "--version" OUTPUT_VARIABLE UNCRUSTIFY_OUTPUT_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
  string(REGEX MATCH "[0-9]+[.][0-9]+([_].*)" UNCRUSTIFY_VERSION ${UNCRUSTIFY_OUTPUT_VERSION})
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(uncrustify REQUIRED_VARS UNCRUSTIFY_BIN VERSION_VAR UNCRUSTIFY_VERSION)
mark_as_advanced(UNCRUSTIFY_BIN)
