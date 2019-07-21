set(NID_IO_LIB_SRCS
    window.cpp
    window.hpp
    SDLwindow.cpp
    SDLwindow.hpp
    GLFWwindow.hpp
    GLFWwindow.cpp
)
add_library(nidIO STATIC ${NID_IO_LIB_SRCS})
target_link_libraries(nidVk PRIVATE glfw)
target_link_libraries(nidVk PRIVATE sdl2)
target_compile_features(nidIO PUBLIC cxx_std_17)
target_include_directories(nidIO PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
