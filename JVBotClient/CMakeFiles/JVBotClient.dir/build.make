# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/vrs/NetBeansProjects/JVBotClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vrs/NetBeansProjects/JVBotClient

# Include any dependencies generated for this target.
include CMakeFiles/JVBotClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/JVBotClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JVBotClient.dir/flags.make

ui_JVBotClientUI.h: JVBotClientUI.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vrs/NetBeansProjects/JVBotClient/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_JVBotClientUI.h"
	/home/vrs/Qt5.0.2/5.0.2/gcc/bin/uic -o /home/vrs/NetBeansProjects/JVBotClient/ui_JVBotClientUI.h /home/vrs/NetBeansProjects/JVBotClient/JVBotClientUI.ui

ui_JVViewer.h: JVViewer.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vrs/NetBeansProjects/JVBotClient/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_JVViewer.h"
	/home/vrs/Qt5.0.2/5.0.2/gcc/bin/uic -o /home/vrs/NetBeansProjects/JVBotClient/ui_JVViewer.h /home/vrs/NetBeansProjects/JVBotClient/JVViewer.ui

CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o: CMakeFiles/JVBotClient.dir/flags.make
CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o: JVBotClientUI.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vrs/NetBeansProjects/JVBotClient/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o -c /home/vrs/NetBeansProjects/JVBotClient/JVBotClientUI.cpp

CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vrs/NetBeansProjects/JVBotClient/JVBotClientUI.cpp > CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.i

CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vrs/NetBeansProjects/JVBotClient/JVBotClientUI.cpp -o CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.s

CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o.requires:
.PHONY : CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o.requires

CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o.provides: CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o.requires
	$(MAKE) -f CMakeFiles/JVBotClient.dir/build.make CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o.provides.build
.PHONY : CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o.provides

CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o.provides.build: CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o

CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o: CMakeFiles/JVBotClient.dir/flags.make
CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o: JVBotClient.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vrs/NetBeansProjects/JVBotClient/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o -c /home/vrs/NetBeansProjects/JVBotClient/JVBotClient.cpp

CMakeFiles/JVBotClient.dir/JVBotClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JVBotClient.dir/JVBotClient.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vrs/NetBeansProjects/JVBotClient/JVBotClient.cpp > CMakeFiles/JVBotClient.dir/JVBotClient.cpp.i

CMakeFiles/JVBotClient.dir/JVBotClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JVBotClient.dir/JVBotClient.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vrs/NetBeansProjects/JVBotClient/JVBotClient.cpp -o CMakeFiles/JVBotClient.dir/JVBotClient.cpp.s

CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o.requires:
.PHONY : CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o.requires

CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o.provides: CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o.requires
	$(MAKE) -f CMakeFiles/JVBotClient.dir/build.make CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o.provides.build
.PHONY : CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o.provides

CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o.provides.build: CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o

CMakeFiles/JVBotClient.dir/main.cpp.o: CMakeFiles/JVBotClient.dir/flags.make
CMakeFiles/JVBotClient.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vrs/NetBeansProjects/JVBotClient/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/JVBotClient.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/JVBotClient.dir/main.cpp.o -c /home/vrs/NetBeansProjects/JVBotClient/main.cpp

CMakeFiles/JVBotClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JVBotClient.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vrs/NetBeansProjects/JVBotClient/main.cpp > CMakeFiles/JVBotClient.dir/main.cpp.i

CMakeFiles/JVBotClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JVBotClient.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vrs/NetBeansProjects/JVBotClient/main.cpp -o CMakeFiles/JVBotClient.dir/main.cpp.s

CMakeFiles/JVBotClient.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/JVBotClient.dir/main.cpp.o.requires

CMakeFiles/JVBotClient.dir/main.cpp.o.provides: CMakeFiles/JVBotClient.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/JVBotClient.dir/build.make CMakeFiles/JVBotClient.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/JVBotClient.dir/main.cpp.o.provides

CMakeFiles/JVBotClient.dir/main.cpp.o.provides.build: CMakeFiles/JVBotClient.dir/main.cpp.o

CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o: CMakeFiles/JVBotClient.dir/flags.make
CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o: JVRenderArea.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vrs/NetBeansProjects/JVBotClient/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o -c /home/vrs/NetBeansProjects/JVBotClient/JVRenderArea.cpp

CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vrs/NetBeansProjects/JVBotClient/JVRenderArea.cpp > CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.i

CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vrs/NetBeansProjects/JVBotClient/JVRenderArea.cpp -o CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.s

CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o.requires:
.PHONY : CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o.requires

CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o.provides: CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o.requires
	$(MAKE) -f CMakeFiles/JVBotClient.dir/build.make CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o.provides.build
.PHONY : CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o.provides

CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o.provides.build: CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o

CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o: CMakeFiles/JVBotClient.dir/flags.make
CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o: JVAreaSelector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vrs/NetBeansProjects/JVBotClient/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o -c /home/vrs/NetBeansProjects/JVBotClient/JVAreaSelector.cpp

CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vrs/NetBeansProjects/JVBotClient/JVAreaSelector.cpp > CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.i

CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vrs/NetBeansProjects/JVBotClient/JVAreaSelector.cpp -o CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.s

CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o.requires:
.PHONY : CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o.requires

CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o.provides: CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o.requires
	$(MAKE) -f CMakeFiles/JVBotClient.dir/build.make CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o.provides.build
.PHONY : CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o.provides

CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o.provides.build: CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o

CMakeFiles/JVBotClient.dir/JVViewer.cpp.o: CMakeFiles/JVBotClient.dir/flags.make
CMakeFiles/JVBotClient.dir/JVViewer.cpp.o: JVViewer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vrs/NetBeansProjects/JVBotClient/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/JVBotClient.dir/JVViewer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/JVBotClient.dir/JVViewer.cpp.o -c /home/vrs/NetBeansProjects/JVBotClient/JVViewer.cpp

CMakeFiles/JVBotClient.dir/JVViewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JVBotClient.dir/JVViewer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vrs/NetBeansProjects/JVBotClient/JVViewer.cpp > CMakeFiles/JVBotClient.dir/JVViewer.cpp.i

CMakeFiles/JVBotClient.dir/JVViewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JVBotClient.dir/JVViewer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vrs/NetBeansProjects/JVBotClient/JVViewer.cpp -o CMakeFiles/JVBotClient.dir/JVViewer.cpp.s

CMakeFiles/JVBotClient.dir/JVViewer.cpp.o.requires:
.PHONY : CMakeFiles/JVBotClient.dir/JVViewer.cpp.o.requires

CMakeFiles/JVBotClient.dir/JVViewer.cpp.o.provides: CMakeFiles/JVBotClient.dir/JVViewer.cpp.o.requires
	$(MAKE) -f CMakeFiles/JVBotClient.dir/build.make CMakeFiles/JVBotClient.dir/JVViewer.cpp.o.provides.build
.PHONY : CMakeFiles/JVBotClient.dir/JVViewer.cpp.o.provides

CMakeFiles/JVBotClient.dir/JVViewer.cpp.o.provides.build: CMakeFiles/JVBotClient.dir/JVViewer.cpp.o

CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o: CMakeFiles/JVBotClient.dir/flags.make
CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o: JVBotClient_automoc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vrs/NetBeansProjects/JVBotClient/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o -c /home/vrs/NetBeansProjects/JVBotClient/JVBotClient_automoc.cpp

CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vrs/NetBeansProjects/JVBotClient/JVBotClient_automoc.cpp > CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.i

CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vrs/NetBeansProjects/JVBotClient/JVBotClient_automoc.cpp -o CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.s

CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o.requires:
.PHONY : CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o.requires

CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o.provides: CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o.requires
	$(MAKE) -f CMakeFiles/JVBotClient.dir/build.make CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o.provides.build
.PHONY : CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o.provides

CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o.provides.build: CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o

# Object files for target JVBotClient
JVBotClient_OBJECTS = \
"CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o" \
"CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o" \
"CMakeFiles/JVBotClient.dir/main.cpp.o" \
"CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o" \
"CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o" \
"CMakeFiles/JVBotClient.dir/JVViewer.cpp.o" \
"CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o"

# External object files for target JVBotClient
JVBotClient_EXTERNAL_OBJECTS =

