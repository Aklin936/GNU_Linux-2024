cmake_minimum_required(VERSION 3.22)
project(RHasher)

endif()

add_executable(rhasher rhasher.c)
target_link_libraries(rhasher ${LIBS})

enable_testing()
