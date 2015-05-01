cmake_minimum_required(VERSION 2.8.4)
project(SpaceInvaders)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ ${CMAKE_MODULE_PATH})

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/build/")
	execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/build/)
endif()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
find_package(SOIL REQUIRED)

include(src/CMakeLists.txt)
include(data/CMakeLists.txt)

include_directories(${OPENGL_INCLUDE_DIR}
                    ${GLUT_INCLUDE_DIR}
                    ${GLEW_INCLUDE_DIR}
                    ${SOIL_INCLUDE_DIR})

add_executable(spaceinvaders ${SOURCE_FILES})

target_link_libraries(spaceinvaders ${EXTRA_LIBS}
                                    ${OPENGL_LIBRARY}
                                    ${GLUT_LIBRARY}
                                    ${GLEW_LIBRARY}
                                    ${SOIL_LIBRARY})

configure_file(README.txt ${CMAKE_SOURCE_DIR}/build/ COPYONLY)