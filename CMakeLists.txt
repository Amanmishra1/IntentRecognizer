cmake_minimum_required(VERSION 3.10)

project(IntentRecognizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

enable_testing()
add_subdirectory(googletest)

set(HEADERS
  include/BasicRecognizer.h
  include/IRecognizer.h
  include/RecognizerAppFactory.h
)

set(SOURCES 
  src/RecognizerAppFactory.cpp
  src/BasicRecognizer.cpp
)

add_library(BasicRecognizer ${HEADERS} ${SOURCES})

target_include_directories(BasicRecognizer
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(IntentRecognizer main.cpp)

target_link_libraries(IntentRecognizer
  BasicRecognizer
)

#add_subdirectory(test)
