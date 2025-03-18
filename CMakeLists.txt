cmake_minimum_required(VERSION 3.30.3)

project(GettingStarted	  # Project name
    VERSION 1.0
    DESCRIPTION "Getting Started With GTK4"
    LANGUAGES C
)

set(EXEC_NAME "gtk_application_window")	# Nome do executável conforme o projeto
set(SOURCE_NAME "gtk_application_window.c")	# Nome do arquivo .c (contendo a função main) conforme o projeto

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c17")
set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
pkg_check_modules (GTK4 REQUIRED gtk4)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK4_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK4_LIBRARY_DIRS})

find_package(PkgConfig)
if(PKG_CONFIG_FOUND)
    pkg_check_modules (GTK "gtk4")
    if(GTK_FOUND)
        add_executable(${EXEC_NAME} ${SOURCE_NAME})
        target_sources(${EXEC_NAME}
            PUBLIC
                ${CMAKE_CURRENT_LIST_DIR}/${SOURCE_NAME}
        )
        target_link_libraries(${EXEC_NAME} PUBLIC ${GTK_LIBRARIES})
        add_definitions(${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})
    endif()
endif()