JVBotClient: CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o
JVBotClient: CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o
JVBotClient: CMakeFiles/JVBotClient.dir/main.cpp.o
JVBotClient: CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o
JVBotClient: CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o
JVBotClient: CMakeFiles/JVBotClient.dir/JVViewer.cpp.o
JVBotClient: CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o
JVBotClient: CMakeFiles/JVBotClient.dir/build.make
JVBotClient: /home/vrs/Qt5.0.2/5.0.2/gcc/lib/libQt5Widgets.so.5.0.2
JVBotClient: /opt/ros/indigo/lib/libroscpp.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_signals.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_filesystem.so
JVBotClient: /opt/ros/indigo/lib/librosconsole.so
JVBotClient: /opt/ros/indigo/lib/librosconsole_log4cxx.so
JVBotClient: /opt/ros/indigo/lib/librosconsole_backend_interface.so
JVBotClient: /usr/lib/liblog4cxx.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_regex.so
JVBotClient: /opt/ros/indigo/lib/libroscpp_serialization.so
JVBotClient: /opt/ros/indigo/lib/librostime.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_date_time.so
JVBotClient: /opt/ros/indigo/lib/libxmlrpcpp.so
JVBotClient: /opt/ros/indigo/lib/libcpp_common.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_system.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_thread.so
JVBotClient: /usr/lib/i386-linux-gnu/libpthread.so
JVBotClient: /usr/lib/i386-linux-gnu/libconsole_bridge.so
JVBotClient: /usr/local/lib/libopencv_videostab.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_video.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_ts.a
JVBotClient: /usr/local/lib/libopencv_superres.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_stitching.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_photo.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_ocl.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_objdetect.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_nonfree.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_ml.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_legacy.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_imgproc.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_highgui.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_gpu.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_flann.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_features2d.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_core.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_contrib.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_calib3d.so.2.4.9
JVBotClient: /opt/ros/indigo/lib/libcv_bridge.so
JVBotClient: /usr/lib/libopencv_calib3d.so
JVBotClient: /usr/lib/libopencv_contrib.so
JVBotClient: /usr/lib/libopencv_core.so
JVBotClient: /usr/lib/libopencv_features2d.so
JVBotClient: /usr/lib/libopencv_flann.so
JVBotClient: /usr/lib/libopencv_gpu.so
JVBotClient: /usr/lib/libopencv_highgui.so
JVBotClient: /usr/lib/libopencv_imgproc.so
JVBotClient: /usr/lib/libopencv_legacy.so
JVBotClient: /usr/lib/libopencv_ml.so
JVBotClient: /usr/lib/libopencv_objdetect.so
JVBotClient: /usr/lib/libopencv_ocl.so
JVBotClient: /usr/lib/libopencv_photo.so
JVBotClient: /usr/lib/libopencv_stitching.so
JVBotClient: /usr/lib/libopencv_superres.so
JVBotClient: /usr/lib/libopencv_video.so
JVBotClient: /usr/lib/libopencv_videostab.so
JVBotClient: /opt/ros/indigo/lib/librosconsole.so
JVBotClient: /opt/ros/indigo/lib/librosconsole_log4cxx.so
JVBotClient: /opt/ros/indigo/lib/librosconsole_backend_interface.so
JVBotClient: /usr/lib/liblog4cxx.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_regex.so
JVBotClient: /opt/ros/indigo/lib/libroscpp_serialization.so
JVBotClient: /opt/ros/indigo/lib/librostime.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_date_time.so
JVBotClient: /opt/ros/indigo/lib/libcpp_common.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_system.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_thread.so
JVBotClient: /usr/lib/i386-linux-gnu/libpthread.so
JVBotClient: /usr/lib/i386-linux-gnu/libconsole_bridge.so
JVBotClient: /opt/ros/indigo/lib/libimage_transport.so
JVBotClient: /opt/ros/indigo/lib/libmessage_filters.so
JVBotClient: /usr/lib/i386-linux-gnu/libtinyxml.so
JVBotClient: /opt/ros/indigo/lib/libclass_loader.so
JVBotClient: /usr/lib/libPocoFoundation.so
JVBotClient: /usr/lib/i386-linux-gnu/libdl.so
JVBotClient: /opt/ros/indigo/lib/libroscpp.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_signals.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_filesystem.so
JVBotClient: /opt/ros/indigo/lib/librosconsole.so
JVBotClient: /opt/ros/indigo/lib/librosconsole_log4cxx.so
JVBotClient: /opt/ros/indigo/lib/librosconsole_backend_interface.so
JVBotClient: /usr/lib/liblog4cxx.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_regex.so
JVBotClient: /opt/ros/indigo/lib/libxmlrpcpp.so
JVBotClient: /opt/ros/indigo/lib/libroslib.so
JVBotClient: /opt/ros/indigo/lib/libroscpp_serialization.so
JVBotClient: /opt/ros/indigo/lib/librostime.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_date_time.so
JVBotClient: /opt/ros/indigo/lib/libcpp_common.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_system.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_thread.so
JVBotClient: /usr/lib/i386-linux-gnu/libpthread.so
JVBotClient: /usr/lib/i386-linux-gnu/libconsole_bridge.so
JVBotClient: /home/vrs/Qt5.0.2/5.0.2/gcc/lib/libQt5Gui.so.5.0.2
JVBotClient: /home/vrs/Qt5.0.2/5.0.2/gcc/lib/libQt5Core.so.5.0.2
JVBotClient: /opt/ros/indigo/lib/libroscpp.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_signals.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_filesystem.so
JVBotClient: /opt/ros/indigo/lib/librosconsole.so
JVBotClient: /opt/ros/indigo/lib/librosconsole_log4cxx.so
JVBotClient: /opt/ros/indigo/lib/librosconsole_backend_interface.so
JVBotClient: /usr/lib/liblog4cxx.so
JVBotClient: /usr/lib/i386-linux-gnu/libboost_regex.so
JVBotClient: /opt/ros/indigo/lib/libxmlrpcpp.so
JVBotClient: /opt/ros/indigo/lib/libcv_bridge.so
JVBotClient: /usr/lib/libopencv_calib3d.so
JVBotClient: /usr/lib/libopencv_contrib.so
JVBotClient: /usr/lib/libopencv_core.so
JVBotClient: /usr/lib/libopencv_features2d.so
JVBotClient: /usr/lib/libopencv_flann.so
JVBotClient: /usr/lib/libopencv_gpu.so
JVBotClient: /usr/lib/libopencv_highgui.so
JVBotClient: /usr/lib/libopencv_imgproc.so
JVBotClient: /usr/lib/libopencv_legacy.so
JVBotClient: /usr/lib/libopencv_ml.so
JVBotClient: /usr/lib/libopencv_objdetect.so
JVBotClient: /usr/lib/libopencv_ocl.so
JVBotClient: /usr/lib/libopencv_photo.so
JVBotClient: /usr/lib/libopencv_stitching.so
JVBotClient: /usr/lib/libopencv_superres.so
JVBotClient: /usr/lib/libopencv_video.so
JVBotClient: /usr/lib/libopencv_videostab.so
JVBotClient: /opt/ros/indigo/lib/libimage_transport.so
JVBotClient: /opt/ros/indigo/lib/libmessage_filters.so
JVBotClient: /usr/lib/i386-linux-gnu/libtinyxml.so
JVBotClient: /opt/ros/indigo/lib/libclass_loader.so
JVBotClient: /usr/lib/libPocoFoundation.so
JVBotClient: /usr/lib/i386-linux-gnu/libdl.so
JVBotClient: /opt/ros/indigo/lib/libroslib.so
JVBotClient: /usr/local/lib/libopencv_nonfree.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_ocl.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_gpu.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_photo.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_objdetect.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_legacy.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_video.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_ml.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_calib3d.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_features2d.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_highgui.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_imgproc.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_flann.so.2.4.9
JVBotClient: /usr/local/lib/libopencv_core.so.2.4.9
JVBotClient: CMakeFiles/JVBotClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable JVBotClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JVBotClient.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E copy ./JVBotClient /home/vrs/NetBeansProjects/JVBotClient/dist/Debug/GNU-Linux-x86

