cmake_minimum_required(VERSION 2.8)

set(TEST_PROJECT CreateWindow)

project(${TEST_PROJECT})

if (PLATFORM_WIN32)
	add_definitions(-DWIN32 -D_DEBUG -D_CONSOLE -DUNICODE -D_UNICODE)
elseif (PLATFORM_LINUX)
	add_definitions(-DLINUX)
endif()

file(GLOB TEST_HEADERS *.h)
file(GLOB TEST_SOURCES *.cpp)

set(MAIN_FILE CreateWindow.cpp)

source_group(include FILES ${TEST_HEADERS})
source_group(source  FILES ${TEST_SOURCES})


include_directories(source)

link_directories( project/win32 )


add_executable( 
		${TEST_PROJECT}
		${MAIN_FILE}
		${TEST_HEADERS}
		${TEST_SOURCES}
		)

if (PLATFORM_WIN32)
set(EXTERNAL_LIBS 
	#debug
	debug ValeraEngine_d.lib
	#release
	optimized ValeraEngine.lib
)

target_link_libraries(
		${TEST_PROJECT}
		${EXTERNAL_LIBS}
	)

endif()