# EntryPoint
set(ENTRY_POINT_HEADER          ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h)
set(ENTRY_POINT_CPP             ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp)

# Application
set(APPLICATION_HEADER          ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h)
set(APPLICATION_CPP             ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp)

# Core
set(GAME_CORE_HEADER            ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Core.h)
set(GAME_CORE_CPP               ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Core.cpp)

# World
set(GAME_WORLD_HEADER           ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/World.h)
set(GAME_WORLD_cpp              ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.cpp)

add_library(${TARGET_ENGINE_NAME} STATIC
# EntryPoint
    ${ENTRY_POINT_HEADER}
    ${ENTRY_POINT_CPP}
    
# Application
    ${APPLICATION_HEADER}
    ${APPLICATION_CPP}
    
# Core
    ${GAME_CORE_HEADER}
    ${GAME_CORE_CPP}
    
# World
    ${GAME_WORLD_HEADER}
    ${GAME_WORLD_cpp}
)

target_include_directories(
    ${TARGET_ENGINE_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

function(linkLibrary LIB_NAME)
    target_link_libraries(
        ${TARGET_ENGINE_NAME}
        PUBLIC ${LIB_NAME}
    )
endfunction()

linkLibrary(sfml-audio)
linkLibrary(sfml-graphics)
linkLibrary(sfml-network)
linkLibrary(sfml-system)
linkLibrary(sfml-window)