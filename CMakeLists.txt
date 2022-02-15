# Copyright (C) 1883 Thomas Edison - All Rights Reserved
# You may use, distribute and modify this code under the
# terms of the GPLv2 license, which unfortunately won't be
# written for another century.
#
# SPDX-License-Identifier: GPL-2.0-or-later
#
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(example C CXX ASM)

pico_sdk_init()

add_subdirectory(stdinit-lib)
add_subdirectory(ps2kbd-lib)

add_executable(example example.c)

target_link_libraries(example PUBLIC
    pico_stdlib
    stdinit-lib
    ps2kbd-lib
)

pico_enable_stdio_uart(example 1)
pico_enable_stdio_usb(example 0)

pico_add_extra_outputs(example)

