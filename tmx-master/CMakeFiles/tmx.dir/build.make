# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/dude/Github Projects/Archer-Fight/tmx-master"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/dude/Github Projects/Archer-Fight/tmx-master"

# Include any dependencies generated for this target.
include CMakeFiles/tmx.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tmx.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tmx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tmx.dir/flags.make

CMakeFiles/tmx.dir/src/tmx.c.o: CMakeFiles/tmx.dir/flags.make
CMakeFiles/tmx.dir/src/tmx.c.o: src/tmx.c
CMakeFiles/tmx.dir/src/tmx.c.o: CMakeFiles/tmx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/dude/Github Projects/Archer-Fight/tmx-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tmx.dir/src/tmx.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tmx.dir/src/tmx.c.o -MF CMakeFiles/tmx.dir/src/tmx.c.o.d -o CMakeFiles/tmx.dir/src/tmx.c.o -c "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx.c"

CMakeFiles/tmx.dir/src/tmx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tmx.dir/src/tmx.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx.c" > CMakeFiles/tmx.dir/src/tmx.c.i

CMakeFiles/tmx.dir/src/tmx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tmx.dir/src/tmx.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx.c" -o CMakeFiles/tmx.dir/src/tmx.c.s

CMakeFiles/tmx.dir/src/tmx_utils.c.o: CMakeFiles/tmx.dir/flags.make
CMakeFiles/tmx.dir/src/tmx_utils.c.o: src/tmx_utils.c
CMakeFiles/tmx.dir/src/tmx_utils.c.o: CMakeFiles/tmx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/dude/Github Projects/Archer-Fight/tmx-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tmx.dir/src/tmx_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tmx.dir/src/tmx_utils.c.o -MF CMakeFiles/tmx.dir/src/tmx_utils.c.o.d -o CMakeFiles/tmx.dir/src/tmx_utils.c.o -c "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_utils.c"

CMakeFiles/tmx.dir/src/tmx_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tmx.dir/src/tmx_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_utils.c" > CMakeFiles/tmx.dir/src/tmx_utils.c.i

CMakeFiles/tmx.dir/src/tmx_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tmx.dir/src/tmx_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_utils.c" -o CMakeFiles/tmx.dir/src/tmx_utils.c.s

CMakeFiles/tmx.dir/src/tmx_err.c.o: CMakeFiles/tmx.dir/flags.make
CMakeFiles/tmx.dir/src/tmx_err.c.o: src/tmx_err.c
CMakeFiles/tmx.dir/src/tmx_err.c.o: CMakeFiles/tmx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/dude/Github Projects/Archer-Fight/tmx-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/tmx.dir/src/tmx_err.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tmx.dir/src/tmx_err.c.o -MF CMakeFiles/tmx.dir/src/tmx_err.c.o.d -o CMakeFiles/tmx.dir/src/tmx_err.c.o -c "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_err.c"

CMakeFiles/tmx.dir/src/tmx_err.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tmx.dir/src/tmx_err.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_err.c" > CMakeFiles/tmx.dir/src/tmx_err.c.i

CMakeFiles/tmx.dir/src/tmx_err.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tmx.dir/src/tmx_err.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_err.c" -o CMakeFiles/tmx.dir/src/tmx_err.c.s

CMakeFiles/tmx.dir/src/tmx_xml.c.o: CMakeFiles/tmx.dir/flags.make
CMakeFiles/tmx.dir/src/tmx_xml.c.o: src/tmx_xml.c
CMakeFiles/tmx.dir/src/tmx_xml.c.o: CMakeFiles/tmx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/dude/Github Projects/Archer-Fight/tmx-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/tmx.dir/src/tmx_xml.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tmx.dir/src/tmx_xml.c.o -MF CMakeFiles/tmx.dir/src/tmx_xml.c.o.d -o CMakeFiles/tmx.dir/src/tmx_xml.c.o -c "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_xml.c"

CMakeFiles/tmx.dir/src/tmx_xml.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tmx.dir/src/tmx_xml.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_xml.c" > CMakeFiles/tmx.dir/src/tmx_xml.c.i

CMakeFiles/tmx.dir/src/tmx_xml.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tmx.dir/src/tmx_xml.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_xml.c" -o CMakeFiles/tmx.dir/src/tmx_xml.c.s

