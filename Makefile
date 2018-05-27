# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/yun/vision/postit_localize

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yun/vision/postit_localize

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/yun/vision/postit_localize/CMakeFiles /home/yun/vision/postit_localize/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/yun/vision/postit_localize/CMakeFiles 0
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
# Target rules for targets named select_search

# Build rule for target.
select_search: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 select_search
.PHONY : select_search

# fast build rule for target.
select_search/fast:
	$(MAKE) -f CMakeFiles/select_search.dir/build.make CMakeFiles/select_search.dir/build
.PHONY : select_search/fast

#=============================================================================
# Target rules for targets named postit_detect

# Build rule for target.
postit_detect: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 postit_detect
.PHONY : postit_detect

# fast build rule for target.
postit_detect/fast:
	$(MAKE) -f CMakeFiles/postit_detect.dir/build.make CMakeFiles/postit_detect.dir/build
.PHONY : postit_detect/fast

postit_detect.o: postit_detect.cpp.o

.PHONY : postit_detect.o

# target to build an object file
postit_detect.cpp.o:
	$(MAKE) -f CMakeFiles/postit_detect.dir/build.make CMakeFiles/postit_detect.dir/postit_detect.cpp.o
.PHONY : postit_detect.cpp.o

postit_detect.i: postit_detect.cpp.i

.PHONY : postit_detect.i

# target to preprocess a source file
postit_detect.cpp.i:
	$(MAKE) -f CMakeFiles/postit_detect.dir/build.make CMakeFiles/postit_detect.dir/postit_detect.cpp.i
.PHONY : postit_detect.cpp.i

postit_detect.s: postit_detect.cpp.s

.PHONY : postit_detect.s

# target to generate assembly for a file
postit_detect.cpp.s:
	$(MAKE) -f CMakeFiles/postit_detect.dir/build.make CMakeFiles/postit_detect.dir/postit_detect.cpp.s
.PHONY : postit_detect.cpp.s

select_search.o: select_search.cpp.o

.PHONY : select_search.o

# target to build an object file
select_search.cpp.o:
	$(MAKE) -f CMakeFiles/select_search.dir/build.make CMakeFiles/select_search.dir/select_search.cpp.o
.PHONY : select_search.cpp.o

select_search.i: select_search.cpp.i

.PHONY : select_search.i

# target to preprocess a source file
select_search.cpp.i:
	$(MAKE) -f CMakeFiles/select_search.dir/build.make CMakeFiles/select_search.dir/select_search.cpp.i
.PHONY : select_search.cpp.i

select_search.s: select_search.cpp.s

.PHONY : select_search.s

# target to generate assembly for a file
select_search.cpp.s:
	$(MAKE) -f CMakeFiles/select_search.dir/build.make CMakeFiles/select_search.dir/select_search.cpp.s
.PHONY : select_search.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... select_search"
	@echo "... postit_detect"
	@echo "... postit_detect.o"
	@echo "... postit_detect.i"
	@echo "... postit_detect.s"
	@echo "... select_search.o"
	@echo "... select_search.i"
	@echo "... select_search.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
