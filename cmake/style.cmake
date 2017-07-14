include(FeatureSummary)
get_property(PKG_TYPES GLOBAL PROPERTY FeatureSummary_PKG_TYPES)
list(FIND PKG_TYPES "BUILD" BUILD_INDEX )
if(${BUILD_INDEX} EQUAL -1)
	set_property(GLOBAL APPEND PROPERTY FeatureSummary_PKG_TYPES BUILD)
endif()
find_package(uncrustify)
set_package_properties(uncrustify PROPERTIES
	DESCRIPTION "A tool for checking code style"
	URL "https://github.com/uncrustify/uncrustify"
	TYPE BUILD
	PURPOSE "Code style enforcement"
)
	
function(validate_style TARGET_NAME)
	get_target_property(VAR ${TARGET_NAME} SOURCES)
	
	if(NOT UNCRUSTIFY_BIN)
		return()
	endif()

	foreach(SOURCE_FILE ${VAR})
		if(NOT TARGET style-check)
			add_custom_target(style-check COMMENT "Validate coding style")
		endif()
		if(NOT TARGET style-reflow)
			add_custom_target(style-reflow COMMENT "Validate coding style")
		endif()

		add_custom_command(TARGET style-check
			PRE_BUILD
			COMMAND ${UNCRUSTIFY_BIN} -c ${CMAKE_CURRENT_SOURCE_DIR}/style.conf --check -f ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE}
			COMMENT "Validate code style for ${SOURCE_FILE} "
		)
		add_custom_command(TARGET style-reflow
			PRE_BUILD
			COMMAND ${UNCRUSTIFY_BIN} -c ${CMAKE_CURRENT_SOURCE_DIR}/style.conf --no-backup ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE}
			COMMENT "Reflow code style for ${SOURCE_FILE} "
		)
	endforeach()
endfunction()
