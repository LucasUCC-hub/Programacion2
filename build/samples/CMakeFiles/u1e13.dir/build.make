# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/Programacion2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/Programacion2/build

# Include any dependencies generated for this target.
include samples/CMakeFiles/u1e13.dir/depend.make

# Include the progress variables for this target.
include samples/CMakeFiles/u1e13.dir/progress.make

# Include the compile flags for this target's objects.
include samples/CMakeFiles/u1e13.dir/flags.make

samples/CMakeFiles/u1e13.dir/TP1/u1e13.cpp.o: samples/CMakeFiles/u1e13.dir/flags.make
samples/CMakeFiles/u1e13.dir/TP1/u1e13.cpp.o: ../samples/TP1/u1e13.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/Programacion2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object samples/CMakeFiles/u1e13.dir/TP1/u1e13.cpp.o"
	cd /workspaces/Programacion2/build/samples && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/u1e13.dir/TP1/u1e13.cpp.o -c /workspaces/Programacion2/samples/TP1/u1e13.cpp

samples/CMakeFiles/u1e13.dir/TP1/u1e13.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/u1e13.dir/TP1/u1e13.cpp.i"
	cd /workspaces/Programacion2/build/samples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Programacion2/samples/TP1/u1e13.cpp > CMakeFiles/u1e13.dir/TP1/u1e13.cpp.i

samples/CMakeFiles/u1e13.dir/TP1/u1e13.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/u1e13.dir/TP1/u1e13.cpp.s"
	cd /workspaces/Programacion2/build/samples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Programacion2/samples/TP1/u1e13.cpp -o CMakeFiles/u1e13.dir/TP1/u1e13.cpp.s

# Object files for target u1e13
u1e13_OBJECTS = \
"CMakeFiles/u1e13.dir/TP1/u1e13.cpp.o"

# External object files for target u1e13
u1e13_EXTERNAL_OBJECTS =

samples/u1e13: samples/CMakeFiles/u1e13.dir/TP1/u1e13.cpp.o
samples/u1e13: samples/CMakeFiles/u1e13.dir/build.make
samples/u1e13: modules/mates/build/libmates.a
samples/u1e13: samples/CMakeFiles/u1e13.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/Programacion2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable u1e13"
	cd /workspaces/Programacion2/build/samples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/u1e13.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
samples/CMakeFiles/u1e13.dir/build: samples/u1e13

.PHONY : samples/CMakeFiles/u1e13.dir/build

samples/CMakeFiles/u1e13.dir/clean:
	cd /workspaces/Programacion2/build/samples && $(CMAKE_COMMAND) -P CMakeFiles/u1e13.dir/cmake_clean.cmake
.PHONY : samples/CMakeFiles/u1e13.dir/clean

samples/CMakeFiles/u1e13.dir/depend:
	cd /workspaces/Programacion2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/Programacion2 /workspaces/Programacion2/samples /workspaces/Programacion2/build /workspaces/Programacion2/build/samples /workspaces/Programacion2/build/samples/CMakeFiles/u1e13.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : samples/CMakeFiles/u1e13.dir/depend

