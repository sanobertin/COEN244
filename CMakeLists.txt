cmake_minimum_required(VERSION 3.27)
project(COEN244)

set(CMAKE_CXX_STANDARD 17)

#add_executable(COEN244 main.cpp)
add_executable(main main.cpp)
#add_executable(regex regex.cpp)
add_executable(binary_math binary_math.cpp)
#add_executable(1_b_TicTacToe1D 1_b_TicTacToe1D.cpp)
add_executable(Time time.cpp)
add_executable(main1 main1.cpp)
add_executable(main2 main2.cpp)
add_executable(regex regex.cpp)
##
add_subdirectory(assignment1)
message("adding sub-directory>> ${PROJECT_SOURCE_DIR}/assignment1")
##