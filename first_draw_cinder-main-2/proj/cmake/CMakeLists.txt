cmake_minimum_required( VERSION 3.10 FATAL_ERROR )
set( CMAKE_VERBOSE_MAKEFILE ON )

project( FirstDraw )

get_filename_component( CINDER_PATH "/root/Cinder" ABSOLUTE )
get_filename_component( APP_PATH "/root" ABSOLUTE )

include( "${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake" )

ci_make_app(
	SOURCES     ${APP_PATH}/src/FirstDraw.cpp
	CINDER_PATH ${CINDER_PATH}
)
