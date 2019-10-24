cmake_minimum_required(VERSION 3.0.0)
project(Program)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

#Include headers
include_directories(
        ${PROJECT_SOURCE_DIR}/include
)
#End of headers

# Compile all cpp files
file(GLOB SOURCES 
    "${PROJECT_SOURCE_DIR}/source/*.cpp"
    )
# End of compile

# Include SFML
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(Program sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
# End of SFML

# Add executables
add_executable(Program SOURCES)
# End of executables

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
