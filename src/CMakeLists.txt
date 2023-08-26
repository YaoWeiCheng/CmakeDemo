
set(SRC_FILES
        hello.hpp
        test3.cpp
        test3.hpp
        test1.hpp
        )

add_library(src_lib ${SRC_FILES})
target_include_directories(src_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})