# CMakeList.txt: SingletonDemo 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project(SingletonDemo VERSION 0.1)

# 设置项目源文件列表
file(GLOB_RECURSE PROJECT_SOURCES
     "*.h" "*.h"
     "*.inl" "*.inl"
     "*.cpp" "*.cpp"
    )
# 包含当前目录
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

add_executable (SingletonDemo ${PROJECT_SOURCES} )

