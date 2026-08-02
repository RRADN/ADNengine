cmake_minimum_required(VERSION 3.30)
project(ADN_ENGINE VERSION 0.2.1 LANGUAGES CXX)

set(SDL3_VERSION "3.0")

# Find or download SDL from a suitable location
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # On Linux, use your package manager to fetch SDL Libraries
    find_package(SDL3 REQUIRED)
    find_package(SDL3_image REQUIRED)
    find_package(SDL3_ttf REQUIRED)
    find_package(Python3 REQUIRED)

    if (NOT SDL3_FOUND)
        message(FATAL_ERROR "Unable to find SDL3 on your system. Install it using your package manager.")
    endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # On Windows, we can use a pre-compiled SDL library stored in the project directory
    set(SDL3_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/SDL3/include)
    set(SDL3_LIBRARY ${CMAKE_SOURCE_DIR}/external/SDL3/lib/x64/SDL3.lib)
    include_directories(${SDL3_INCLUDE_DIR})

    set(SDL3_IMAGE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/SDL3_image/include)
    set(SDL3_IMAGE_LIBRARY ${CMAKE_SOURCE_DIR}/external/SDL3_image/lib/x64/SDL3_image.lib)
    include_directories(${SDL3_IMAGE_INCLUDE_DIR}) 
endif()

add_executable(${PROJECT_NAME}
    #app
    src/main.cpp
    src/app/app.cpp

    #src/core/timer/timer.cpp
    
    #window
    src/platform/window/sdlWindow.cpp
    
    #events
    src/platform/events/sdlEvents.cpp
    src/platform/events/guiEvents.cpp
    src/platform/events/eventsManager.cpp

    #rendering
    src/platform/rendering/renderManager.cpp
    src/platform/rendering/textures/textureManager.cpp

    #context
    src/platform/context/contextManager.cpp

    #gui
    src/platform/gui/guiManager.cpp
    src/platform/gui/rendering/guiBackend.cpp
    src/platform/gui/rendering/guiRender.cpp
    src/platform/gui/styles/guiStyle.cpp
    src/platform/gui/windows/windowsManager.cpp
    
    #gui Windows
    src/platform/gui/windows/scene.cpp

    #entities
    src/entities/primitive/entity.cpp
    
    #collision
    src/logic/systems/collisions/collision.cpp
    src/logic/systems/collisions/collisionManager.cpp
    
    #input logic
    src/logic/input/inputManager.cpp
    src/logic/input/keysManager.cpp
)

#imgui
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)

target_sources(${PROJECT_NAME} PRIVATE

    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_demo.cpp

    ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer3.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

#script execute
add_custom_target(generate_assets ALL
    COMMAND
        ${Python3_EXECUTABLE}
        ${CMAKE_SOURCE_DIR}/src/scripts/generator.py

    WORKING_DIRECTORY
        ${CMAKE_SOURCE_DIR}

    COMMENT "Generating asset files..."
)

add_dependencies(${PROJECT_NAME} generate_assets)

#memory leak detector
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -g3
        -O0
        -fno-omit-frame-pointer
        -fno-inline
        -fsanitize=address
    )

    target_link_options(${PROJECT_NAME} PRIVATE
        -fsanitize=address
    )
endif()

# Linking SDL libraries
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL3::SDL3 
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
    )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} ${SDL3_LIBRARY} ${SDL3_IMAGE_LIBRARY})

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/external/SDL3/lib/x64/SDL3.dll
        ${CMAKE_SOURCE_DIR}/external/SDL3_image/lib/x64/SDL3_image.dll
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

#copy assets to build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

