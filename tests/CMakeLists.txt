set(TEST_INCLUDES
    TAngle.h
    TMatrix.h
    TQuaternion.h
    TRectangle.h
    TUtilities.h
    TVector.h
)

set(TEST_SOURCES
    tests.cpp
)

add_executable(tests ${TEST_SOURCES} ${TEST_INCLUDES})
target_link_libraries(tests PRIVATE lutra-math GTest::gtest)

include(GoogleTest)
gtest_discover_tests(tests)