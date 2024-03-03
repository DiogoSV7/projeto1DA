cmake_minimum_required(VERSION 3.27)
project(projeto1DA)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/includes)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(projeto1DA
        ${SOURCE_DIR}/main.cpp
        ${INCLUDE_DIR}/Graph.h
        ${INCLUDE_DIR}/WaterReservoir.h
        ${INCLUDE_DIR}/PumpingStations.h
        ${INCLUDE_DIR}/Pipes.h
        ${INCLUDE_DIR}/DeliverySites.h
        ${SOURCE_DIR}/Pipes.cpp
        ${SOURCE_DIR}/PumpingStations.cpp
        ${SOURCE_DIR}/WaterReservoir.cpp
        ${INCLUDE_DIR}/Data.h
        ${SOURCE_DIR}/Data.cpp
        ${SOURCE_DIR}/DeliverySites.cpp
        ${INCLUDE_DIR}/Window.h
        ${SOURCE_DIR}/Window.cpp
)

target_include_directories(projeto1DA PRIVATE ${INCLUDE_DIR})
