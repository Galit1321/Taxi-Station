cmake_minimum_required(VERSION 3.5.1)
project(AdvPro01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(SOURCE_FILES Test/LuxuryTest.cpp Test/CreateTest.cpp Test/PointTest.cpp
        Test/SearchableTripTest.cpp Test/BFSTest.cpp Test/DriverTest.cpp Test/MatrixLayoutTest.cpp
        Test/PassengerTest.cpp Test/TaxiCTest.cpp Test/TaxiCabTest.cpp BFS.cpp BFS.h Car.cpp Car.h Creation/Create.cpp
        Creation/Create.h Creation/CreateGrid.h Creation/CreateGrid.cpp Driver.cpp Driver.h ILayout.h ISearchable.h ISearcher.h
        Luxury.cpp Luxury.h  main.cpp MatrixLayout.cpp MatrixLayout.h Passenger.cpp Passenger.h Person.cpp
        Person.h Point.cpp Point.h SearchableTrip.h SearchableTrip.cpp TaxiCab.cpp TaxiCab.h TaxiCenter.h TaxiCenter.cpp
        main.cpp Controller.cpp Controller.h Creation/CreateDriver.cpp Creation/CreateDriver.h Creation/CreateCar.cpp Creation/CreateCar.h Creation/CreateRide.cpp
        Creation/CreateRide.h UDP.cpp UDP.h Connection.cpp Connection.h)

set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})

add_executable(AdvPro01 ${SOURCE_FILES})

target_link_libraries(AdvPro01 ${Boost_LIBRARIES})
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

target_link_libraries(AdvPro01 gtest gtest_main)