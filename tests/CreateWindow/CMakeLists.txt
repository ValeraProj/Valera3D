cmake_minimum_required(VERSION 2.8)

project(${TEST_PROJECT})

if (PLATFORM_WIN32)
	add_definitions(-DWIN32 -D_CONSOLE -DUNICODE -D_UNICODE)
elseif (PLATFORM_LINUX)
	add_definitions(-DLINUX)
elseif(PLATFORM_MACOSX)
	add_definitions(-DMACOSX)
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_DEBUG_POSTFIX "_d")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")

file(GLOB TEST_HEADERS *.h)
file(GLOB TEST_SOURCES *.cpp)

set(MAIN_FILE CreateWindow.cpp)

source_group(include FILES ${TEST_HEADERS})
source_group(source  FILES ${TEST_SOURCES})

include_directories(source)

if (PLATFORM_WIN32)
	link_directories(
		${ENGINE_PROJECT_DIR}/project/win32/
		)
endif()

add_executable( 
		${TEST_PROJECT}
		${MAIN_FILE}
		${TEST_HEADERS}
		${TEST_SOURCES}
		)

if (PLATFORM_WIN32)
	set(EXTERNAL_LIBS 
		OpenGL32.lib
		#debug
		#debug ${ENGINE_NAME}_d.lib
		#debug ${GLEW_PLOJECT}_d.lib
		#release
		#optimized ${ENGINE_NAME}.lib
		#optimized ${GLEW_PLOJECT}.lib
	)
endif()

target_link_libraries(
	${TEST_PROJECT}
	${EXTERNAL_LIBS}
	${GLEW_PLOJECT}
	${ENGINE_NAME}
	)

add_dependencies(${TEST_PROJECT} ${ENGINE_NAME})