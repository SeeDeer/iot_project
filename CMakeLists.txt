cmake_minimum_required (VERSION 3.2)
project (main)

# set(CMAKE_C_COMPILER "mips-linux-uclibc-gcc")
# set(CMAKE_CXX_COMPILER "mips-linux-uclibc-g++")
# set(CMAKE_STRIP "mips-linux-uclibc-strip")

# 包含头文件
include_directories(./os_time/include ./os_algorithm/include)

# 包含库

# 包含源文件
# set(CFILE_SRC hashmap/hashmap.c)
# set(CFILE_SRC ${CFILE_SRC} main.c)

aux_source_directory(./app CFILE_SRC)
aux_source_directory(./os_time/src CFILE_SRC)
aux_source_directory(./os_algorithm/src CFILE_SRC)

message(STATUS "${CFILE_SRC}")
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -g)
message(STATUS "${CMAKE_C_FLAGS}")

# add_compile_options(-pthread)

add_executable(main ${CFILE_SRC})
