include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runStructuresTests
        dynamictabletests.cpp ListTests.cpp)

target_link_libraries(runStructuresTests gtest gtest_main)

add_subdirectory(testfiles)

file(COPY testfiles/tab1.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})