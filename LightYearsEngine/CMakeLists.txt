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
set(GAME_WORLD_CPP              ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.cpp)

# Actor
set(GAME_ACTOR_HEADER           ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Actor.h)
set(GAME_ACTOR_CPP              ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Actor.cpp)

# Object
set(GAME_OBJECT_HEADER           ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Object.h)
set(GAME_OBJECT_CPP              ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Object.cpp)

# Asset Manager
set(GAME_ASSET_MANAGER_HEADER           ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/AssetManager.h)
set(GAME_ASSET_MANAGER_CPP              ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/AssetManager.cpp)

# Math
set(GAME_MATH_HEADER           ${CMAKE_CURRENT_SOURCE_DIR}/include/helper/Math.h)
set(GAME_MATH_CPP              ${CMAKE_CURRENT_SOURCE_DIR}/src/helper/Math.cpp)

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
    ${GAME_WORLD_CPP}
    
# Actor
    ${GAME_ACTOR_HEADER}
    ${GAME_ACTOR_CPP}
    
# Object
    ${GAME_OBJECT_HEADER}
    ${GAME_OBJECT_CPP}

# Asset Manager
    ${GAME_ASSET_MANAGER_HEADER}
    ${GAME_ASSET_MANAGER_CPP}

# Math
    ${GAME_MATH_HEADER}
    ${GAME_MATH_CPP}
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