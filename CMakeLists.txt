# Copyright (c) 2022 furzoom.com, All rights reserved.
# Author: Furzoom, mn@furzoom.com

cmake_minimum_required(VERSION 3.7)

project(cutio-ctest
    LANGUAGES C
)

# Main target
add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE cutio-ctest_example.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}
)

set(${PROJECT_NAME}_PUBLIC_HEADERS
        src/cutio-ctest.h
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        C_STANDARD          90
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS        OFF
        PUBLIC_HEADER       "${${PROJECT_NAME}_PUBLIC_HEADERS}"
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        # Clang
        $<$<C_COMPILER_ID:Clang>:
            -Wcast-align
            -Wcase-qual
            -Wconversion
            -Wexit-time-destructors
            -Wglobal-constructors
            -Wmissing-noreturn
            -Wmissing-prototypes
            -Wno-missing-braces
            -Wold-style-cast
            -Wshadow
            -Wweak-vtables
            -Werror
            -Wall
            $<$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,8.0.0>:-Wextra-semi-stmt>
        >

        # GCC
        $<$<C_COMPILER_ID:GNU>:
            -Waddress
            -Waggregate-return
            -Wformat-nonliteral
            -Wformat-security
            -Wformat
            -Winit-self
            -Wmissing-declarations
            -Wmissing-include-dirs
            -Wno-multichar
            -Wno-parentheses
            -Wno-type-limits
            -Wno-unused-parameter
            -Wpointer-arith
            -Wunreachable-code
            -Wwrite-strings
            -Werror
            -Wall
        >
)