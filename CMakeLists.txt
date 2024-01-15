cmake_minimum_required(VERSION 3.5)

project(DayRoller VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    include/main.cpp
    include/gui/mainwindow.cpp
        include/gui/mainwindow.h

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DayRoller
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        include/decision/roller.h include/decision/roller.cpp
        include/decision/directive.h include/decision/directive.cpp
        include/decision/constantdirective.h include/decision/constantdirective.cpp
        include/decision/decider.h include/decision/decider.cpp
        include/serialization/serializable.h
        include/serialization/serializer.h
        include/serialization/jsonserializer.h include/serialization/jsonserializer.cpp
        include/decision/variabledirective.h include/decision/variabledirective.cpp
        include/session/profile.h include/session/profile.cpp
        include/session/session.h include/session/session.cpp
        include/session/activitylog.h include/session/activitylog.cpp
        include/gui/dayfocus.h include/gui/dayfocus.cpp
        include/session/profilequery.h include/session/profilequery.cpp
        resource/res.qrc
        include/session/edithistory.h include/session/edithistory.cpp
        include/serialization/binaryserializer.h include/serialization/binaryserializer.cpp
        include/appinit.h





    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET DayRoller APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(DayRoller SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(DayRoller
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(DayRoller PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.DayRoller)
endif()
set_target_properties(DayRoller PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS DayRoller
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DayRoller)
endif()
