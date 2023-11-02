if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    add_custom_target(run_terminal
            COMMAND open -a Terminal "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}"
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}  # Working directory 설정 추가
            COMMENT "Open Terminal"
    )
endif()
