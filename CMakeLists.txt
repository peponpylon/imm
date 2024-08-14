cmake_minimum_required(VERSION 3.5)
project(imm)

# Debug messages.
message(STATUS "Toolchain file specified: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "System name: ${CMAKE_SYSTEM_NAME}")
message(STATUS "System version: ${CMAKE_SYSTEM_VERSION}")
message(STATUS "System processor: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")

# Enable C23/C++23 standards.
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# We use Vulkan.
find_package(Vulkan REQUIRED)

#
#
#
#
#
# Header stuff
#
#
#
#
#

# Primary executable target.
add_executable(imm ./src/main.cpp ${HEADER_SOURCES})

# The root is where this CMakeLists.txt is located; ie: the root of the repository itself.
target_compile_definitions(imm PRIVATE -DPROJECT_ROOT="${CMAKE_SOURCE_DIR}")

target_include_directories(imm PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

# Linking what's needed from external/ + system packages.
target_link_libraries(imm PRIVATE Vulkan::Vulkan)

# Add compilation flags and preprocessor definitions for Debug and Release builds.
target_compile_definitions(imm PRIVATE
        "$<$<CONFIG:Debug>:DEBUG_BUILD>"
        "$<$<CONFIG:Release>:RELEASE_BUILD>"
)

target_compile_options(imm PRIVATE
        "$<$<CONFIG:Debug>:-O0;-g>"
        "$<$<CONFIG:Release>:-O3>"
)