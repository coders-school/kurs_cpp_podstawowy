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
CMAKE_SOURCE_DIR = /home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven/bulid

# Include any dependencies generated for this target.
include CMakeFiles/addEven.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/addEven.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/addEven.dir/flags.make

CMakeFiles/addEven.dir/main.cpp.o: CMakeFiles/addEven.dir/flags.make
CMakeFiles/addEven.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/addEven.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/addEven.dir/main.cpp.o -c /home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven/main.cpp

CMakeFiles/addEven.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/addEven.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven/main.cpp > CMakeFiles/addEven.dir/main.cpp.i

CMakeFiles/addEven.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/addEven.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven/main.cpp -o CMakeFiles/addEven.dir/main.cpp.s

# Object files for target addEven
addEven_OBJECTS = \
"CMakeFiles/addEven.dir/main.cpp.o"

# External object files for target addEven
addEven_EXTERNAL_OBJECTS =

addEven: CMakeFiles/addEven.dir/main.cpp.o
addEven: CMakeFiles/addEven.dir/build.make
addEven: CMakeFiles/addEven.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable addEven"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/addEven.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/addEven.dir/build: addEven

.PHONY : CMakeFiles/addEven.dir/build

CMakeFiles/addEven.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/addEven.dir/cmake_clean.cmake
.PHONY : CMakeFiles/addEven.dir/clean

CMakeFiles/addEven.dir/depend:
	cd /home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven/bulid && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven /home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven /home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven/bulid /home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven/bulid /home/nanautzin/programing/kurs_cpp_podstawowy/module2/homework/addEven/bulid/CMakeFiles/addEven.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/addEven.dir/depend
