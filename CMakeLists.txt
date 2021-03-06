cmake_minimum_required(VERSION 3.5)

project(MatrixCalculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainapp.cpp
        mainapp.h
        mainapp.ui
        matrix.h
        matrix.cpp
)

include_directories(
    " ../../libs/armadillo/include/"
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MatrixCalculator
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(MatrixCalculator SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(MatrixCalculator
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MatrixCalculator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    "../../libs/arma-addon/x86_64/liblapack"
    "../../libs/arma-addon/x86_64/libblas")

add_custom_command (TARGET MatrixCalculator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "../../libs/arma-addon/x86_64/liblapack.dll"
    ${CMAKE_BINARY_DIR}
)

add_custom_command (TARGET MatrixCalculator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "../../libs/arma-addon/x86_64/libblas.dll"
    ${CMAKE_BINARY_DIR}
)

set_target_properties(MatrixCalculator PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MatrixCalculator)
endif()
