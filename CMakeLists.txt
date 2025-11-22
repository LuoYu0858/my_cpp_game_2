cmake_minimum_required(VERSION 4.0)
project(HollowSamurai)

set(CMAKE_CXX_STANDARD 23)

# 设置MSVC特有选项
if(MSVC)
    # 定义Windows图形程序宏
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)

    # 设置EasyX库路径
    set(EASYX_LIB ${CMAKE_SOURCE_DIR}/lib/EasyXa.lib)

    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi /Od")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG")

    # 添加导入库目标
    add_library(EasyX STATIC IMPORTED)
    set_target_properties(EasyX PROPERTIES
            IMPORTED_LOCATION "${EASYX_LIB}"
    )

else()
    message(FATAL_ERROR "This project requires MSVC compiler")
endif()

add_executable(HollowSamurai
        main.cpp
        resources_manager.cpp
)

if(MSVC)
    target_compile_options(HollowSamurai PRIVATE "/wd4456" "/wd4457" "/wd4458" "/wd4459")
endif()

target_include_directories(HollowSamurai PRIVATE
        ${PROJECT_SOURCE_DIR}
)

target_link_libraries(HollowSamurai PRIVATE EasyX)