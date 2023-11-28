include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(mid2048_test board_test.cc)
target_link_libraries(mid2048_test PRIVATE mid2048 gtest_main)

include(GoogleTest)
gtest_discover_tests(mid2048_test)