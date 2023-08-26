cmake_minimum_required(VERSION 3.25)
project(CmakeDemo VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

# OpenGL
find_package(OpenGL REQUIRED) # REQUIRED：必须的意思
# FreeType
find_package(Freetype REQUIRED)
# glfw3
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
find_package(glfw3 3.3 REQUIRED)
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

add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
        )

target_link_libraries(${PROJECT_NAME} PRIVATE src_lib glad glfw glm OpenGL::GL Freetype::Freetype )