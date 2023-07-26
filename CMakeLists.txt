cmake_minimum_required(VERSION 3.14)

project(LaboratorioProg LANGUAGES CXX)

enable_testing(true)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(LaboratorioProg
  main.cpp
  event.h
  event.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
  dayview.h
  dayview.cpp

  day.h
  day.cpp
  day.ui
  tester.h
  tester.cpp
)

add_test(NAME LaboratorioProg COMMAND LaboratorioProg)



target_link_libraries(LaboratorioProg PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(LaboratorioProg PRIVATE Qt6::Test)

install(TARGETS LaboratorioProg
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set_target_properties(LaboratorioProg PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
