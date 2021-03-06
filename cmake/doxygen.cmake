include(FeatureSummary)
get_property(PKG_TYPES GLOBAL PROPERTY FeatureSummary_PKG_TYPES)
list(FIND PKG_TYPES "BUILD" BUILD_INDEX )
if(${BUILD_INDEX} EQUAL -1)
	set_property(GLOBAL APPEND PROPERTY FeatureSummary_PKG_TYPES BUILD)
endif()
find_package(Doxygen)
set_package_properties(Doxygen PROPERTIES
	DESCRIPTION "Source code documentation generator"
	URL "http://doxygen.org"
	TYPE BUILD
	PURPOSE "Generate source code documentation"
)

if(NOT DOXYGEN_GENERIC_DOXYFILE)
	set(DOXYGEN_GENERIC_DOXYFILE ${CMAKE_SOURCE_DIR}/doc/Doxyfile CACHE FILEPATH "Doxygen default doxyfile")
	mark_as_advanced(DOXYGEN_GENERIC_DOXYFILE)
endif()

if(NOT TARGET doc)
	add_custom_target(doc COMMENT "Generating documentation")
endif()

function(add_documentation TARGET)
	set(options)
	set(oneValueArgs
		DOXYFILE #Doxygen doxyfile
		PROJECT_NAME # Set project name for documentation. Default: ${PROJECT_NAME}
	)
	set(multiValueArgs)
	cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	if(DOXYGEN_FOUND)
		if(DOXYFILE)
			set(DOXYGEN_DOXYFILE ${ARG_DOXYFILE})
		else()
			set(DOXYGEN_DOXYFILE ${DOXYGEN_GENERIC_DOXYFILE})
		endif()

		if(ARG_PROJECT_NAME)
			set(DOXYGEN_PROJECT_NAME ${ARG_PROJECT_NAME})
		else()
			set(DOXYGEN_PROJECT_NAME ${PROJECT_NAME})
		endif()
		# Generate source file with full path
		get_target_property(TARGET_SOURCE_FILES ${TARGET} SOURCES)
		foreach(SOURCE_FILE ${TARGET_SOURCE_FILES})
			set(SOURCE_FILES "${SOURCE_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE}")
		endforeach()
		set(SOURCE_BASE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
		set(DOXYGEN_PROJECT_SOURCES ${SOURCE_FILES})

		set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/doc/${TARGET}/doxygen)
		set(OUTPUT_DOXYFILE ${DOXYGEN_OUTPUT_DIR}/doxyfile-${TARGET})

		configure_file(${DOXYGEN_DOXYFILE} ${OUTPUT_DOXYFILE} @ONLY)

		add_custom_target(doc-${TARGET}
			COMMAND ${DOXYGEN_EXECUTABLE} ${OUTPUT_DOXYFILE}
			COMMENT "Generating documentation for ${TARGET}"
		)

		add_dependencies(doc doc-${TARGET})
	endif()
endfunction()
