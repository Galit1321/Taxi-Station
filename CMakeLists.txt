cmake_minimum_required(VERSION 3.5.1)
project(AdvPro01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++0x")

set(SOURCE_FILES
        BFS.cpp BFS.h Car.cpp Car.h Create.cpp
        Create.h CreateGrid.h CreateGrid.cpp Driver.cpp Driver.h ILayout.h ISearchable.h ISearcher.h
        Luxury.cpp Luxury.h MatrixLayout.cpp MatrixLayout.h Passenger.cpp Passenger.h Person.cpp
        Person.h Point.cpp Point.h SearchableTrip.h SearchableTrip.cpp TaxiCab.cpp TaxiCab.h TaxiCenter.h TaxiCenter.cpp
        Controller.cpp Controller.h Udp.h Udp.cpp CreateDriver.cpp CreateDriver.h CreateCar.cpp CreateCar.h CreateRide.cpp
        CreateRide.h TCP_server.cpp TCP_server.h
        TCP_client.cpp TCP_client.h Tcp.h Tcp.cpp Socket.h Socket.cpp)

set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})
find_package (Threads)

add_executable(AdvPro01 main.cpp ${SOURCE_FILES})

add_executable(client mainclient.cpp ${SOURCE_FILES})

target_link_libraries(client ${Boost_LIBRARIES})

target_link_libraries (client ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(AdvPro01 ${Boost_LIBRARIES})

target_link_libraries (AdvPro01 ${CMAKE_THREAD_LIBS_INIT})