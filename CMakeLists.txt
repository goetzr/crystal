cmake_minimum_required(VERSION 3.18)
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
	$<$<PLATFORM_ID:WIN32>:${crystal_SOURCE_DIR}/include/windows/crystal/NativeFileHandle.h>
	$<$<PLATFORM_ID:UNIX>:${crystal_SOURCE_DIR}/includelinux/crystal/NativeFileHandle.h>
	${crystal_SOURCE_DIR}/include/crystal/FileHandle.h
)

target_include_directories(crystal INTERFACE
	$<$<PLATFORM_ID:WIN32>:${crystal_SOURCE_DIR}/include/windows>
	$<$<PLATFORM_ID:UNUX>:${crystal_SOURCE_DIR}/include/linux>
	${crystal_SOURCE_DIR}/include
)