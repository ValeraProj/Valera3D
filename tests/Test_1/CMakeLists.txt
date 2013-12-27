cmake_minimum_required(VERSION 2.8.9)

project(${TEST_PROJECT_1})

file(GLOB TEST_HEADERS_1 *.h)
file(GLOB TEST_SOURCES_1 *.cpp)

set(MAIN_FILE Test_1.cpp)

source_group(include FILES ${TEST_HEADERS_1})
source_group(source  FILES ${TEST_SOURCES_1})

include_directories(source)

if(WIN32)
	link_directories(${ENGINE_PROJECT_DIR}/project/win32/)
elseif(UNIX AND NOT APPLE)
	link_directories(${ENGINE_PROJECT_DIR}/project/linux-qt/)
endif()

add_executable(
	${TEST_PROJECT_1}
	${TEST_HEADERS_1}
	${TEST_SOURCES_1}
	)

if(WIN32)
	set(EXTERNAL_LIBS 
		OpenGL32.lib
		#debug
		#debug ${ENGINE_NAME}_d.lib
		#debug ${GLEW_PLOJECT}_d.lib
		#release
		#optimized ${ENGINE_NAME}.lib
		#optimized ${GLEW_PLOJECT}.lib
	)
elseif(UNIX AND NOT APPLE)
	find_package(X11)
	set(EXTERNAL_LIBS
		libX11.so
		libGL.so
		libGLU.so
	)
	#find_library(X11 NAMES X11 x11 PATHS /usr/X11/include/X11/ /usr/X11/lib)
endif()

target_link_libraries(
	${TEST_PROJECT_1}
	${EXTERNAL_LIBS}
	${ENGINE_NAME}
	)

add_dependencies(${TEST_PROJECT_1} ${ENGINE_NAME})
