
function(validate_style TARGET_NAME)
	get_target_property(VAR ${TARGET_NAME} SOURCES)

	foreach(SOURCE_FILE ${VAR})
		if(NOT TARGET style-check)
			add_custom_target(style-check COMMENT "Validate coding style")
		endif()
		if(NOT TARGET style-reflow)
			add_custom_target(style-reflow COMMENT "Validate coding style")
		endif()

		add_custom_command(TARGET style-check
			PRE_BUILD
			COMMAND uncrustify -c ${CMAKE_CURRENT_SOURCE_DIR}/style.conf --check -f ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE}
			COMMENT "Validate code style for ${SOURCE_FILE} "
		)
		add_custom_command(TARGET style-reflow
			PRE_BUILD
			COMMAND uncrustify -c ${CMAKE_CURRENT_SOURCE_DIR}/style.conf --no-backup ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE}
			COMMENT "Reflow code style for ${SOURCE_FILE} "
		)
	endforeach()
endfunction()
