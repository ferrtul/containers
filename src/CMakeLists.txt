cmake_minimum_required(VERSION 3.26)
project(containers)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS --coverage)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(containers
        ./set/capacity.hpp
        ./set/iterators.hpp
        ./set/lookup.hpp
        ./set/member_functions.hpp
        ./set/modifiers.hpp
        ./set/s21_set.hpp

        ./RedBlackTree/delete.hpp
        ./RedBlackTree/finders.hpp
        ./RedBlackTree/getters.hpp
        ./RedBlackTree/insert.hpp
        ./RedBlackTree/printers.hpp
        ./RedBlackTree/rbt.hpp
        ./RedBlackTree/rotations.hpp
        ./RedBlackTree/tree_walkers.hpp

        ./map/capacity.hpp
        ./map/iterators.hpp
        ./map/lookup.hpp
        ./map/s21_map.hpp
        ./map/member_functions.hpp
        ./map/modifiers.hpp

        ./tests/header.h
        ./tests/set.cc
        ./tests/map.cc
        ./tests/vector.cc
        ./tests/stack.cc
        ./tests/array.cc
        ./tests/list.cpp
        ./tests/queue.cpp
)

target_link_libraries(
        containers
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(containers)