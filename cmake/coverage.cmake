find_program(GCOV_EXECUTABLE NAMES gcov)
find_program(LCOV_EXECUTABLE NAMES lcov)
find_program(GENHTML_EXECUTABLE NAMES genhtml)
find_program(GGCOVR_EXECUTABLE NAMES gcovr PATHS ${CMAKE_SOURCE_DIR}/tests)
find_program(KCOV_EXECUTABLE NAMES gcovr PATHS ${CMAKE_SOURCE_DIR}/tests)


function(analyze_coverage TARGET_NAME)
	set_target_properties(${TARGET_NAME}
		PROPERTIES
			COMPILE_FLAGS "-O0 -g -fprofile-arcs -ftest-coverage"
			LINK_FLAGS "-lgcov -fprofile-arcs -ftest-coverage"
	)
endfunction()

function(analyze_coverage_kcov TARGET_NAME)

endfunction()

function(analyze_coverage_gcov TARGET_NAME)

	if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
		message(WARNING "Code coverage results with an optimized (non-Debug) build may be misleading")
	endif()
	
	#if(NOT LCOV_EXECUTABLE)
	#	message(FATAL_ERROR "lcov not found! Aborting...")
    #endif()
	#
    #if(NOT GENHTML_EXECUTABLE)
	#	message(FATAL_ERROR "genhtml not found! Aborting...")
    #endif()
	
	add_custom_target(coverage-reset-${TARGET_NAME}
	
		# Cleanup lcov
		${LCOV_EXECUTABLE} --directory . --zerocounters
	
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
		COMMENT "Resetting code coverage counters to zero for ${TARGET_NAME}."
	)
	
	add_custom_target(coverage-report-${TARGET_NAME}
		# Capturing lcov counters and generating report
		COMMAND ${LCOV_EXECUTABLE} --directory . --capture --output-file "${TARGET_NAME}.info"
		COMMAND ${LCOV_EXECUTABLE} --remove "${TARGET_NAME}.info" 'tests/*' '/usr/*' --output-file "${TARGET_NAME}.info.cleaned"
		COMMAND ${GENHTML_EXECUTABLE} -o "${TARGET_NAME}" "${TARGET_NAME}.info.cleaned"
		COMMAND ${CMAKE_COMMAND} -E remove "${TARGET_NAME}.info" "${TARGET_NAME}.info.cleaned"
	
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
		COMMENT "Processing code coverage counters and generating report for ${TARGET_NAME}."
	)
	
    # Show info where to find the report
	add_custom_target(TARGET coverage-report-${TARGET_NAME} POST_BUILD
		COMMAND
		COMMENT "Open ./${TARGET_NAME}/index.html in your browser to view the coverage report."
	)

	#COMMAND ${GGCOVR_EXECUTABLE} -x -r ${CMAKE_SOURCE_DIR} -e '${CMAKE_SOURCE_DIR}/tests/' -o ${_outputname}.xml
	#WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
	#COMMENT "Running gcovr to produce Cobertura code coverage report."
	#COMMENT "Cobertura code coverage report saved in ${_outputname}.xml."
            
endfunction()
