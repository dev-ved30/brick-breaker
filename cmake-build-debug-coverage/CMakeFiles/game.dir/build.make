# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

Debug/game/game.app/Contents/Resources/CinderApp.icns: /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/samples/data/CinderApp.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content Debug/game/game.app/Contents/Resources/CinderApp.icns"
	$(CMAKE_COMMAND) -E copy /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/samples/data/CinderApp.icns Debug/game/game.app/Contents/Resources/CinderApp.icns

CMakeFiles/game.dir/apps/cinder_app_main.cc.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/apps/cinder_app_main.cc.o: ../apps/cinder_app_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/apps/cinder_app_main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/apps/cinder_app_main.cc.o -c /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/apps/cinder_app_main.cc

CMakeFiles/game.dir/apps/cinder_app_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/apps/cinder_app_main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/apps/cinder_app_main.cc > CMakeFiles/game.dir/apps/cinder_app_main.cc.i

CMakeFiles/game.dir/apps/cinder_app_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/apps/cinder_app_main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/apps/cinder_app_main.cc -o CMakeFiles/game.dir/apps/cinder_app_main.cc.s

CMakeFiles/game.dir/src/game.cc.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/game.cc.o: ../src/game.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/src/game.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/game.cc.o -c /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/game.cc

CMakeFiles/game.dir/src/game.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/game.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/game.cc > CMakeFiles/game.dir/src/game.cc.i

CMakeFiles/game.dir/src/game.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/game.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/game.cc -o CMakeFiles/game.dir/src/game.cc.s

CMakeFiles/game.dir/src/grid.cc.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/grid.cc.o: ../src/grid.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/src/grid.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/grid.cc.o -c /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/grid.cc

CMakeFiles/game.dir/src/grid.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/grid.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/grid.cc > CMakeFiles/game.dir/src/grid.cc.i

CMakeFiles/game.dir/src/grid.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/grid.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/grid.cc -o CMakeFiles/game.dir/src/grid.cc.s

CMakeFiles/game.dir/src/paddle.cc.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/paddle.cc.o: ../src/paddle.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/src/paddle.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/paddle.cc.o -c /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/paddle.cc

CMakeFiles/game.dir/src/paddle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/paddle.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/paddle.cc > CMakeFiles/game.dir/src/paddle.cc.i

CMakeFiles/game.dir/src/paddle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/paddle.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/paddle.cc -o CMakeFiles/game.dir/src/paddle.cc.s

CMakeFiles/game.dir/src/ball.cc.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/ball.cc.o: ../src/ball.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/src/ball.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/ball.cc.o -c /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/ball.cc

CMakeFiles/game.dir/src/ball.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/ball.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/ball.cc > CMakeFiles/game.dir/src/ball.cc.i

CMakeFiles/game.dir/src/ball.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/ball.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/ball.cc -o CMakeFiles/game.dir/src/ball.cc.s

CMakeFiles/game.dir/src/game_engine.cc.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/game_engine.cc.o: ../src/game_engine.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/src/game_engine.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/game_engine.cc.o -c /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/game_engine.cc

CMakeFiles/game.dir/src/game_engine.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/game_engine.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/game_engine.cc > CMakeFiles/game.dir/src/game_engine.cc.i

CMakeFiles/game.dir/src/game_engine.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/game_engine.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/game_engine.cc -o CMakeFiles/game.dir/src/game_engine.cc.s

CMakeFiles/game.dir/src/leader_board.cc.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/leader_board.cc.o: ../src/leader_board.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.dir/src/leader_board.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/leader_board.cc.o -c /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/leader_board.cc

CMakeFiles/game.dir/src/leader_board.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/leader_board.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/leader_board.cc > CMakeFiles/game.dir/src/leader_board.cc.i

CMakeFiles/game.dir/src/leader_board.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/leader_board.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/src/leader_board.cc -o CMakeFiles/game.dir/src/leader_board.cc.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/apps/cinder_app_main.cc.o" \
"CMakeFiles/game.dir/src/game.cc.o" \
"CMakeFiles/game.dir/src/grid.cc.o" \
"CMakeFiles/game.dir/src/paddle.cc.o" \
"CMakeFiles/game.dir/src/ball.cc.o" \
"CMakeFiles/game.dir/src/game_engine.cc.o" \
"CMakeFiles/game.dir/src/leader_board.cc.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

Debug/game/game.app/Contents/MacOS/game: CMakeFiles/game.dir/apps/cinder_app_main.cc.o
Debug/game/game.app/Contents/MacOS/game: CMakeFiles/game.dir/src/game.cc.o
Debug/game/game.app/Contents/MacOS/game: CMakeFiles/game.dir/src/grid.cc.o
Debug/game/game.app/Contents/MacOS/game: CMakeFiles/game.dir/src/paddle.cc.o
Debug/game/game.app/Contents/MacOS/game: CMakeFiles/game.dir/src/ball.cc.o
Debug/game/game.app/Contents/MacOS/game: CMakeFiles/game.dir/src/game_engine.cc.o
Debug/game/game.app/Contents/MacOS/game: CMakeFiles/game.dir/src/leader_board.cc.o
Debug/game/game.app/Contents/MacOS/game: CMakeFiles/game.dir/build.make
Debug/game/game.app/Contents/MacOS/game: /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/lib/macosx/Debug/libcinder.a
Debug/game/game.app/Contents/MacOS/game: /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/lib/macosx/libboost_system.a
Debug/game/game.app/Contents/MacOS/game: /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/lib/macosx/libboost_filesystem.a
Debug/game/game.app/Contents/MacOS/game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Debug/game/game.app/Contents/MacOS/game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: Debug/game/game.app/Contents/MacOS/game
CMakeFiles/game.dir/build: Debug/game/game.app/Contents/Resources/CinderApp.icns

.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30 /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30 /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage /Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/cmake-build-debug-coverage/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

