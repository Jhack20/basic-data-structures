# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Circular_Linked_List.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Circular_Linked_List.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Circular_Linked_List.dir/flags.make

CMakeFiles/Circular_Linked_List.dir/main.cpp.obj: CMakeFiles/Circular_Linked_List.dir/flags.make
CMakeFiles/Circular_Linked_List.dir/main.cpp.obj: CMakeFiles/Circular_Linked_List.dir/includes_CXX.rsp
CMakeFiles/Circular_Linked_List.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Circular_Linked_List.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Circular_Linked_List.dir\main.cpp.obj -c "C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List\main.cpp"

CMakeFiles/Circular_Linked_List.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Circular_Linked_List.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List\main.cpp" > CMakeFiles\Circular_Linked_List.dir\main.cpp.i

CMakeFiles/Circular_Linked_List.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Circular_Linked_List.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List\main.cpp" -o CMakeFiles\Circular_Linked_List.dir\main.cpp.s

CMakeFiles/Circular_Linked_List.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Circular_Linked_List.dir/main.cpp.obj.requires

CMakeFiles/Circular_Linked_List.dir/main.cpp.obj.provides: CMakeFiles/Circular_Linked_List.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Circular_Linked_List.dir\build.make CMakeFiles/Circular_Linked_List.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Circular_Linked_List.dir/main.cpp.obj.provides

CMakeFiles/Circular_Linked_List.dir/main.cpp.obj.provides.build: CMakeFiles/Circular_Linked_List.dir/main.cpp.obj


# Object files for target Circular_Linked_List
Circular_Linked_List_OBJECTS = \
"CMakeFiles/Circular_Linked_List.dir/main.cpp.obj"

# External object files for target Circular_Linked_List
Circular_Linked_List_EXTERNAL_OBJECTS =

Circular_Linked_List.exe: CMakeFiles/Circular_Linked_List.dir/main.cpp.obj
Circular_Linked_List.exe: CMakeFiles/Circular_Linked_List.dir/build.make
Circular_Linked_List.exe: CMakeFiles/Circular_Linked_List.dir/linklibs.rsp
Circular_Linked_List.exe: CMakeFiles/Circular_Linked_List.dir/objects1.rsp
Circular_Linked_List.exe: CMakeFiles/Circular_Linked_List.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Circular_Linked_List.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Circular_Linked_List.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Circular_Linked_List.dir/build: Circular_Linked_List.exe

.PHONY : CMakeFiles/Circular_Linked_List.dir/build

CMakeFiles/Circular_Linked_List.dir/requires: CMakeFiles/Circular_Linked_List.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Circular_Linked_List.dir/requires

CMakeFiles/Circular_Linked_List.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Circular_Linked_List.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Circular_Linked_List.dir/clean

CMakeFiles/Circular_Linked_List.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List" "C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List" "C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List\cmake-build-debug" "C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List\cmake-build-debug" "C:\Users\matte\Documents\GitHub\basic-data-structures\Circular Linked List\cmake-build-debug\CMakeFiles\Circular_Linked_List.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Circular_Linked_List.dir/depend

