# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/hunter/Desktop/intruder-detector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hunter/Desktop/intruder-detector

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/hunter/Desktop/intruder-detector/CMakeFiles /home/hunter/Desktop/intruder-detector/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/hunter/Desktop/intruder-detector/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named robcatch

# Build rule for target.
robcatch: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 robcatch
.PHONY : robcatch

# fast build rule for target.
robcatch/fast:
	$(MAKE) -f CMakeFiles/robcatch.dir/build.make CMakeFiles/robcatch.dir/build
.PHONY : robcatch/fast

robcatch.o: robcatch.cpp.o

.PHONY : robcatch.o

# target to build an object file
robcatch.cpp.o:
	$(MAKE) -f CMakeFiles/robcatch.dir/build.make CMakeFiles/robcatch.dir/robcatch.cpp.o
.PHONY : robcatch.cpp.o

robcatch.i: robcatch.cpp.i

.PHONY : robcatch.i

# target to preprocess a source file
robcatch.cpp.i:
	$(MAKE) -f CMakeFiles/robcatch.dir/build.make CMakeFiles/robcatch.dir/robcatch.cpp.i
.PHONY : robcatch.cpp.i

robcatch.s: robcatch.cpp.s

.PHONY : robcatch.s

# target to generate assembly for a file
robcatch.cpp.s:
	$(MAKE) -f CMakeFiles/robcatch.dir/build.make CMakeFiles/robcatch.dir/robcatch.cpp.s
.PHONY : robcatch.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... robcatch"
	@echo "... edit_cache"
	@echo "... robcatch.o"
	@echo "... robcatch.i"
	@echo "... robcatch.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

