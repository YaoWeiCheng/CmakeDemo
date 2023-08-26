cmake_minimum_required(VERSION 3.25)
project(CmakeDemo VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)


# glad
## 添加源文件生成一个库
add_library(glad deps/glad/src/glad.c)
# 定义目标索引位置
target_include_directories(glad PUBLIC deps/glad/include)
#glm
add_subdirectory(deps/glm)
## 创建一个库并生成别名
#add_library(glm:glm ALIAS glm)


add_subdirectory(src)

add_executable(CmakeDemo main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE src_lib glad glm)