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
include lib/mylib/CMakeFiles/mylib.dir/depend.make

# Include the progress variables for this target.
include lib/mylib/CMakeFiles/mylib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/mylib/CMakeFiles/mylib.dir/flags.make

lib/mylib/CMakeFiles/mylib.dir/src/mymaths.cpp.o: lib/mylib/CMakeFiles/mylib.dir/flags.make
lib/mylib/CMakeFiles/mylib.dir/src/mymaths.cpp.o: ../lib/mylib/src/mymaths.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/Programacion2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/mylib/CMakeFiles/mylib.dir/src/mymaths.cpp.o"
	cd /workspaces/Programacion2/build/lib/mylib && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mylib.dir/src/mymaths.cpp.o -c /workspaces/Programacion2/lib/mylib/src/mymaths.cpp

lib/mylib/CMakeFiles/mylib.dir/src/mymaths.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mylib.dir/src/mymaths.cpp.i"
	cd /workspaces/Programacion2/build/lib/mylib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Programacion2/lib/mylib/src/mymaths.cpp > CMakeFiles/mylib.dir/src/mymaths.cpp.i

lib/mylib/CMakeFiles/mylib.dir/src/mymaths.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/src/mymaths.cpp.s"
	cd /workspaces/Programacion2/build/lib/mylib && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Programacion2/lib/mylib/src/mymaths.cpp -o CMakeFiles/mylib.dir/src/mymaths.cpp.s

# Object files for target mylib
mylib_OBJECTS = \
"CMakeFiles/mylib.dir/src/mymaths.cpp.o"

# External object files for target mylib
mylib_EXTERNAL_OBJECTS =

../lib/mylib/build/libmylib.a: lib/mylib/CMakeFiles/mylib.dir/src/mymaths.cpp.o
../lib/mylib/build/libmylib.a: lib/mylib/CMakeFiles/mylib.dir/build.make
../lib/mylib/build/libmylib.a: lib/mylib/CMakeFiles/mylib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/Programacion2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/mylib/build/libmylib.a"
	cd /workspaces/Programacion2/build/lib/mylib && $(CMAKE_COMMAND) -P CMakeFiles/mylib.dir/cmake_clean_target.cmake
	cd /workspaces/Programacion2/build/lib/mylib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mylib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/mylib/CMakeFiles/mylib.dir/build: ../lib/mylib/build/libmylib.a

.PHONY : lib/mylib/CMakeFiles/mylib.dir/build

lib/mylib/CMakeFiles/mylib.dir/clean:
	cd /workspaces/Programacion2/build/lib/mylib && $(CMAKE_COMMAND) -P CMakeFiles/mylib.dir/cmake_clean.cmake
.PHONY : lib/mylib/CMakeFiles/mylib.dir/clean

lib/mylib/CMakeFiles/mylib.dir/depend:
	cd /workspaces/Programacion2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/Programacion2 /workspaces/Programacion2/lib/mylib /workspaces/Programacion2/build /workspaces/Programacion2/build/lib/mylib /workspaces/Programacion2/build/lib/mylib/CMakeFiles/mylib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/mylib/CMakeFiles/mylib.dir/depend