CMakeFiles/tmx.dir/src/tmx_mem.c.o: CMakeFiles/tmx.dir/flags.make
CMakeFiles/tmx.dir/src/tmx_mem.c.o: src/tmx_mem.c
CMakeFiles/tmx.dir/src/tmx_mem.c.o: CMakeFiles/tmx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/dude/Github Projects/Archer-Fight/tmx-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/tmx.dir/src/tmx_mem.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tmx.dir/src/tmx_mem.c.o -MF CMakeFiles/tmx.dir/src/tmx_mem.c.o.d -o CMakeFiles/tmx.dir/src/tmx_mem.c.o -c "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_mem.c"

CMakeFiles/tmx.dir/src/tmx_mem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tmx.dir/src/tmx_mem.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_mem.c" > CMakeFiles/tmx.dir/src/tmx_mem.c.i

CMakeFiles/tmx.dir/src/tmx_mem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tmx.dir/src/tmx_mem.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_mem.c" -o CMakeFiles/tmx.dir/src/tmx_mem.c.s

CMakeFiles/tmx.dir/src/tmx_hash.c.o: CMakeFiles/tmx.dir/flags.make
CMakeFiles/tmx.dir/src/tmx_hash.c.o: src/tmx_hash.c
CMakeFiles/tmx.dir/src/tmx_hash.c.o: CMakeFiles/tmx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/dude/Github Projects/Archer-Fight/tmx-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/tmx.dir/src/tmx_hash.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tmx.dir/src/tmx_hash.c.o -MF CMakeFiles/tmx.dir/src/tmx_hash.c.o.d -o CMakeFiles/tmx.dir/src/tmx_hash.c.o -c "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_hash.c"

CMakeFiles/tmx.dir/src/tmx_hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tmx.dir/src/tmx_hash.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_hash.c" > CMakeFiles/tmx.dir/src/tmx_hash.c.i

CMakeFiles/tmx.dir/src/tmx_hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tmx.dir/src/tmx_hash.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/dude/Github Projects/Archer-Fight/tmx-master/src/tmx_hash.c" -o CMakeFiles/tmx.dir/src/tmx_hash.c.s

# Object files for target tmx
tmx_OBJECTS = \
"CMakeFiles/tmx.dir/src/tmx.c.o" \
"CMakeFiles/tmx.dir/src/tmx_utils.c.o" \
"CMakeFiles/tmx.dir/src/tmx_err.c.o" \
"CMakeFiles/tmx.dir/src/tmx_xml.c.o" \
"CMakeFiles/tmx.dir/src/tmx_mem.c.o" \
"CMakeFiles/tmx.dir/src/tmx_hash.c.o"

# External object files for target tmx
tmx_EXTERNAL_OBJECTS =

libtmx.a: CMakeFiles/tmx.dir/src/tmx.c.o
libtmx.a: CMakeFiles/tmx.dir/src/tmx_utils.c.o
libtmx.a: CMakeFiles/tmx.dir/src/tmx_err.c.o
libtmx.a: CMakeFiles/tmx.dir/src/tmx_xml.c.o
libtmx.a: CMakeFiles/tmx.dir/src/tmx_mem.c.o
libtmx.a: CMakeFiles/tmx.dir/src/tmx_hash.c.o
libtmx.a: CMakeFiles/tmx.dir/build.make
libtmx.a: CMakeFiles/tmx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/dude/Github Projects/Archer-Fight/tmx-master/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library libtmx.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tmx.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tmx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tmx.dir/build: libtmx.a
.PHONY : CMakeFiles/tmx.dir/build

CMakeFiles/tmx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tmx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tmx.dir/clean

CMakeFiles/tmx.dir/depend:
	cd "/home/dude/Github Projects/Archer-Fight/tmx-master" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/dude/Github Projects/Archer-Fight/tmx-master" "/home/dude/Github Projects/Archer-Fight/tmx-master" "/home/dude/Github Projects/Archer-Fight/tmx-master" "/home/dude/Github Projects/Archer-Fight/tmx-master" "/home/dude/Github Projects/Archer-Fight/tmx-master/CMakeFiles/tmx.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tmx.dir/depend

