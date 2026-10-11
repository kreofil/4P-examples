# Create executable
add_executable(main_program main.c)

# Include directory to find library.h
target_include_directories(main_program PRIVATE
    ${CMAKE_SOURCE_DIR}/LibDirectory
)

# Link against the shared library
target_link_libraries(main_program PRIVATE mylib)
