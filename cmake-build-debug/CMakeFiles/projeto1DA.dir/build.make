# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /snap/clion/265/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/265/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tiago/2ano2sem/DA/projeto1DA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projeto1DA.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/projeto1DA.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/projeto1DA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projeto1DA.dir/flags.make

CMakeFiles/projeto1DA.dir/main.cpp.o: CMakeFiles/projeto1DA.dir/flags.make
CMakeFiles/projeto1DA.dir/main.cpp.o: /home/tiago/2ano2sem/DA/projeto1DA/main.cpp
CMakeFiles/projeto1DA.dir/main.cpp.o: CMakeFiles/projeto1DA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projeto1DA.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projeto1DA.dir/main.cpp.o -MF CMakeFiles/projeto1DA.dir/main.cpp.o.d -o CMakeFiles/projeto1DA.dir/main.cpp.o -c /home/tiago/2ano2sem/DA/projeto1DA/main.cpp

CMakeFiles/projeto1DA.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projeto1DA.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiago/2ano2sem/DA/projeto1DA/main.cpp > CMakeFiles/projeto1DA.dir/main.cpp.i

CMakeFiles/projeto1DA.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projeto1DA.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiago/2ano2sem/DA/projeto1DA/main.cpp -o CMakeFiles/projeto1DA.dir/main.cpp.s

CMakeFiles/projeto1DA.dir/src/Pipes.cpp.o: CMakeFiles/projeto1DA.dir/flags.make
CMakeFiles/projeto1DA.dir/src/Pipes.cpp.o: /home/tiago/2ano2sem/DA/projeto1DA/src/Pipes.cpp
CMakeFiles/projeto1DA.dir/src/Pipes.cpp.o: CMakeFiles/projeto1DA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/projeto1DA.dir/src/Pipes.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projeto1DA.dir/src/Pipes.cpp.o -MF CMakeFiles/projeto1DA.dir/src/Pipes.cpp.o.d -o CMakeFiles/projeto1DA.dir/src/Pipes.cpp.o -c /home/tiago/2ano2sem/DA/projeto1DA/src/Pipes.cpp

CMakeFiles/projeto1DA.dir/src/Pipes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projeto1DA.dir/src/Pipes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiago/2ano2sem/DA/projeto1DA/src/Pipes.cpp > CMakeFiles/projeto1DA.dir/src/Pipes.cpp.i

CMakeFiles/projeto1DA.dir/src/Pipes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projeto1DA.dir/src/Pipes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiago/2ano2sem/DA/projeto1DA/src/Pipes.cpp -o CMakeFiles/projeto1DA.dir/src/Pipes.cpp.s

CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.o: CMakeFiles/projeto1DA.dir/flags.make
CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.o: /home/tiago/2ano2sem/DA/projeto1DA/src/PumpingStations.cpp
CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.o: CMakeFiles/projeto1DA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.o -MF CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.o.d -o CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.o -c /home/tiago/2ano2sem/DA/projeto1DA/src/PumpingStations.cpp

CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiago/2ano2sem/DA/projeto1DA/src/PumpingStations.cpp > CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.i

CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiago/2ano2sem/DA/projeto1DA/src/PumpingStations.cpp -o CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.s

CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.o: CMakeFiles/projeto1DA.dir/flags.make
CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.o: /home/tiago/2ano2sem/DA/projeto1DA/src/WaterReservoir.cpp
CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.o: CMakeFiles/projeto1DA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.o -MF CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.o.d -o CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.o -c /home/tiago/2ano2sem/DA/projeto1DA/src/WaterReservoir.cpp

CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiago/2ano2sem/DA/projeto1DA/src/WaterReservoir.cpp > CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.i

CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiago/2ano2sem/DA/projeto1DA/src/WaterReservoir.cpp -o CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.s

CMakeFiles/projeto1DA.dir/src/Data.cpp.o: CMakeFiles/projeto1DA.dir/flags.make
CMakeFiles/projeto1DA.dir/src/Data.cpp.o: /home/tiago/2ano2sem/DA/projeto1DA/src/Data.cpp
CMakeFiles/projeto1DA.dir/src/Data.cpp.o: CMakeFiles/projeto1DA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/projeto1DA.dir/src/Data.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projeto1DA.dir/src/Data.cpp.o -MF CMakeFiles/projeto1DA.dir/src/Data.cpp.o.d -o CMakeFiles/projeto1DA.dir/src/Data.cpp.o -c /home/tiago/2ano2sem/DA/projeto1DA/src/Data.cpp

CMakeFiles/projeto1DA.dir/src/Data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projeto1DA.dir/src/Data.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiago/2ano2sem/DA/projeto1DA/src/Data.cpp > CMakeFiles/projeto1DA.dir/src/Data.cpp.i

CMakeFiles/projeto1DA.dir/src/Data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projeto1DA.dir/src/Data.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiago/2ano2sem/DA/projeto1DA/src/Data.cpp -o CMakeFiles/projeto1DA.dir/src/Data.cpp.s

CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.o: CMakeFiles/projeto1DA.dir/flags.make
CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.o: /home/tiago/2ano2sem/DA/projeto1DA/src/DeliverySites.cpp
CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.o: CMakeFiles/projeto1DA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.o -MF CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.o.d -o CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.o -c /home/tiago/2ano2sem/DA/projeto1DA/src/DeliverySites.cpp

CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiago/2ano2sem/DA/projeto1DA/src/DeliverySites.cpp > CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.i

CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiago/2ano2sem/DA/projeto1DA/src/DeliverySites.cpp -o CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.s

