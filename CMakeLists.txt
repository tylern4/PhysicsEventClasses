cmake_minimum_required(VERSION 3.5)
project(Skim)
set(VERSION 0.0.1)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS RIO Net)
include(${ROOT_USE_FILE})

set(CMAKE_MODULE_PATH
   ${CMAKE_MODULE_PATH}
)

include_directories("src")
add_subdirectory("src")

#Skim
add_executable(skim src/main.cpp)
target_link_libraries(skim physics_skim ${ROOT_LIBRARIES})
install(TARGETS skim
  RUNTIME DESTINATION bin)
