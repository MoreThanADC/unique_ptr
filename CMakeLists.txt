cmake_minimum_required(VERSION 3.14)
project(UniquePtr)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-ut tests.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wconversion -O3)
target_compile_options(${PROJECT_NAME}-ut PRIVATE -Wall -Wextra -Wpedantic -Wconversion -O3)
#set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
#set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set_target_properties(${PROJECT_NAME} PROPERTIES
                        CXX_STANDARD 17
                        CMAKE_CXX_STANDARD_REQUIRED ON)
                        
set_target_properties(${PROJECT_NAME}-ut PROPERTIES
                        CXX_STANDARD 17
                        CMAKE_CXX_STANDARD_REQUIRED ON)

target_link_libraries(${PROJECT_NAME}-ut gtest_main)

enable_testing()
add_test(NAME testsForUniquePtr COMMAND ${PROJECT_NAME}-ut)



include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
