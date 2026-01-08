cmake_minimum_required(VERSION 3.16)

project(libdw3000 LANGUAGES C)

add_library(libdw3000 STATIC)

target_sources(libdw3000
    PRIVATE
        src/libdw3000.c
        src/libdw3000Spi.c
        src/mac_802_15_4.c
)

target_include_directories(libdw3000
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(libdw3000 PUBLIC c_std_99)
