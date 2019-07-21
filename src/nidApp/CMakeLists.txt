set(NID_APP_LIB_SRCS
    application.hpp
)
add_library(nidApp STATIC ${NID_APP_LIB_SRCS})
target_compile_features(nidApp PUBLIC cxx_std_17)
target_include_directories(nidApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
