cmake_minimum_required(VERSION 3.12)

project(GameTest)

find_package(raylib REQUIRED)

file(GLOB_RECURSE SRC
"src/*.cxx"
"src/*.cpp"
)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
