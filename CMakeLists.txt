cmake_minimum_required(VERSION 3.16)

#Project name
set(PRJ_NAME Temp)

#You can change this to Qt5 or Qt4 if you
#are not ready to migrate to Qt6.
set(QT_PACKAGE Qt5)

project(${PRJ_NAME} VERSION 0.0.1 DESCRIPTION "Project Description")

#Make sure CMake will take care of moc for us
set(CMAKE_AUTOMOC ON)

#Set the CXX standard. Qt 6 I believe uses c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Check to make sure the environment var is set
#since we need to know where Qt is installed.
if($ENV{QT_HOME})
    message(STATUS "Looking for Qt in: " $ENV{QT_HOME})
else()
    message(STATUS "QT_HOME environment variable not set. Checking default paths.")
endif()

#standard paths to include
find_package(${QT_PACKAGE} COMPONENTS Core Widgets REQUIRED PATHS $ENV{QT_HOME})

#Add extra components here as needed.
#find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(${PRJ_NAME}
    include/window.hpp
    src/window.cpp
    src/main.cpp)

target_include_directories(${PRJ_NAME} PRIVATE ${Qt6_INCLUDE_DIRS})
target_include_directories(${PRJ_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

#Add any extra libs to link also.
target_link_libraries(${PRJ_NAME} PRIVATE ${QT_PACKAGE}::Core ${QT_PACKAGE}::Widgets)