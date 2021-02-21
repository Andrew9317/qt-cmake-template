cmake_minimum_required(VERSION 3.16)

#Project name
set(TARGET_NAME Temp)

#You can change this to Qt5 if you
#are not ready to migrate to Qt6.
set(QT_MAJOR_VERSION 5)

project(${TARGET_NAME} VERSION 0.0.1 DESCRIPTION "Project Description")

#Make sure CMake will take care of moc for us
set(CMAKE_AUTOMOC ON)

#Set the CXX standard. Qt 6 I believe uses c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#See if the environment var is set
if(DEFINED ENV{Qt${QT_MAJOR_VERSION}_HOME})
    message(STATUS "Looking for Qt in: " $ENV{Qt${QT_MAJOR_VERSION}_HOME})
else()
    message(STATUS "Qt${QT_MAJOR_VERSION}_HOME environment variable not set. Checking default paths.")
endif()

#Qt6 requires setting the CMAKE_PREFIX_PATH whereas 5 does not.
if("${QT_MAJOR_VERSION}" STREQUAL "6")
    set(CMAKE_PREFIX_PATH $ENV{Qt${QT_MAJOR_VERSION}_HOME})
endif()

#find_package should find everything fine so long as the ENV Variable is set or, for linux systems,
#it is in the default install path.
find_package(Qt${QT_MAJOR_VERSION} COMPONENTS Widgets REQUIRED PATHS $ENV{Qt${QT_MAJOR_VERSION}_HOME})

add_executable(${TARGET_NAME}
    include/window.hpp
    src/window.cpp
    src/main.cpp)
    
if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_include_directories(${TARGET_NAME} PRIVATE ${Qt${QT_MAJOR_VERSION}_INCLUDE_DIRS})
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_OUTPUT_NAME "${TARGET_NAME}d" RELEASE_OUTPUT_NAME ${TARGET_NAME})

#Add any extra libs to link also.
target_link_libraries(${TARGET_NAME} PRIVATE Qt${QT_MAJOR_VERSION}::Widgets)