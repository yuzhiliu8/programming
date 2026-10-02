find_package(GTest CONFIG REQUIRED)

add_executable(yliu_tests
    test_vector.cpp
)

target_link_libraries(yliu_tests PRIVATE
    yliu
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(yliu_tests)
