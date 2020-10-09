cmake_minimum_required(VERSION 3.17)
project(UB_th)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)
#find_package(OpenGL REQUIRED)
#find_package(SDL_image REQUIRED)
add_executable(UB_th main.cpp Input.cpp direction.h Screen.cpp Player.cpp Input.h Screen.h Player.h Geom.h Geom.cpp Bullet.h Enemy.cpp Bullet.cpp)


target_link_libraries(UB_th SDL2::SDL2)