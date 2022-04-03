set(TOP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(SOURCE_FILE
    ${TOP_DIR}/src/Hello.cpp
)

set(TEST_FILE
#    ${TOP_DIR}/testcase/GtestBase.cpp
#    ${TOP_DIR}/testcase/L648.cpp
#    ${TOP_DIR}/testcase/L127.cpp
#    ${TOP_DIR}/testcase/L200.cpp
    ${TOP_DIR}/testcase/L1557.cpp
)

add_executable(test
    ${TOP_DIR}testcase/gtest_main.cpp
    ${SOURCE_FILE}
    ${TEST_FILE}
)

target_include_directories(test PRIVATE
    ${TOP_DIR}/include
    ${TOP_DIR}/../googletest/googletest/include
)

target_link_libraries(test PRIVATE
    gtest
    gtest_main
)

target_link_directories(test PRIVATE
    ${TOP_DIR}/../googletest/out/lib
)