CMakeFiles/projeto1DA.dir/src/Window.cpp.o: CMakeFiles/projeto1DA.dir/flags.make
CMakeFiles/projeto1DA.dir/src/Window.cpp.o: /home/tiago/2ano2sem/DA/projeto1DA/src/Window.cpp
CMakeFiles/projeto1DA.dir/src/Window.cpp.o: CMakeFiles/projeto1DA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/projeto1DA.dir/src/Window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projeto1DA.dir/src/Window.cpp.o -MF CMakeFiles/projeto1DA.dir/src/Window.cpp.o.d -o CMakeFiles/projeto1DA.dir/src/Window.cpp.o -c /home/tiago/2ano2sem/DA/projeto1DA/src/Window.cpp

CMakeFiles/projeto1DA.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projeto1DA.dir/src/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiago/2ano2sem/DA/projeto1DA/src/Window.cpp > CMakeFiles/projeto1DA.dir/src/Window.cpp.i

CMakeFiles/projeto1DA.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projeto1DA.dir/src/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiago/2ano2sem/DA/projeto1DA/src/Window.cpp -o CMakeFiles/projeto1DA.dir/src/Window.cpp.s

CMakeFiles/projeto1DA.dir/src/Graph.cpp.o: CMakeFiles/projeto1DA.dir/flags.make
CMakeFiles/projeto1DA.dir/src/Graph.cpp.o: /home/tiago/2ano2sem/DA/projeto1DA/src/Graph.cpp
CMakeFiles/projeto1DA.dir/src/Graph.cpp.o: CMakeFiles/projeto1DA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/projeto1DA.dir/src/Graph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projeto1DA.dir/src/Graph.cpp.o -MF CMakeFiles/projeto1DA.dir/src/Graph.cpp.o.d -o CMakeFiles/projeto1DA.dir/src/Graph.cpp.o -c /home/tiago/2ano2sem/DA/projeto1DA/src/Graph.cpp

CMakeFiles/projeto1DA.dir/src/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projeto1DA.dir/src/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiago/2ano2sem/DA/projeto1DA/src/Graph.cpp > CMakeFiles/projeto1DA.dir/src/Graph.cpp.i

CMakeFiles/projeto1DA.dir/src/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projeto1DA.dir/src/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiago/2ano2sem/DA/projeto1DA/src/Graph.cpp -o CMakeFiles/projeto1DA.dir/src/Graph.cpp.s

CMakeFiles/projeto1DA.dir/src/Menu.cpp.o: CMakeFiles/projeto1DA.dir/flags.make
CMakeFiles/projeto1DA.dir/src/Menu.cpp.o: /home/tiago/2ano2sem/DA/projeto1DA/src/Menu.cpp
CMakeFiles/projeto1DA.dir/src/Menu.cpp.o: CMakeFiles/projeto1DA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/projeto1DA.dir/src/Menu.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projeto1DA.dir/src/Menu.cpp.o -MF CMakeFiles/projeto1DA.dir/src/Menu.cpp.o.d -o CMakeFiles/projeto1DA.dir/src/Menu.cpp.o -c /home/tiago/2ano2sem/DA/projeto1DA/src/Menu.cpp

CMakeFiles/projeto1DA.dir/src/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projeto1DA.dir/src/Menu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiago/2ano2sem/DA/projeto1DA/src/Menu.cpp > CMakeFiles/projeto1DA.dir/src/Menu.cpp.i

CMakeFiles/projeto1DA.dir/src/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projeto1DA.dir/src/Menu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiago/2ano2sem/DA/projeto1DA/src/Menu.cpp -o CMakeFiles/projeto1DA.dir/src/Menu.cpp.s

# Object files for target projeto1DA
projeto1DA_OBJECTS = \
"CMakeFiles/projeto1DA.dir/main.cpp.o" \
"CMakeFiles/projeto1DA.dir/src/Pipes.cpp.o" \
"CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.o" \
"CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.o" \
"CMakeFiles/projeto1DA.dir/src/Data.cpp.o" \
"CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.o" \
"CMakeFiles/projeto1DA.dir/src/Window.cpp.o" \
"CMakeFiles/projeto1DA.dir/src/Graph.cpp.o" \
"CMakeFiles/projeto1DA.dir/src/Menu.cpp.o"

# External object files for target projeto1DA
projeto1DA_EXTERNAL_OBJECTS =

projeto1DA: CMakeFiles/projeto1DA.dir/main.cpp.o
projeto1DA: CMakeFiles/projeto1DA.dir/src/Pipes.cpp.o
projeto1DA: CMakeFiles/projeto1DA.dir/src/PumpingStations.cpp.o
projeto1DA: CMakeFiles/projeto1DA.dir/src/WaterReservoir.cpp.o
projeto1DA: CMakeFiles/projeto1DA.dir/src/Data.cpp.o
projeto1DA: CMakeFiles/projeto1DA.dir/src/DeliverySites.cpp.o
projeto1DA: CMakeFiles/projeto1DA.dir/src/Window.cpp.o
projeto1DA: CMakeFiles/projeto1DA.dir/src/Graph.cpp.o
projeto1DA: CMakeFiles/projeto1DA.dir/src/Menu.cpp.o
projeto1DA: CMakeFiles/projeto1DA.dir/build.make
projeto1DA: CMakeFiles/projeto1DA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable projeto1DA"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projeto1DA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projeto1DA.dir/build: projeto1DA
.PHONY : CMakeFiles/projeto1DA.dir/build

CMakeFiles/projeto1DA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projeto1DA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projeto1DA.dir/clean

CMakeFiles/projeto1DA.dir/depend:
	cd /home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tiago/2ano2sem/DA/projeto1DA /home/tiago/2ano2sem/DA/projeto1DA /home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug /home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug /home/tiago/2ano2sem/DA/projeto1DA/cmake-build-debug/CMakeFiles/projeto1DA.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/projeto1DA.dir/depend

