#----- Dear ImGui library
project(imgui
        VERSION 1.91.8
        LANGUAGES CXX
        DESCRIPTION "ImGui library.")

set( THIRDPARTY_DIR "../")

set( IMGUI_SRC_DIR ${THIRDPARTY_DIR}/imgui )

set( IMGUI_PUBLIC_HEADERS "${IMGUI_SRC_DIR}/imgui.h")

set( IMGUI_SOURCES
    ${IMGUI_SRC_DIR}/imgui.cpp
    ${IMGUI_SRC_DIR}/imgui_demo.cpp
    ${IMGUI_SRC_DIR}/imgui_draw.cpp
    ${IMGUI_SRC_DIR}/imgui_tables.cpp
    ${IMGUI_SRC_DIR}/imgui_widgets.cpp
    ${IMGUI_SRC_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_SRC_DIR}/backends/imgui_impl_opengl3.cpp
    ${IMGUI_SRC_DIR}/misc/cpp/imgui_stdlib.cpp
    ${THIRDPARTY_DIR}/glad/include/glad/gl.h )

add_library( imgui STATIC ${IMGUI_SOURCES} )

target_link_libraries( imgui glfw )

target_include_directories( imgui PUBLIC "${IMGUI_SRC_DIR}")
