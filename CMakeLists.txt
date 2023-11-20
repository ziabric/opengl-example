cmake_minimum_required(VERSION 3.25)
project(openglExample)

set(CMAKE_CXX_STANDARD 17)

include_directories(./)

find_package(SFML COMPONENTS system graphics audio network REQUIRED)

set(IMGUI
        imgui/imconfig.h
        imgui/imgui.cpp
        imgui/imgui.h
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_internal.h
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imstb_rectpack.h
        imgui/imstb_textedit.h
        imgui/imstb_truetype.h
        imgui/imconfig-SFML.h
        imgui/imgui-SFML.cpp
        imgui/imgui-SFML.h
        imgui/imgui-SFML_export.h
)

add_executable(${PROJECT_NAME} main.cpp ${IMGUI}
        poverhnostNURBS.h
        simpleExample.h
        kr1.h
        kr2.h
        cubes.h
        image.h
        anims.h
        kr21.h)

target_link_libraries(${PROJECT_NAME} GL glut GLU sfml-window sfml-network sfml-graphics sfml-system)
