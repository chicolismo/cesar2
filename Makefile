# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/chico/Projects/cesar2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chico/Projects/cesar2

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
	$(CMAKE_COMMAND) -E cmake_progress_start /home/chico/Projects/cesar2/CMakeFiles /home/chico/Projects/cesar2/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/chico/Projects/cesar2/CMakeFiles 0
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
# Target rules for targets named cesar

# Build rule for target.
cesar: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 cesar
.PHONY : cesar

# fast build rule for target.
cesar/fast:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/build
.PHONY : cesar/fast

CPU.o: CPU.cpp.o

.PHONY : CPU.o

# target to build an object file
CPU.cpp.o:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/CPU.cpp.o
.PHONY : CPU.cpp.o

CPU.i: CPU.cpp.i

.PHONY : CPU.i

# target to preprocess a source file
CPU.cpp.i:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/CPU.cpp.i
.PHONY : CPU.cpp.i

CPU.s: CPU.cpp.s

.PHONY : CPU.s

# target to generate assembly for a file
CPU.cpp.s:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/CPU.cpp.s
.PHONY : CPU.cpp.s

DataTable.o: DataTable.cpp.o

.PHONY : DataTable.o

# target to build an object file
DataTable.cpp.o:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/DataTable.cpp.o
.PHONY : DataTable.cpp.o

DataTable.i: DataTable.cpp.i

.PHONY : DataTable.i

# target to preprocess a source file
DataTable.cpp.i:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/DataTable.cpp.i
.PHONY : DataTable.cpp.i

DataTable.s: DataTable.cpp.s

.PHONY : DataTable.s

# target to generate assembly for a file
DataTable.cpp.s:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/DataTable.cpp.s
.PHONY : DataTable.cpp.s

ExecutionPanel.o: ExecutionPanel.cpp.o

.PHONY : ExecutionPanel.o

# target to build an object file
ExecutionPanel.cpp.o:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/ExecutionPanel.cpp.o
.PHONY : ExecutionPanel.cpp.o

ExecutionPanel.i: ExecutionPanel.cpp.i

.PHONY : ExecutionPanel.i

# target to preprocess a source file
ExecutionPanel.cpp.i:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/ExecutionPanel.cpp.i
.PHONY : ExecutionPanel.cpp.i

ExecutionPanel.s: ExecutionPanel.cpp.s

.PHONY : ExecutionPanel.s

# target to generate assembly for a file
ExecutionPanel.cpp.s:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/ExecutionPanel.cpp.s
.PHONY : ExecutionPanel.cpp.s

Main.o: Main.cpp.o

.PHONY : Main.o

# target to build an object file
Main.cpp.o:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/Main.cpp.o
.PHONY : Main.cpp.o

Main.i: Main.cpp.i

.PHONY : Main.i

# target to preprocess a source file
Main.cpp.i:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/Main.cpp.i
.PHONY : Main.cpp.i

Main.s: Main.cpp.s

.PHONY : Main.s

# target to generate assembly for a file
Main.cpp.s:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/Main.cpp.s
.PHONY : Main.cpp.s

MainFrame.o: MainFrame.cpp.o

.PHONY : MainFrame.o

# target to build an object file
MainFrame.cpp.o:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/MainFrame.cpp.o
.PHONY : MainFrame.cpp.o

MainFrame.i: MainFrame.cpp.i

.PHONY : MainFrame.i

# target to preprocess a source file
MainFrame.cpp.i:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/MainFrame.cpp.i
.PHONY : MainFrame.cpp.i

MainFrame.s: MainFrame.cpp.s

.PHONY : MainFrame.s

# target to generate assembly for a file
MainFrame.cpp.s:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/MainFrame.cpp.s
.PHONY : MainFrame.cpp.s

ProgramTable.o: ProgramTable.cpp.o

.PHONY : ProgramTable.o

# target to build an object file
ProgramTable.cpp.o:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/ProgramTable.cpp.o
.PHONY : ProgramTable.cpp.o

ProgramTable.i: ProgramTable.cpp.i

.PHONY : ProgramTable.i

# target to preprocess a source file
ProgramTable.cpp.i:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/ProgramTable.cpp.i
.PHONY : ProgramTable.cpp.i

ProgramTable.s: ProgramTable.cpp.s

.PHONY : ProgramTable.s

# target to generate assembly for a file
ProgramTable.cpp.s:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/ProgramTable.cpp.s
.PHONY : ProgramTable.cpp.s

Register.o: Register.cpp.o

.PHONY : Register.o

# target to build an object file
Register.cpp.o:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/Register.cpp.o
.PHONY : Register.cpp.o

Register.i: Register.cpp.i

.PHONY : Register.i

# target to preprocess a source file
Register.cpp.i:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/Register.cpp.i
.PHONY : Register.cpp.i

Register.s: Register.cpp.s

.PHONY : Register.s

# target to generate assembly for a file
Register.cpp.s:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/Register.cpp.s
.PHONY : Register.cpp.s

SidePanel.o: SidePanel.cpp.o

.PHONY : SidePanel.o

# target to build an object file
SidePanel.cpp.o:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/SidePanel.cpp.o
.PHONY : SidePanel.cpp.o

SidePanel.i: SidePanel.cpp.i

.PHONY : SidePanel.i

# target to preprocess a source file
SidePanel.cpp.i:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/SidePanel.cpp.i
.PHONY : SidePanel.cpp.i

SidePanel.s: SidePanel.cpp.s

.PHONY : SidePanel.s

# target to generate assembly for a file
SidePanel.cpp.s:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/SidePanel.cpp.s
.PHONY : SidePanel.cpp.s

Table.o: Table.cpp.o

.PHONY : Table.o

# target to build an object file
Table.cpp.o:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/Table.cpp.o
.PHONY : Table.cpp.o

Table.i: Table.cpp.i

.PHONY : Table.i

# target to preprocess a source file
Table.cpp.i:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/Table.cpp.i
.PHONY : Table.cpp.i

Table.s: Table.cpp.s

.PHONY : Table.s

# target to generate assembly for a file
Table.cpp.s:
	$(MAKE) -f CMakeFiles/cesar.dir/build.make CMakeFiles/cesar.dir/Table.cpp.s
.PHONY : Table.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... cesar"
	@echo "... CPU.o"
	@echo "... CPU.i"
	@echo "... CPU.s"
	@echo "... DataTable.o"
	@echo "... DataTable.i"
	@echo "... DataTable.s"
	@echo "... ExecutionPanel.o"
	@echo "... ExecutionPanel.i"
	@echo "... ExecutionPanel.s"
	@echo "... Main.o"
	@echo "... Main.i"
	@echo "... Main.s"
	@echo "... MainFrame.o"
	@echo "... MainFrame.i"
	@echo "... MainFrame.s"
	@echo "... ProgramTable.o"
	@echo "... ProgramTable.i"
	@echo "... ProgramTable.s"
	@echo "... Register.o"
	@echo "... Register.i"
	@echo "... Register.s"
	@echo "... SidePanel.o"
	@echo "... SidePanel.i"
	@echo "... SidePanel.s"
	@echo "... Table.o"
	@echo "... Table.i"
	@echo "... Table.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

