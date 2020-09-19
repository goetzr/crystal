cmake_minimum_required(VERSION 3.16)
project(crystal
				DESCRIPTION "Provides RAII-style wrapper types for common resources."
				LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 					17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS				FALSE)

add_library(crystal INTERFACE)
add_library(crystal::crystal ALIAS crystal)

target_sources(crystal INTERFACE
	${crystal_SOURCE_DIR}/include/crystal/FileHandle.h
	${crystal_SOURCE_DIR}/include/crystal/CStdioFileHandle.h
)

target_include_directories(crystal INTERFACE
	${crystal_SOURCE_DIR}/include
)