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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ssasu\Desktop\Trabalho

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Trabalho.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Trabalho.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Trabalho.dir/flags.make

CMakeFiles/Trabalho.dir/main.cpp.obj: CMakeFiles/Trabalho.dir/flags.make
CMakeFiles/Trabalho.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Trabalho.dir/main.cpp.obj"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Trabalho.dir\main.cpp.obj -c C:\Users\ssasu\Desktop\Trabalho\main.cpp

CMakeFiles/Trabalho.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho.dir/main.cpp.i"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ssasu\Desktop\Trabalho\main.cpp > CMakeFiles\Trabalho.dir\main.cpp.i

CMakeFiles/Trabalho.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho.dir/main.cpp.s"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ssasu\Desktop\Trabalho\main.cpp -o CMakeFiles\Trabalho.dir\main.cpp.s

CMakeFiles/Trabalho.dir/map.cpp.obj: CMakeFiles/Trabalho.dir/flags.make
CMakeFiles/Trabalho.dir/map.cpp.obj: ../map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Trabalho.dir/map.cpp.obj"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Trabalho.dir\map.cpp.obj -c C:\Users\ssasu\Desktop\Trabalho\map.cpp

CMakeFiles/Trabalho.dir/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho.dir/map.cpp.i"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ssasu\Desktop\Trabalho\map.cpp > CMakeFiles\Trabalho.dir\map.cpp.i

CMakeFiles/Trabalho.dir/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho.dir/map.cpp.s"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ssasu\Desktop\Trabalho\map.cpp -o CMakeFiles\Trabalho.dir\map.cpp.s

CMakeFiles/Trabalho.dir/trabalhadores.cpp.obj: CMakeFiles/Trabalho.dir/flags.make
CMakeFiles/Trabalho.dir/trabalhadores.cpp.obj: ../trabalhadores.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Trabalho.dir/trabalhadores.cpp.obj"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Trabalho.dir\trabalhadores.cpp.obj -c C:\Users\ssasu\Desktop\Trabalho\trabalhadores.cpp

CMakeFiles/Trabalho.dir/trabalhadores.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho.dir/trabalhadores.cpp.i"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ssasu\Desktop\Trabalho\trabalhadores.cpp > CMakeFiles\Trabalho.dir\trabalhadores.cpp.i

CMakeFiles/Trabalho.dir/trabalhadores.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho.dir/trabalhadores.cpp.s"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ssasu\Desktop\Trabalho\trabalhadores.cpp -o CMakeFiles\Trabalho.dir\trabalhadores.cpp.s

CMakeFiles/Trabalho.dir/comandos.cpp.obj: CMakeFiles/Trabalho.dir/flags.make
CMakeFiles/Trabalho.dir/comandos.cpp.obj: ../comandos.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Trabalho.dir/comandos.cpp.obj"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Trabalho.dir\comandos.cpp.obj -c C:\Users\ssasu\Desktop\Trabalho\comandos.cpp

CMakeFiles/Trabalho.dir/comandos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho.dir/comandos.cpp.i"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ssasu\Desktop\Trabalho\comandos.cpp > CMakeFiles\Trabalho.dir\comandos.cpp.i

CMakeFiles/Trabalho.dir/comandos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho.dir/comandos.cpp.s"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ssasu\Desktop\Trabalho\comandos.cpp -o CMakeFiles\Trabalho.dir\comandos.cpp.s

CMakeFiles/Trabalho.dir/recursos.cpp.obj: CMakeFiles/Trabalho.dir/flags.make
CMakeFiles/Trabalho.dir/recursos.cpp.obj: ../recursos.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Trabalho.dir/recursos.cpp.obj"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Trabalho.dir\recursos.cpp.obj -c C:\Users\ssasu\Desktop\Trabalho\recursos.cpp

CMakeFiles/Trabalho.dir/recursos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho.dir/recursos.cpp.i"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ssasu\Desktop\Trabalho\recursos.cpp > CMakeFiles\Trabalho.dir\recursos.cpp.i

