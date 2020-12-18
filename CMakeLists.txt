cmake_minimum_required(VERSION 3.16)

#Project name
set(PRJ_NAME Temp)

project(${PRJ_NAME} VERSION 0.0.1 DESCRIPTION "Project Description")

#Make sure CMake will take care of moc for us
set(CMAKE_AUTOMOC ON)

#Set the CXX standard. Qt 6 I believe uses c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Looking for Qt in: " $ENV{QT_HOME})

#Check to make sure the environment var is set
#since we need to know where Qt is installed.
if($ENV{QT_HOME} STREQUAL "")
    message(FATAL_ERROR "QT_HOME environment variable not set!")
endif()

#Qt6 standard paths to include
set(Qt6_DIR $ENV{QT_HOME}/lib/cmake/Qt6)
set(Qt6CoreTools_DIR $ENV{QT_HOME}/lib/cmake/Qt6CoreTools)
set(Qt6GuiTools_DIR $ENV{QT_HOME}/lib/cmake/Qt6GuiTools)
set(Qt6WidgetsTools_DIR $ENV{QT_HOME}/lib/cmake/Qt6WidgetsTools)

message(STATUS "Looking for Qt Tools in: \n\t" ${Qt6CoreTools_DIR} "\n\t" ${Qt6GuiTools_DIR} "\n\t" ${Qt6WidgetsTools_DIR})

#Add extra components here as needed.
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(${PRJ_NAME}
    include/window.hpp
    src/window.cpp
    src/main.cpp)

target_include_directories(${PRJ_NAME} PRIVATE ${Qt6_INCLUDE_DIRS})
target_include_directories(${PRJ_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

#Add any extra libs to link also.
target_link_libraries(${PRJ_NAME} PRIVATE Qt6::Core Qt6::Widgets)