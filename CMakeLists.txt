cmake_minimum_required(VERSION 3.10)

project(BoronServer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    enet
    GIT_REPOSITORY https://github.com/lsalzman/enet.git
    GIT_TAG v1.3.18
)

FetchContent_MakeAvailable(enet)

add_executable(BoronServer
    BoronServer.cpp
    Networking/NetworkServer.cpp
    Networking/NetworkServer.h
)

target_include_directories(BoronServer PRIVATE
    "${enet_SOURCE_DIR}/include"
)

target_link_libraries(BoronServer PRIVATE
    enet
)

if(WIN32)
    target_link_libraries(BoronServer PRIVATE
        ws2_32
        winmm
    )
endif()