# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bertin/CLionProjects/COEN244

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bertin/CLionProjects/COEN244

# Include any dependencies generated for this target.
include A3/CMakeFiles/testfile.cpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include A3/CMakeFiles/testfile.cpp.dir/compiler_depend.make

# Include the progress variables for this target.
include A3/CMakeFiles/testfile.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include A3/CMakeFiles/testfile.cpp.dir/flags.make

A3/CMakeFiles/testfile.cpp.dir/test.cpp.o: A3/CMakeFiles/testfile.cpp.dir/flags.make
A3/CMakeFiles/testfile.cpp.dir/test.cpp.o: A3/test.cpp
A3/CMakeFiles/testfile.cpp.dir/test.cpp.o: A3/CMakeFiles/testfile.cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bertin/CLionProjects/COEN244/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object A3/CMakeFiles/testfile.cpp.dir/test.cpp.o"
	cd /Users/bertin/CLionProjects/COEN244/A3 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT A3/CMakeFiles/testfile.cpp.dir/test.cpp.o -MF CMakeFiles/testfile.cpp.dir/test.cpp.o.d -o CMakeFiles/testfile.cpp.dir/test.cpp.o -c /Users/bertin/CLionProjects/COEN244/A3/test.cpp

A3/CMakeFiles/testfile.cpp.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testfile.cpp.dir/test.cpp.i"
	cd /Users/bertin/CLionProjects/COEN244/A3 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bertin/CLionProjects/COEN244/A3/test.cpp > CMakeFiles/testfile.cpp.dir/test.cpp.i

A3/CMakeFiles/testfile.cpp.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testfile.cpp.dir/test.cpp.s"
	cd /Users/bertin/CLionProjects/COEN244/A3 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bertin/CLionProjects/COEN244/A3/test.cpp -o CMakeFiles/testfile.cpp.dir/test.cpp.s

# Object files for target testfile.cpp
testfile_cpp_OBJECTS = \
"CMakeFiles/testfile.cpp.dir/test.cpp.o"

# External object files for target testfile.cpp
testfile_cpp_EXTERNAL_OBJECTS =

A3/testfile.cpp: A3/CMakeFiles/testfile.cpp.dir/test.cpp.o
A3/testfile.cpp: A3/CMakeFiles/testfile.cpp.dir/build.make
A3/testfile.cpp: A3/CMakeFiles/testfile.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/bertin/CLionProjects/COEN244/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testfile.cpp"
	cd /Users/bertin/CLionProjects/COEN244/A3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testfile.cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
A3/CMakeFiles/testfile.cpp.dir/build: A3/testfile.cpp
.PHONY : A3/CMakeFiles/testfile.cpp.dir/build

A3/CMakeFiles/testfile.cpp.dir/clean:
	cd /Users/bertin/CLionProjects/COEN244/A3 && $(CMAKE_COMMAND) -P CMakeFiles/testfile.cpp.dir/cmake_clean.cmake
.PHONY : A3/CMakeFiles/testfile.cpp.dir/clean

A3/CMakeFiles/testfile.cpp.dir/depend:
	cd /Users/bertin/CLionProjects/COEN244 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bertin/CLionProjects/COEN244 /Users/bertin/CLionProjects/COEN244/A3 /Users/bertin/CLionProjects/COEN244 /Users/bertin/CLionProjects/COEN244/A3 /Users/bertin/CLionProjects/COEN244/A3/CMakeFiles/testfile.cpp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : A3/CMakeFiles/testfile.cpp.dir/depend