# Rule to build all files generated by this target.
CMakeFiles/JVBotClient.dir/build: JVBotClient
.PHONY : CMakeFiles/JVBotClient.dir/build

CMakeFiles/JVBotClient.dir/requires: CMakeFiles/JVBotClient.dir/JVBotClientUI.cpp.o.requires
CMakeFiles/JVBotClient.dir/requires: CMakeFiles/JVBotClient.dir/JVBotClient.cpp.o.requires
CMakeFiles/JVBotClient.dir/requires: CMakeFiles/JVBotClient.dir/main.cpp.o.requires
CMakeFiles/JVBotClient.dir/requires: CMakeFiles/JVBotClient.dir/JVRenderArea.cpp.o.requires
CMakeFiles/JVBotClient.dir/requires: CMakeFiles/JVBotClient.dir/JVAreaSelector.cpp.o.requires
CMakeFiles/JVBotClient.dir/requires: CMakeFiles/JVBotClient.dir/JVViewer.cpp.o.requires
CMakeFiles/JVBotClient.dir/requires: CMakeFiles/JVBotClient.dir/JVBotClient_automoc.cpp.o.requires
.PHONY : CMakeFiles/JVBotClient.dir/requires

CMakeFiles/JVBotClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/JVBotClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/JVBotClient.dir/clean

CMakeFiles/JVBotClient.dir/depend: ui_JVBotClientUI.h
CMakeFiles/JVBotClient.dir/depend: ui_JVViewer.h
	cd /home/vrs/NetBeansProjects/JVBotClient && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vrs/NetBeansProjects/JVBotClient /home/vrs/NetBeansProjects/JVBotClient /home/vrs/NetBeansProjects/JVBotClient /home/vrs/NetBeansProjects/JVBotClient /home/vrs/NetBeansProjects/JVBotClient/CMakeFiles/JVBotClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JVBotClient.dir/depend

