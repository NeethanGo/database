cmake_minimum_required(VERSION 3.0)
project(SQLiteExample)

set(CMAKE_CXX_STANDARD 11)

# 将编译警告视为错误
# 增加编译器优化等级（例如，-O2）,若使用gdb调试则不能开启优化编译
# 启用调试信息 -g
add_compile_options(-Werror -g)

# 设置构建类型为Debug
set(CMAKE_BUILD_TYPE Debug)

# Add header file include directories
include_directories(./include)

# Add block directories
set(SRC test_db.cpp)


# Target
add_executable(SQLiteExample main.cpp ${SRC} )

# 查找SQLite3库
find_package(SQLite3 REQUIRED)

# 链接SQLite3库
target_link_libraries(SQLiteExample SQLite::SQLite3)
