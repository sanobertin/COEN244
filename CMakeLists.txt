cmake_minimum_required(VERSION 3.27.7)
project(COEN244)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_LINKER_FLAGS “-g -Wall -Werror”)
message("CMAKE build type: ${CMAKE_BUILD_TYPE}")

#GLOB_RECURSE
file(GLOB ALLCPP
        "*.cpp")

foreach(file ${ALLCPP})
    #extract just the file name and extension
    get_filename_component(fname ${file} NAME)
    message(STATUS "Adding target for ${fname}")
    #add target for just that file
    add_executable(${fname} ${fname})
endforeach()

##
add_subdirectory(assignment1)
message("adding sub-directory>> ${PROJECT_SOURCE_DIR}/assignment1")
##
##
add_subdirectory(A3)
include_directories("${PROJECT_SOURCE_DIR}/A3")
message("adding sub-directory>> ${PROJECT_SOURCE_DIR}/A3")
##
#add_executable(advanced.cpp advanced.cpp)
##
#add_executable(Ass4 "${PROJECT_SOURCE_DIR}/foreign/assignment4-q1.cpp")
#add_executable(Ass4-2 "${PROJECT_SOURCE_DIR}/foreign/assignment4-q2/employee.h" "${PROJECT_SOURCE_DIR}/foreign/assignment4-q2/employee.cpp" "${PROJECT_SOURCE_DIR}/foreign/assignment4-q2/testemployee.cpp" )
#add_executable(Ass4-3 "${PROJECT_SOURCE_DIR}/foreign/assignment4-q3/department.h" "${PROJECT_SOURCE_DIR}/foreign/assignment4-q3/department.cpp" "${PROJECT_SOURCE_DIR}/foreign/assignment4-q3/testdepartment.cpp" "${PROJECT_SOURCE_DIR}/foreign/assignment4-q3/employee.h" "${PROJECT_SOURCE_DIR}/foreign/assignment4-q3/employee.cpp"  )
#message("adding sub-directory>> ${PROJECT_SOURCE_DIR}/foreign")
##
##

#A4 folder
add_subdirectory(A4)
#std folder
add_subdirectory(std)
# AAA folder
add_subdirectory(AAA)