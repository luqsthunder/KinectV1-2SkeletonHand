cmake_minimum_required(VERSION 3.1)
project(kinectV1Skeleton)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(EXECUTABLE_NAME kinectV1Skeleton)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_FILES
  ${PROJECT_SOURCE_DIR}/src/main.cc

  ${PROJECT_SOURCE_DIR}/src/Viewer.cc
  ${PROJECT_SOURCE_DIR}/src/Viewer.h)

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

find_package(OpenCV REQUIRED)
find_package(OpenNI2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(NITE2 REQUIRED)
find_package(GLUT REQUIRED)

if(OpenCV_FOUND)
  include_directories(${OpenCV_INCLUDE_DIRS})
  target_link_libraries(${EXECUTABLE_NAME} ${OpenCV_LIBS})
else()
  message("OPENCV NOT FOUND")
endif()

if(OPENNI2_FOUND)
  include_directories(${OPENNI2_INCLUDE_DIRS})
  target_link_libraries(${EXECUTABLE_NAME} ${OPENNI2_LIBRARIES})
else()
  message("OPENNI2 NOT FOUND")
endif()

if(OPENGL_FOUND)
  include_directories(${OPENGL_INCLUDE_DIRS})
  target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})
else()
  message("OPENGL NOT FOUND")
endif()

if(GLUT_FOUND)
  include_directories(${GLUT_INCLUDE_DIRS})
  target_link_libraries(${EXECUTABLE_NAME} ${GLUT_LIBRARIES})
else()
  message("GLUT NOT FOUND")
endif()

if(NITE2_FOUND)
  include_directories(${NITE2_INCLUDE_DIRS})
  target_link_libraries(${EXECUTABLE_NAME} ${NITE2_LIBRARIES})
else()
  message("NITE2 NOT FOUND")
endif()
