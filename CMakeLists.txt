cmake_minimum_required(VERSION 3.5.1)
project(AdvPro01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(SOURCE_FILES LuxuryTest.cpp CreateTest.cpp PointTest.cpp
        SearchableTripTest.cpp BFSTest.cpp DriverTest.cpp MatrixLayoutTest.cpp
        PassengerTest.cpp TaxiCTest.cpp TaxiCabTest.cpp BFS.cpp BFS.h Car.cpp Car.h Create.cpp
        Create.h CreateGrid.h CreateGrid.cpp Driver.cpp Driver.h ILayout.h ISearchable.h ISearcher.h
        Luxury.cpp Luxury.h  main.cpp MatrixLayout.cpp MatrixLayout.h Passenger.cpp Passenger.h Person.cpp
        Person.h Point.cpp Point.h SearchableTrip.h SearchableTrip.cpp TaxiCab.cpp TaxiCab.h TaxiCenter.h TaxiCenter.cpp
        main.cpp Controller.cpp Controller.h CreateDriver.cpp CreateDriver.h CreateCar.cpp CreateCar.h CreateRide.cpp
        CreateRide.h)
add_executable(AdvPro01 ${SOURCE_FILES})


add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

target_link_libraries(AdvPro01 gtest gtest_main)