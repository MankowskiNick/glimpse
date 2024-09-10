cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Glimpse VERSION 1.0)

# Option to build shared or static library
option(BUILD_STATIC_LIBS "Build using static libraries" ON)

# Automatically find all .cpp files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Add the library target
if(BUILD_STATIC_LIBS)
    add_library(Glimpse STATIC ${SOURCES})
else()
    add_library(Glimpse SHARED ${SOURCES})
endif()

# Specify include directories
target_include_directories(Glimpse PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# Optionally, set properties for the library
set_target_properties(Glimpse PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# Optionally, set installation rules
install(TARGETS Glimpse
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)