cmake_minimum_required(VERSION 2.8.9)

project(${TEST_PROJECT})

file(GLOB TEST_HEADERS *.h)
file(GLOB TEST_SOURCES *.cpp)

set(MAIN_FILE CreateWindow.cpp)

source_group(include FILES ${TEST_HEADERS})
source_group(source  FILES ${TEST_SOURCES})

include_directories(source)

if(PLATFORM_WIN32)
	link_directories(${ENGINE_PROJECT_DIR}/project/win32/)
elseif(PLATFORM_LINUX)
	link_directories(${ENGINE_PROJECT_DIR}/project/linux-qt/)
endif()

add_executable(
	${TEST_PROJECT}
	${MAIN_FILE}
	${TEST_HEADERS}
	${TEST_SOURCES}
	)

if(PLATFORM_WIN32)
	set(EXTERNAL_LIBS 
		OpenGL32.lib
		#debug
		#debug ${ENGINE_NAME}_d.lib
		#debug ${GLEW_PLOJECT}_d.lib
		#release
		#optimized ${ENGINE_NAME}.lib
		#optimized ${GLEW_PLOJECT}.lib
	)
elseif(PLATFORM_LINUX)
	find_package(X11)
	set(EXTERNAL_LIBS
		libX11.so
		libGL.so
		libGLU.so
	)
	#find_library(X11 NAMES X11 x11 PATHS /usr/X11/include/X11/ /usr/X11/lib)
endif()

target_link_libraries(
	${TEST_PROJECT}
	${EXTERNAL_LIBS}
	${ENGINE_NAME}
	)

add_dependencies(${TEST_PROJECT} ${ENGINE_NAME})
