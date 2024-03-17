cmake_minimum_required(VERSION 3.27)
project(projeto1DA)

set(CMAKE_CXX_STANDARD 17)

add_executable(projeto1DA main.cpp
        includes/Graph.h
        includes/PumpingStations.h
        includes/Pipes.h
        includes/WaterReservoir.h
        includes/DeliverySites.h
        src/Pipes.cpp
        src/PumpingStations.cpp
        src/WaterReservoir.cpp
        includes/Data.h
        src/Data.cpp
        src/DeliverySites.cpp
        src/WaterReservoir.cpp
        includes/MutablePriorityQueue.h
        src/Graph.cpp
        src/Menu.cpp
        includes/Menu.h
)