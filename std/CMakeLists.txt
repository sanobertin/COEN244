
file(GLOB ALLCPP_IN_STD
        "*.cpp")

foreach(file ${ALLCPP_IN_STD})
    #extract just the file name and extension
    get_filename_component(fname ${file} NAME)
    message(STATUS "Adding target for ${fname}")
    #add target for just that file
    add_executable(${fname} ${fname})
endforeach()