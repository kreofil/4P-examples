# Create shared library
add_library(mylib SHARED library.c)

# Set properties for shared library
set_target_properties(mylib PROPERTIES
    POSITION_INDEPENDENT_CODE TRUE
    C_VISIBILITY_PRESET hidden
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
)

# Define export symbol for proper visibility
target_compile_definitions(mylib PRIVATE MYLIB_EXPORTS)

# Include directory for library headers
target_include_directories(mylib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

# Export the library for other targets
export(TARGETS mylib FILE mylib-targets.cmake)
