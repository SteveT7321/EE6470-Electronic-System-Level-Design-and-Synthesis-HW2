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
CMAKE_SOURCE_DIR = /home/user/ee6470/HW2/mmfilter_tlm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/ee6470/HW2/mmfilter_tlm/build

# Include any dependencies generated for this target.
include CMakeFiles/mm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mm.dir/flags.make

CMakeFiles/mm.dir/Initiator.cpp.o: CMakeFiles/mm.dir/flags.make
CMakeFiles/mm.dir/Initiator.cpp.o: ../Initiator.cpp
CMakeFiles/mm.dir/Initiator.cpp.o: CMakeFiles/mm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ee6470/HW2/mmfilter_tlm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mm.dir/Initiator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mm.dir/Initiator.cpp.o -MF CMakeFiles/mm.dir/Initiator.cpp.o.d -o CMakeFiles/mm.dir/Initiator.cpp.o -c /home/user/ee6470/HW2/mmfilter_tlm/Initiator.cpp

CMakeFiles/mm.dir/Initiator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mm.dir/Initiator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ee6470/HW2/mmfilter_tlm/Initiator.cpp > CMakeFiles/mm.dir/Initiator.cpp.i

CMakeFiles/mm.dir/Initiator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mm.dir/Initiator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ee6470/HW2/mmfilter_tlm/Initiator.cpp -o CMakeFiles/mm.dir/Initiator.cpp.s

CMakeFiles/mm.dir/MMFilter.cpp.o: CMakeFiles/mm.dir/flags.make
CMakeFiles/mm.dir/MMFilter.cpp.o: ../MMFilter.cpp
CMakeFiles/mm.dir/MMFilter.cpp.o: CMakeFiles/mm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ee6470/HW2/mmfilter_tlm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mm.dir/MMFilter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mm.dir/MMFilter.cpp.o -MF CMakeFiles/mm.dir/MMFilter.cpp.o.d -o CMakeFiles/mm.dir/MMFilter.cpp.o -c /home/user/ee6470/HW2/mmfilter_tlm/MMFilter.cpp

CMakeFiles/mm.dir/MMFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mm.dir/MMFilter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ee6470/HW2/mmfilter_tlm/MMFilter.cpp > CMakeFiles/mm.dir/MMFilter.cpp.i

CMakeFiles/mm.dir/MMFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mm.dir/MMFilter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ee6470/HW2/mmfilter_tlm/MMFilter.cpp -o CMakeFiles/mm.dir/MMFilter.cpp.s

CMakeFiles/mm.dir/Testbench.cpp.o: CMakeFiles/mm.dir/flags.make
CMakeFiles/mm.dir/Testbench.cpp.o: ../Testbench.cpp
CMakeFiles/mm.dir/Testbench.cpp.o: CMakeFiles/mm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ee6470/HW2/mmfilter_tlm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mm.dir/Testbench.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mm.dir/Testbench.cpp.o -MF CMakeFiles/mm.dir/Testbench.cpp.o.d -o CMakeFiles/mm.dir/Testbench.cpp.o -c /home/user/ee6470/HW2/mmfilter_tlm/Testbench.cpp

CMakeFiles/mm.dir/Testbench.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mm.dir/Testbench.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ee6470/HW2/mmfilter_tlm/Testbench.cpp > CMakeFiles/mm.dir/Testbench.cpp.i

CMakeFiles/mm.dir/Testbench.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mm.dir/Testbench.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ee6470/HW2/mmfilter_tlm/Testbench.cpp -o CMakeFiles/mm.dir/Testbench.cpp.s

CMakeFiles/mm.dir/main.cpp.o: CMakeFiles/mm.dir/flags.make
CMakeFiles/mm.dir/main.cpp.o: ../main.cpp
CMakeFiles/mm.dir/main.cpp.o: CMakeFiles/mm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ee6470/HW2/mmfilter_tlm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mm.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mm.dir/main.cpp.o -MF CMakeFiles/mm.dir/main.cpp.o.d -o CMakeFiles/mm.dir/main.cpp.o -c /home/user/ee6470/HW2/mmfilter_tlm/main.cpp

CMakeFiles/mm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mm.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ee6470/HW2/mmfilter_tlm/main.cpp > CMakeFiles/mm.dir/main.cpp.i

CMakeFiles/mm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mm.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ee6470/HW2/mmfilter_tlm/main.cpp -o CMakeFiles/mm.dir/main.cpp.s

# Object files for target mm
mm_OBJECTS = \
"CMakeFiles/mm.dir/Initiator.cpp.o" \
"CMakeFiles/mm.dir/MMFilter.cpp.o" \
"CMakeFiles/mm.dir/Testbench.cpp.o" \
"CMakeFiles/mm.dir/main.cpp.o"

# External object files for target mm
mm_EXTERNAL_OBJECTS =

mm: CMakeFiles/mm.dir/Initiator.cpp.o
mm: CMakeFiles/mm.dir/MMFilter.cpp.o
mm: CMakeFiles/mm.dir/Testbench.cpp.o
mm: CMakeFiles/mm.dir/main.cpp.o
mm: CMakeFiles/mm.dir/build.make
mm: /opt/systemc/lib/libsystemc.so.2.3.3
mm: CMakeFiles/mm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/ee6470/HW2/mmfilter_tlm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable mm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mm.dir/build: mm
.PHONY : CMakeFiles/mm.dir/build

CMakeFiles/mm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mm.dir/clean

CMakeFiles/mm.dir/depend:
	cd /home/user/ee6470/HW2/mmfilter_tlm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/ee6470/HW2/mmfilter_tlm /home/user/ee6470/HW2/mmfilter_tlm /home/user/ee6470/HW2/mmfilter_tlm/build /home/user/ee6470/HW2/mmfilter_tlm/build /home/user/ee6470/HW2/mmfilter_tlm/build/CMakeFiles/mm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mm.dir/depend

