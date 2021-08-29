cmake_minimum_required  (VERSION 3.1)
project                 (Hampel CXX)
set (Hampel_VERSION_MAJOR 0)
set (Hampel_VERSION_MINOR 1)
set (Hampel_VERSION_PATCH 0)

add_library (Hampel INTERFACE)
add_library (Hampel::Hampel ALIAS Hampel)

target_compile_features (Hampel
    INTERFACE cxx_std_11
)

target_include_directories (Hampel
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
)


add_subdirectory (test)
