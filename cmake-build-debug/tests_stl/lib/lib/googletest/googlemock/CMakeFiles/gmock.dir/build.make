# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rjoella/Desktop/ft_containers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rjoella/Desktop/ft_containers/cmake-build-debug

# Include any dependencies generated for this target.
include tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/flags.make

tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/flags.make
tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../tests_stl/lib/googletest/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rjoella/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /Users/rjoella/Desktop/ft_containers/cmake-build-debug/tests_stl/lib/lib/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /Users/rjoella/Desktop/ft_containers/tests_stl/lib/googletest/googlemock/src/gmock-all.cc

tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /Users/rjoella/Desktop/ft_containers/cmake-build-debug/tests_stl/lib/lib/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rjoella/Desktop/ft_containers/tests_stl/lib/googletest/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /Users/rjoella/Desktop/ft_containers/cmake-build-debug/tests_stl/lib/lib/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rjoella/Desktop/ft_containers/tests_stl/lib/googletest/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmockd.a: tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
lib/libgmockd.a: tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmockd.a: tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rjoella/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../../lib/libgmockd.a"
	cd /Users/rjoella/Desktop/ft_containers/cmake-build-debug/tests_stl/lib/lib/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /Users/rjoella/Desktop/ft_containers/cmake-build-debug/tests_stl/lib/lib/googletest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/build: lib/libgmockd.a

.PHONY : tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/build

tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/clean:
	cd /Users/rjoella/Desktop/ft_containers/cmake-build-debug/tests_stl/lib/lib/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/clean

tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend:
	cd /Users/rjoella/Desktop/ft_containers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rjoella/Desktop/ft_containers /Users/rjoella/Desktop/ft_containers/tests_stl/lib/googletest/googlemock /Users/rjoella/Desktop/ft_containers/cmake-build-debug /Users/rjoella/Desktop/ft_containers/cmake-build-debug/tests_stl/lib/lib/googletest/googlemock /Users/rjoella/Desktop/ft_containers/cmake-build-debug/tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests_stl/lib/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend
