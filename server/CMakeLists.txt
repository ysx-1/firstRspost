cmake_minimum_required(VERSION 3.16)
project(server)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(http)
include_directories(inc)
include_directories(oal)
include_directories(oam)
include_directories(threadpool)

add_executable(server
        oal/oal_locker.h
        oal/oal_sleep.h
        oal/oal_top.h
        oal/oal_type.h
        oam/oam_log.h
        threadpool/threadpool.h
        main.cpp
        pre_macro.h
        prepare.h
        server.i oal/oal_timer.h)
