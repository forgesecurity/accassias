# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eric/perso/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eric/perso/src

# Include any dependencies generated for this target.
include console/CMakeFiles/t_console.dir/depend.make

# Include the progress variables for this target.
include console/CMakeFiles/t_console.dir/progress.make

# Include the compile flags for this target's objects.
include console/CMakeFiles/t_console.dir/flags.make

console/CMakeFiles/t_console.dir/t_time.cpp.o: console/CMakeFiles/t_console.dir/flags.make
console/CMakeFiles/t_console.dir/t_time.cpp.o: console/t_time.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eric/perso/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object console/CMakeFiles/t_console.dir/t_time.cpp.o"
	cd /home/eric/perso/src/console && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/t_console.dir/t_time.cpp.o -c /home/eric/perso/src/console/t_time.cpp

console/CMakeFiles/t_console.dir/t_time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/t_console.dir/t_time.cpp.i"
	cd /home/eric/perso/src/console && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eric/perso/src/console/t_time.cpp > CMakeFiles/t_console.dir/t_time.cpp.i

console/CMakeFiles/t_console.dir/t_time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/t_console.dir/t_time.cpp.s"
	cd /home/eric/perso/src/console && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eric/perso/src/console/t_time.cpp -o CMakeFiles/t_console.dir/t_time.cpp.s

console/CMakeFiles/t_console.dir/t_time.cpp.o.requires:
.PHONY : console/CMakeFiles/t_console.dir/t_time.cpp.o.requires

console/CMakeFiles/t_console.dir/t_time.cpp.o.provides: console/CMakeFiles/t_console.dir/t_time.cpp.o.requires
	$(MAKE) -f console/CMakeFiles/t_console.dir/build.make console/CMakeFiles/t_console.dir/t_time.cpp.o.provides.build
.PHONY : console/CMakeFiles/t_console.dir/t_time.cpp.o.provides

console/CMakeFiles/t_console.dir/t_time.cpp.o.provides.build: console/CMakeFiles/t_console.dir/t_time.cpp.o

console/CMakeFiles/t_console.dir/t_console.cpp.o: console/CMakeFiles/t_console.dir/flags.make
console/CMakeFiles/t_console.dir/t_console.cpp.o: console/t_console.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eric/perso/src/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object console/CMakeFiles/t_console.dir/t_console.cpp.o"
	cd /home/eric/perso/src/console && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/t_console.dir/t_console.cpp.o -c /home/eric/perso/src/console/t_console.cpp

console/CMakeFiles/t_console.dir/t_console.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/t_console.dir/t_console.cpp.i"
	cd /home/eric/perso/src/console && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eric/perso/src/console/t_console.cpp > CMakeFiles/t_console.dir/t_console.cpp.i

console/CMakeFiles/t_console.dir/t_console.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/t_console.dir/t_console.cpp.s"
	cd /home/eric/perso/src/console && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eric/perso/src/console/t_console.cpp -o CMakeFiles/t_console.dir/t_console.cpp.s

console/CMakeFiles/t_console.dir/t_console.cpp.o.requires:
.PHONY : console/CMakeFiles/t_console.dir/t_console.cpp.o.requires

console/CMakeFiles/t_console.dir/t_console.cpp.o.provides: console/CMakeFiles/t_console.dir/t_console.cpp.o.requires
	$(MAKE) -f console/CMakeFiles/t_console.dir/build.make console/CMakeFiles/t_console.dir/t_console.cpp.o.provides.build
.PHONY : console/CMakeFiles/t_console.dir/t_console.cpp.o.provides

console/CMakeFiles/t_console.dir/t_console.cpp.o.provides.build: console/CMakeFiles/t_console.dir/t_console.cpp.o

# Object files for target t_console
t_console_OBJECTS = \
"CMakeFiles/t_console.dir/t_time.cpp.o" \
"CMakeFiles/t_console.dir/t_console.cpp.o"

# External object files for target t_console
t_console_EXTERNAL_OBJECTS =

console/libt_console.a: console/CMakeFiles/t_console.dir/t_time.cpp.o
console/libt_console.a: console/CMakeFiles/t_console.dir/t_console.cpp.o
console/libt_console.a: console/CMakeFiles/t_console.dir/build.make
console/libt_console.a: console/CMakeFiles/t_console.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libt_console.a"
	cd /home/eric/perso/src/console && $(CMAKE_COMMAND) -P CMakeFiles/t_console.dir/cmake_clean_target.cmake
	cd /home/eric/perso/src/console && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/t_console.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
console/CMakeFiles/t_console.dir/build: console/libt_console.a
.PHONY : console/CMakeFiles/t_console.dir/build

console/CMakeFiles/t_console.dir/requires: console/CMakeFiles/t_console.dir/t_time.cpp.o.requires
console/CMakeFiles/t_console.dir/requires: console/CMakeFiles/t_console.dir/t_console.cpp.o.requires
.PHONY : console/CMakeFiles/t_console.dir/requires

console/CMakeFiles/t_console.dir/clean:
	cd /home/eric/perso/src/console && $(CMAKE_COMMAND) -P CMakeFiles/t_console.dir/cmake_clean.cmake
.PHONY : console/CMakeFiles/t_console.dir/clean

console/CMakeFiles/t_console.dir/depend:
	cd /home/eric/perso/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eric/perso/src /home/eric/perso/src/console /home/eric/perso/src /home/eric/perso/src/console /home/eric/perso/src/console/CMakeFiles/t_console.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : console/CMakeFiles/t_console.dir/depend

