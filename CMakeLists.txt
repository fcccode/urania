# CMakeLists.txt for project URANIA

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
SET(CMAKE_VERBOSE_MAKEFILE 1)

#PROJECT(urania CXX)

SET(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O3 -DWINVER=0x500 -D_UNICODE -DUNICODE")
include_directories("${CMAKE_INSTALL_PREFIX}/include")

ADD_LIBRARY(urania STATIC
  system.cpp
  msgloop.cpp
  sys-mbs2ws.cpp sys-ws2mbs.cpp
  getCLArgs.cpp getCLArgsW.cpp
  getLongPath.cpp
  ctrl.cpp ctrl_sb.cpp
  pdev.cpp pdev2.cpp pmdev.cpp pmdidx.cpp
  bwin.cpp
  dialog.cpp
  menu.cpp menudesc.cpp
  win.cpp scroll-h.cpp drop-h.cpp
  clkpanel.cpp
  cmndlg.cpp
  registry.cpp regread.cpp regwrite.cpp
)

INSTALL(TARGETS urania DESTINATION lib)
INSTALL(FILES
    decl.h
    system.h
    wbase.h bwin.h
    paintdev.h
    dialog.h
    menu.h
    win.h
    clkpanel.h
    cmndlg.h
    registry.h
  DESTINATION
    include/urania
)


#eof
