project(AlgoTests)
set(CMAKE_CXX_STANDARD 20)

add_executable(AlgoTests
        src/TestsMain.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/eff443c6ef5eb6ab598bfaae27f9427fdb4f6af7.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(AlgoTests
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(AlgoTests)

# Linking our algorithms
target_link_libraries(AlgoTests AlgorithmsLib)
target_include_directories(AlgoTests PUBLIC AlgorithmsLib)
