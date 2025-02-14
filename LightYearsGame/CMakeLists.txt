set(GAME_APPLICATION_HEADER          ${CMAKE_CURRENT_SOURCE_DIR}/include/GameFramework/GameApplication.h)
set(GAME_APPLICATION_CPP             ${CMAKE_CURRENT_SOURCE_DIR}/src/GameFramework/GameApplication.cpp)

add_executable(${TARGET_GAME_NAME}
    ${GAME_APPLICATION_HEADER}
    ${GAME_APPLICATION_CPP}
)

target_include_directories(
    ${TARGET_GAME_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

function(linkLibrary LIB_NAME)
    target_link_libraries(
        ${TARGET_GAME_NAME}
        PUBLIC ${LIB_NAME}
    )
endfunction()

linkLibrary(${TARGET_ENGINE_NAME})

function(CopyLibDirectoryToTarget LIB_DIR_NAME TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        $<TARGET_FILE_DIR:${LIB_DIR_NAME}>
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibDirectoryToTarget(${TARGET_ENGINE_NAME} ${TARGET_GAME_NAME})