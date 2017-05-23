include(FeatureSummary)
get_property(PKG_TYPES GLOBAL PROPERTY FeatureSummary_PKG_TYPES)
list(FIND PKG_TYPES "BUILD" BUILD_INDEX )
if(${BUILD_INDEX} EQUAL -1)
	set_property(GLOBAL APPEND PROPERTY FeatureSummary_PKG_TYPES BUILD)
endif()
find_package(cppcheck)
set_package_properties(cppcheck PROPERTIES
	DESCRIPTION "A tool for static C/C++ code analysis"
	URL "http://cppcheck.sourceforge.net/"
	TYPE BUILD
	PURPOSE "Code analysis and error reporting"
)

option(CPPCHECK_VALIDATE_CONFIG "Have cppcheck check the configuration" OFF)
option(CPPCHECK_VALIDATE_LIBRARY "Have cppcheck check the library configuration" OFF)

function(validate_cppcheck TARGET_NAME)
	set(options
		# No options
	)
	set(oneValueArgs
		LIBRARY_CFG
	)
	set(multiValueArgs
		# No multivalue parameter
	)
	cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	if(NOT CPPCHECK_BIN)
		return()
	endif()

	if(NOT TARGET cppcheck)
		add_custom_target(cppcheck COMMENT "Validate targets against cppcheck")
	endif()

	# Generate source file with full path
	get_target_property(TARGET_SOURCE_FILES ${TARGET_NAME} SOURCES)
	foreach(SOURCE_FILE ${TARGET_SOURCE_FILES})
		list(APPEND SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE}")
	endforeach()

	# Add library support
	if(ARG_LIBRARY_CFG)
		set(LIBRARY_OPTION "--library=${ARG_LIBRARY_CFG}")
	endif()

	# Add checkconfig option is specified
	if(CPPCHECK_VALIDATE_CONFIG)
		set(CHECKCONFIG_OPTION ${CHECKCONFIG_OPTION} --check-config)
	endif()
	if(CPPCHECK_VALIDATE_LIBRARY)
		set(CHECKCONFIG_OPTION ${CHECKCONFIG_OPTION} --check-library)
	endif()

	# Define checks (validators)
	if(CPPCHECK_VALIDATOR)
		set(VALIDATORS "${CPPCHECK_VALIDATOR}")
	else()
		set(VALIDATORS "all")
	endif()

	# Define cppcheck target
	add_custom_target(cppcheck_${TARGET_NAME}
		COMMENT "Running cppcheck for ${TARGET_NAME} source files"
		COMMAND ${CPPCHECK_BIN}
			--enable="${VALIDATORS}"
			--std=c++11
			${LIBRARY_OPTION}
			--template='[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)'
			${CHECKCONFIG_OPTION}
			${SOURCE_FILES}
	)

endfunction()
