cmake_minimum_required(VERSION 3.17)
project(node_freebsd CXX)


list(APPEND library_source
    _.cpp
    _.h
    _factory.cpp
    )


add_library(node_freebsd SHARED ${library_source})


list(APPEND library_references
   acme
   acme_freebsd
   aura_posix
   )


target_precompile_headers(node_freebsd PRIVATE framework.h)


set_target_properties(node_freebsd PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)


   target_compile_options(node_freebsd PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(node_freebsd PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(node_freebsd PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/node_freebsd.lib")
   target_link_options(node_freebsd PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/node_freebsd.def")
   target_link_libraries(node_freebsd PRIVATE ${library_references})


elseif(${FREEBSD})


   pkg_check_modules(PKGCONFIG x11)
   target_compile_options(node_freebsd PRIVATE ${PKGCONFIG_CFLAGS})
   target_link_options(node_freebsd PRIVATE ${PKGCONFIG_LDFLAGS})
   target_link_libraries(node_freebsd PRIVATE dl pthread ${library_references})
   target_link_options(node_freebsd PRIVATE -Wl,-z,defs)


endif()


target_include_directories(node_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(node_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(node_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(node_freebsd PRIVATE _NODE_FREEBSD_LIBRARY)



