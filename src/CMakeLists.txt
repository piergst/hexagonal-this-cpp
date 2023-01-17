file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

add_executable(${PROJECT_NAME} main.cpp)

add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})