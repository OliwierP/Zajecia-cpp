# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ZadClassKcpp.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ZadClassKcpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ZadClassKcpp.dir/flags.make

CMakeFiles/ZadClassKcpp.dir/main.cpp.obj: CMakeFiles/ZadClassKcpp.dir/flags.make
CMakeFiles/ZadClassKcpp.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ZadClassKcpp.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ZadClassKcpp.dir\main.cpp.obj -c E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp\main.cpp

CMakeFiles/ZadClassKcpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZadClassKcpp.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp\main.cpp > CMakeFiles\ZadClassKcpp.dir\main.cpp.i

CMakeFiles/ZadClassKcpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZadClassKcpp.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp\main.cpp -o CMakeFiles\ZadClassKcpp.dir\main.cpp.s

# Object files for target ZadClassKcpp
ZadClassKcpp_OBJECTS = \
"CMakeFiles/ZadClassKcpp.dir/main.cpp.obj"

# External object files for target ZadClassKcpp
ZadClassKcpp_EXTERNAL_OBJECTS =

ZadClassKcpp.exe: CMakeFiles/ZadClassKcpp.dir/main.cpp.obj
ZadClassKcpp.exe: CMakeFiles/ZadClassKcpp.dir/build.make
ZadClassKcpp.exe: CMakeFiles/ZadClassKcpp.dir/linklibs.rsp
ZadClassKcpp.exe: CMakeFiles/ZadClassKcpp.dir/objects1.rsp
ZadClassKcpp.exe: CMakeFiles/ZadClassKcpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ZadClassKcpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ZadClassKcpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ZadClassKcpp.dir/build: ZadClassKcpp.exe
.PHONY : CMakeFiles/ZadClassKcpp.dir/build

CMakeFiles/ZadClassKcpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ZadClassKcpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ZadClassKcpp.dir/clean

CMakeFiles/ZadClassKcpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp\cmake-build-debug E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp\cmake-build-debug E:\Lab_Cpp\Zajecia-cpp\Labs\ZadClassKcpp\cmake-build-debug\CMakeFiles\ZadClassKcpp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ZadClassKcpp.dir/depend
