cmake_minimum_required(VERSION 3.22)
project(RHasher)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

option(USE_READLINE "Use readline function" ON)
if (USE_READLINE)
	add_definitions(-DUSE_READLINE)
endif (USE_READLINE)