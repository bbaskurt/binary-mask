cmake_minimum_required(VERSION 2.8.9)

set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE PATH "Install path prefix" FORCE)

project (binary_mask)

set(binary_mask_sources
	main.cpp
	binary_mask.h
	binary_mask.cpp
	)	

add_executable(${PROJECT_NAME}
	${binary_mask_sources}
)

IF(WIN32)

LINK_DIRECTORIES(
${PROJECT_SOURCE_DIR}/opencv
)

INCLUDE_DIRECTORIES(
${PROJECT_SOURCE_DIR}/opencv/include
)

TARGET_LINK_LIBRARIES( ${PROJECT_NAME}
${PROJECT_SOURCE_DIR}/opencv/opencv_world340.lib
)

ENDIF(WIN32)
