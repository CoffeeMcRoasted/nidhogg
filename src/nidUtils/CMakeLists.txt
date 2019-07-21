set(NID_UTILS_LIB_SRCS
    profiling/timing.hpp
)
add_library(nidUtils STATIC ${NID_UTILS_LIB_SRCS})
target_compile_features(nidUtils PUBLIC cxx_std_17)
target_include_directories(nidUtils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