CMakeFiles/Trabalho.dir/recursos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho.dir/recursos.cpp.s"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ssasu\Desktop\Trabalho\recursos.cpp -o CMakeFiles\Trabalho.dir\recursos.cpp.s

CMakeFiles/Trabalho.dir/edificios.cpp.obj: CMakeFiles/Trabalho.dir/flags.make
CMakeFiles/Trabalho.dir/edificios.cpp.obj: ../edificios.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Trabalho.dir/edificios.cpp.obj"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Trabalho.dir\edificios.cpp.obj -c C:\Users\ssasu\Desktop\Trabalho\edificios.cpp

CMakeFiles/Trabalho.dir/edificios.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho.dir/edificios.cpp.i"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ssasu\Desktop\Trabalho\edificios.cpp > CMakeFiles\Trabalho.dir\edificios.cpp.i

CMakeFiles/Trabalho.dir/edificios.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho.dir/edificios.cpp.s"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ssasu\Desktop\Trabalho\edificios.cpp -o CMakeFiles\Trabalho.dir\edificios.cpp.s

CMakeFiles/Trabalho.dir/zonas.cpp.obj: CMakeFiles/Trabalho.dir/flags.make
CMakeFiles/Trabalho.dir/zonas.cpp.obj: ../zonas.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Trabalho.dir/zonas.cpp.obj"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Trabalho.dir\zonas.cpp.obj -c C:\Users\ssasu\Desktop\Trabalho\zonas.cpp

CMakeFiles/Trabalho.dir/zonas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho.dir/zonas.cpp.i"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ssasu\Desktop\Trabalho\zonas.cpp > CMakeFiles\Trabalho.dir\zonas.cpp.i

CMakeFiles/Trabalho.dir/zonas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho.dir/zonas.cpp.s"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ssasu\Desktop\Trabalho\zonas.cpp -o CMakeFiles\Trabalho.dir\zonas.cpp.s

# Object files for target Trabalho
Trabalho_OBJECTS = \
"CMakeFiles/Trabalho.dir/main.cpp.obj" \
"CMakeFiles/Trabalho.dir/map.cpp.obj" \
"CMakeFiles/Trabalho.dir/trabalhadores.cpp.obj" \
"CMakeFiles/Trabalho.dir/comandos.cpp.obj" \
"CMakeFiles/Trabalho.dir/recursos.cpp.obj" \
"CMakeFiles/Trabalho.dir/edificios.cpp.obj" \
"CMakeFiles/Trabalho.dir/zonas.cpp.obj"

# External object files for target Trabalho
Trabalho_EXTERNAL_OBJECTS =

Trabalho.exe: CMakeFiles/Trabalho.dir/main.cpp.obj
Trabalho.exe: CMakeFiles/Trabalho.dir/map.cpp.obj
Trabalho.exe: CMakeFiles/Trabalho.dir/trabalhadores.cpp.obj
Trabalho.exe: CMakeFiles/Trabalho.dir/comandos.cpp.obj
Trabalho.exe: CMakeFiles/Trabalho.dir/recursos.cpp.obj
Trabalho.exe: CMakeFiles/Trabalho.dir/edificios.cpp.obj
Trabalho.exe: CMakeFiles/Trabalho.dir/zonas.cpp.obj
Trabalho.exe: CMakeFiles/Trabalho.dir/build.make
Trabalho.exe: CMakeFiles/Trabalho.dir/linklibs.rsp
Trabalho.exe: CMakeFiles/Trabalho.dir/objects1.rsp
Trabalho.exe: CMakeFiles/Trabalho.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Trabalho.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Trabalho.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Trabalho.dir/build: Trabalho.exe
.PHONY : CMakeFiles/Trabalho.dir/build

CMakeFiles/Trabalho.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Trabalho.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Trabalho.dir/clean

CMakeFiles/Trabalho.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ssasu\Desktop\Trabalho C:\Users\ssasu\Desktop\Trabalho C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug C:\Users\ssasu\Desktop\Trabalho\cmake-build-debug\CMakeFiles\Trabalho.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Trabalho.dir/depend

