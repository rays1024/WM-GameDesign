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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangqingjiu/Desktop/WM-GameDesign

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangqingjiu/Desktop/WM-GameDesign/build

# Include any dependencies generated for this target.
include CMakeFiles/WM-GameDesign_core.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WM-GameDesign_core.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WM-GameDesign_core.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WM-GameDesign_core.dir/flags.make

CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.o: ../src/AIView.cpp
CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/AIView.cpp

CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/AIView.cpp > CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/AIView.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.o: ../src/ActiveActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/ActiveActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/ActiveActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/ActiveActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.o: ../src/ActiveProcess.cpp
CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/ActiveProcess.cpp

CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/ActiveProcess.cpp > CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/ActiveProcess.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.o: ../src/FlyingEnemyActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/FlyingEnemyActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/FlyingEnemyActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/FlyingEnemyActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.o: ../src/InactiveActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/InactiveActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/InactiveActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/InactiveActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.o: ../src/InactiveProcess.cpp
CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/InactiveProcess.cpp

CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/InactiveProcess.cpp > CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/InactiveProcess.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.o: ../src/LegActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/LegActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/LegActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/LegActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.o: ../src/LobbingEnemyActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/LobbingEnemyActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/LobbingEnemyActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/LobbingEnemyActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.o: ../src/PickupActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/PickupActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/PickupActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/PickupActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.o: ../src/PlatformActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlatformActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlatformActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlatformActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.o: ../src/PlayerActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlayerActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlayerActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlayerActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.o: ../src/PlayerProcess.cpp
CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlayerProcess.cpp

CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlayerProcess.cpp > CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlayerProcess.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.o: ../src/PlayerView.cpp
CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlayerView.cpp

CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlayerView.cpp > CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/PlayerView.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.o: ../src/ProcessManager.cpp
CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/ProcessManager.cpp

CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/ProcessManager.cpp > CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/ProcessManager.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.o: ../src/ProjectileActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/ProjectileActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/ProjectileActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/ProjectileActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.o: ../src/SpikeActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/SpikeActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/SpikeActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/SpikeActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.o: ../src/TyrantulaActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/TyrantulaActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/TyrantulaActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/TyrantulaActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.o: ../src/WalkingEnemyActor.cpp
CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/WalkingEnemyActor.cpp

CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/WalkingEnemyActor.cpp > CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/WalkingEnemyActor.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.s

CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.o: CMakeFiles/WM-GameDesign_core.dir/flags.make
CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.o: ../src/tinyxml2.cpp
CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.o: CMakeFiles/WM-GameDesign_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.o -MF CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.o.d -o CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.o -c /Users/wangqingjiu/Desktop/WM-GameDesign/src/tinyxml2.cpp

CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqingjiu/Desktop/WM-GameDesign/src/tinyxml2.cpp > CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.i

CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqingjiu/Desktop/WM-GameDesign/src/tinyxml2.cpp -o CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.s

# Object files for target WM-GameDesign_core
WM__GameDesign_core_OBJECTS = \
"CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.o" \
"CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.o"

# External object files for target WM-GameDesign_core
WM__GameDesign_core_EXTERNAL_OBJECTS =

libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/AIView.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/ActiveActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/ActiveProcess.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/FlyingEnemyActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/InactiveActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/InactiveProcess.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/LegActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/LobbingEnemyActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/PickupActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/PlatformActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/PlayerActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/PlayerProcess.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/PlayerView.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/ProcessManager.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/ProjectileActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/SpikeActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/TyrantulaActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/WalkingEnemyActor.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/src/tinyxml2.cpp.o
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/build.make
libWM-GameDesign_core.a: CMakeFiles/WM-GameDesign_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX static library libWM-GameDesign_core.a"
	$(CMAKE_COMMAND) -P CMakeFiles/WM-GameDesign_core.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WM-GameDesign_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WM-GameDesign_core.dir/build: libWM-GameDesign_core.a
.PHONY : CMakeFiles/WM-GameDesign_core.dir/build

CMakeFiles/WM-GameDesign_core.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WM-GameDesign_core.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WM-GameDesign_core.dir/clean

CMakeFiles/WM-GameDesign_core.dir/depend:
	cd /Users/wangqingjiu/Desktop/WM-GameDesign/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangqingjiu/Desktop/WM-GameDesign /Users/wangqingjiu/Desktop/WM-GameDesign /Users/wangqingjiu/Desktop/WM-GameDesign/build /Users/wangqingjiu/Desktop/WM-GameDesign/build /Users/wangqingjiu/Desktop/WM-GameDesign/build/CMakeFiles/WM-GameDesign_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WM-GameDesign_core.dir/depend
