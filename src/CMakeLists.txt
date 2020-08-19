cmake_minimum_required(VERSION 3.10)

project(basic_recognizer)

add_library(${PROJECT_NAME} STATIC
    BasicRecognizer.cpp
    RecognizerAppFactory.cpp
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)
