cmake_minimum_required(VERSION 3.5)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS RIO Net)
include(${ROOT_USE_FILE})

add_library(physics_skim SHARED
  skim.cpp
  )

set(EXTRA_FLAGS "-pthread -m64 -Wno-return-type -Wno-writable-strings -Wno-dangling-else -Wno-comment")
target_link_libraries(physics_skim ${ROOT_LIBRARIES})

target_include_directories(physics_skim
  PRIVATE include
)

install(TARGETS physics_skim
  EXPORT PhysicsTargets
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION .
    )


install(
    DIRECTORY
    .
    DESTINATION
    include
    FILES_MATCHING
    PATTERN "*.hpp"
)
