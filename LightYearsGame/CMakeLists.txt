set(GAME_APPLICATION_HEADER             ${CMAKE_CURRENT_SOURCE_DIR}/include/GameFramework/GameApplication.h)
set(GAME_APPLICATION_CPP                ${CMAKE_CURRENT_SOURCE_DIR}/src/GameFramework/GameApplication.cpp)

set(GAME_SPACESHIP_HEADER               ${CMAKE_CURRENT_SOURCE_DIR}/include/spaceship/spaceship.h)
set(GAME_SPACESHIP_CPP                  ${CMAKE_CURRENT_SOURCE_DIR}/src/spaceship/spaceship.cpp)

#PlayerSpaceship
set(GAME_PLAYER_SPACESHIP_HEADER        ${CMAKE_CURRENT_SOURCE_DIR}/include/player/PlayerSpaceship.h)
set(GAME_PLAYER_SPACESHIP_CPP           ${CMAKE_CURRENT_SOURCE_DIR}/src/player/PlayerSpaceship.cpp)

add_executable(${TARGET_GAME_NAME}
    # Game Application
    ${GAME_APPLICATION_HEADER}
    ${GAME_APPLICATION_CPP}
    
    # Spaceship
    ${GAME_SPACESHIP_HEADER}
    ${GAME_SPACESHIP_CPP}
    
    # Player Spaceship
    ${GAME_PLAYER_SPACESHIP_HEADER}
    ${GAME_PLAYER_SPACESHIP_CPP}
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

set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

add_custom_command(
    TARGET ${TARGET_GAME_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_directory
    ${RESOURCE_SRC_DIR}
    $<TARGET_FILE_DIR:${TARGET_GAME_NAME}>/${RESOURCE_FOLDER_NAME}
)

configure_file(
    "config.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/config.h" ESCAPE_QUOTES
)