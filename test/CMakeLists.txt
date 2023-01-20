add_executable(${PROJECT_NAME}_tests main.cpp tests.cpp)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}_tests PUBLIC ${PROJECT_NAME}_lib gtest gmock)

