qt-cmake-template
===========

A Qt5/6 CMake quickstart template.

It's extremely easy to setup. All you need to do is add your Qt installation as an environment variable and change the Major Version CMAKE variable to the Qt major version.

    For Qt5 create an environment variable called Qt5_HOME that points to your Qt5 installation and change the QT_MAJOR_VERSION to 5 in the CMakeLists.txt file.
    
    For Qt6 create an environment variable called Qt6_HOME that points to your Qt6 installation and change the QT_MAJOR_VERSION to 6 in the CMakeLists.txt file.

For example:

    Qt5_HOME = C:\Users\Andrew\Documents\Qt\5.15.2\msvc2019_64
    Qt6_HOME = C:\Users\Andrew\Documents\Qt\6.0.1\msvc2019_64
