cmake_minimum_required(VERSION 3.14)

project(LaboratorioProg LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(LaboratorioProg
  main.cpp
  event.h
  event.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
  day.h
  day.cpp
  day.ui
)
target_link_libraries(LaboratorioProg Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS LaboratorioProg
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set_target_properties(LaboratorioProg PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
