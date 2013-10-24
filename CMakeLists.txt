cmake_minimum_required(VERSION 2.8.10)

set(SOLUTION_NAME Valera3D)
set(ENGINE_NAME ValeraEngine)
set(GLEW_PLOJECT glew_static)
set(TEST_PROJECT CreateWindow)

if(PLATFORM_WIN32)
	message("-- Configuring Win32")
	add_definitions(-D_WIN32 -D_CONSOLE -DUNICODE -D_UNICODE)
elseif(PLATFORM_LINUX)
	message("-- Configuring Linux")
	add_definitions(-D_LINUX)
elseif(PLATFORM_MACOSX)
	message("-- Configuring MacOSX")
	add_definitions(-DMACOSX)
else()
	message(FATAL_ERROR "Unknown platform. Only PLATFORM_WIN32|PLATFORM_LINUX|PLATFORM_MACOSX supported")
endif()

project(${SOLUTION_NAME})

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_DEBUG_POSTFIX "_d")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
if(PLATFORM_WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /MP")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /ZI")
endif()

#Source Dir
set(SOURCE_DIR source)

set(MAIN_FILE 
	${SOURCE_DIR}/Object.cpp
	${SOURCE_DIR}/Object.h
 )

#Filters

#Platform Source
if(PLATFORM_WIN32) 
	set(PLATFORM_HEADERS
		${SOURCE_DIR}/platform/Platform.h
		${SOURCE_DIR}/platform/PlatformMgr.h
		${SOURCE_DIR}/platform/PlatformWin32.h
	)
	
	set(PLATFORM_SOURCES
		${SOURCE_DIR}/platform/Platform.cpp
		${SOURCE_DIR}/platform/PlatformMgr.cpp
		${SOURCE_DIR}/platform/PlatformWin32.cpp
	)

elseif(PLATFORM_LINUX)
	set(PLATFORM_HEADERS
		${SOURCE_DIR}/platform/Platform.h
		${SOURCE_DIR}/platform/PlatformMgr.h
		${SOURCE_DIR}/platform/PlatformLinux.h
	)
	
	set(PLATFORM_SOURCES
		${SOURCE_DIR}/platform/Platform.cpp
		${SOURCE_DIR}/platform/PlatformMgr.cpp
		${SOURCE_DIR}/platform/PlatformLinux.cpp
	)

elseif(PLATFORM_MACOSX)
	set(PLATFORM_HEADERS
		${SOURCE_DIR}/platform/Platform.h
		${SOURCE_DIR}/platform/PlatformMgr.h
		${SOURCE_DIR}/platform/PlatformMacOSX.h
	)
	
	set(PLATFORM_SOURCES
		${SOURCE_DIR}/platform/Platform.cpp
		${SOURCE_DIR}/platform/PlatformMgr.cpp
		${SOURCE_DIR}/platform/PlatformMacOSX.mm
	)
endif()

#Core Source
file(GLOB CORE_HEADERS ${SOURCE_DIR}/core/*.h)
file(GLOB CORE_SOURCES ${SOURCE_DIR}/core/*.cpp)

#Renderer Source
file(GLOB RENDERER_HEADERS ${SOURCE_DIR}/renderer/*.h)
file(GLOB RENDERER_SOURCES ${SOURCE_DIR}/renderer/*.cpp)

#Context Source
file(GLOB CONTEXT_HEADERS ${SOURCE_DIR}/context/*.h)
file(GLOB CONTEXT_SOURCES ${SOURCE_DIR}/context/*.cpp)

#Scene Source
file(GLOB SCENE_HEADERS ${SOURCE_DIR}/scene/*.h)
file(GLOB SCENE_SOURCES ${SOURCE_DIR}/scene/*.cpp)

#Stream Source
file(GLOB STREAM_HEADERS ${SOURCE_DIR}/stream/*.h)
file(GLOB STREAM_SOURCES ${SOURCE_DIR}/stream/*.cpp)

#Utils Source
file(GLOB UTILS_HEADERS ${SOURCE_DIR}/utils/*.h)
file(GLOB UTILS_SOURCES ${SOURCE_DIR}/utils/*.cpp)

#Main Source
file(GLOB MAIN_HEADERS ${SOURCE_DIR}/*.h)
file(GLOB MAIN_SOURCES ${SOURCE_DIR}/*.cpp)

source_group(platform         FILES ${PLATFORM_HEADERS} ${PLATFORM_SOURCES})
source_group(core             FILES ${CORE_HEADERS}     ${CORE_SOURCES})
source_group(renderer         FILES ${RENDERER_HEADERS} ${RENDERER_SOURCES})
source_group(context          FILES ${CONTEXT_HEADERS}  ${CONTEXT_SOURCES})
source_group(scene            FILES ${STREAM_HEADERS}   ${STREAM_SOURCES})
source_group(utils            FILES ${UTILS_HEADERS}    ${UTILS_SOURCES})
source_group(""               FILES ${MAIN_HEADERS}     ${MAIN_SOURCES})

set (ENGINE_PROJECT_DIR ${PROJECT_SOURCE_DIR})

include_directories(
		${SOURCE_DIR}
		libs/glew/include/GL
	)

add_library(
	${ENGINE_NAME}
	STATIC
	${PLATFORM_HEADERS} ${PLATFORM_SOURCES}
	${CORE_HEADERS}     ${CORE_SOURCES}
	${RENDERER_HEADERS} ${RENDERER_SOURCES}
	${CONTEXT_HEADERS}  ${CONTEXT_SOURCES}
	${STREAM_HEADERS}   ${STREAM_SOURCES}
	${UTILS_HEADERS}    ${UTILS_SOURCES}
	${MAIN_HEADERS}     ${MAIN_SOURCES}
	) 

#Additional Libs
add_subdirectory(libs/glew)
add_subdirectory(tests/${TEST_PROJECT})

add_dependencies(${ENGINE_NAME} ${GLEW_PLOJECT})



