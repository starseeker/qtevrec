cmake_minimum_required(VERSION 3.12)

project(EVREC)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Boost COMPONENTS serialization REQUIRED)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${Boost_INCLUDE_DIR}
  )

add_executable(qtevrec
  main.cpp
  mainwindow.cpp
  canvaswidget.cpp
  eventserialization.cpp
  qinputeventrecorder.cpp
  naiveserialization.cpp
  mainwindow.h
  canvaswidget.h
  eventserialization.h
  qinputeventrecorder.h
  mainwindow.ui
  )

target_link_libraries(qtevrec Qt5::Widgets ${Boost_LIBRARIES})

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8
