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
include CMakeFiles/test_range.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_range.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_range.dir/flags.make

CMakeFiles/test_range.dir/samples/test_range.cpp.o: CMakeFiles/test_range.dir/flags.make
CMakeFiles/test_range.dir/samples/test_range.cpp.o: ../samples/test_range.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/Programacion2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_range.dir/samples/test_range.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_range.dir/samples/test_range.cpp.o -c /workspaces/Programacion2/samples/test_range.cpp

CMakeFiles/test_range.dir/samples/test_range.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_range.dir/samples/test_range.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Programacion2/samples/test_range.cpp > CMakeFiles/test_range.dir/samples/test_range.cpp.i

CMakeFiles/test_range.dir/samples/test_range.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_range.dir/samples/test_range.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Programacion2/samples/test_range.cpp -o CMakeFiles/test_range.dir/samples/test_range.cpp.s

# Object files for target test_range
test_range_OBJECTS = \
"CMakeFiles/test_range.dir/samples/test_range.cpp.o"

# External object files for target test_range
test_range_EXTERNAL_OBJECTS =

test_range: CMakeFiles/test_range.dir/samples/test_range.cpp.o
test_range: CMakeFiles/test_range.dir/build.make
test_range: ../lib/mates/build/libmates.a
test_range: CMakeFiles/test_range.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/Programacion2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_range"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_range.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_range.dir/build: test_range

.PHONY : CMakeFiles/test_range.dir/build

CMakeFiles/test_range.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_range.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_range.dir/clean

CMakeFiles/test_range.dir/depend:
	cd /workspaces/Programacion2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/Programacion2 /workspaces/Programacion2 /workspaces/Programacion2/build /workspaces/Programacion2/build /workspaces/Programacion2/build/CMakeFiles/test_range.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_range.dir/depend

