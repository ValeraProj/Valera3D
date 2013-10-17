cmake_minimum_required(VERSION 2.8)

project(${GLEW_PLOJECT})

if(MINGW OR UNIX)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-attributes")
endif()

include_directories( include )

add_definitions("-DGLEW_STATIC")

file(GLOB GLEW_HEADERS include/GL/*.h)
file(GLOB GLEW_SOURCES src/glew.c)

source_group(include/GL FILES ${GLEW_HEADERS})
source_group(src FILES ${GLEW_SOURCES})

add_library(
		${GLEW_PLOJECT}
		STATIC
		${GLEW_SOURCES} ${GLEW_HEADERS}
		)