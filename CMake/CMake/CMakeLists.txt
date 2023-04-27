# CMakeList.txt : CMake project for CMake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (producer "producer.cpp")
add_executable (consumer "consumer.cpp")
add_executable (sem_util "sem_util.cpp")

# TODO: Add tests and install targets if needed.
