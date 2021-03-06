cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_PREFIX_PATH "/home/vrs/Qt5.0.2/5.0.2/gcc")
set(CMAKE_AUTOMOC ON)

project(JVBotClient)

find_package(roscpp REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED )

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

# Add the include directories for the Qt 5 Widgets module to
# the compile lines.
include_directories(
	${Qt5Widgets_INCLUDE_DIRS}
	${roscpp_INCLUDE_DIRS}
)

# Use the compile definitions defined in the Qt 5 Widgets module
add_definitions(${Qt5Widgets_DEFINITIONS})

# Add compiler flags for building executables (-fPIE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(JVBotServer_SRC_FILES
	JVBotClientUI.cpp
	JVBotClient.cpp
	main.cpp	
	JVRenderArea.cpp
	JVAreaSelector.cpp
	JVViewer.cpp
)

# http://plagatux.es/2012/12/qt-automoc-with-cmake/

set(JVBotServer_UI_FILES
	JVBotClientUI.ui
	JVViewer.ui
)

qt5_wrap_ui(JVBotServer_UI_FILES ${JVBotServer_UI_FILES})

# Tell CMake to create the helloworld executable
add_executable(JVBotClient ${JVBotServer_SRC_FILES} ${JVBotServer_REQUIRE_MOC} ${JVBotServer_UI_FILES})

#Link the helloworld executable to the Qt 5 widgets library.
target_link_libraries(JVBotClient 
	Qt5::Widgets ${roscpp_LIBRARIES}
	${OpenCV_LIBRARIES}
	${cv_bridge_LIBRARIES}
	${image_transport_LIBRARIES}
	-lX11
)

add_custom_command(TARGET JVBotClient POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E
                         copy ./JVBotClient ${CMAKE_SOURCE_DIR}/dist/Debug/GNU-Linux-x86)


