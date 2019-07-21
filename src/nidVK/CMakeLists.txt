set(NID_VK_LIB_SRCS
    extension.hpp
    extension.cpp
    instance.hpp
    instance.cpp
    physicaldevice.hpp
    physicaldevice.cpp
)
add_library(nidVk STATIC ${NID_VK_LIB_SRCS})
target_link_libraries(nidVk PRIVATE vulkan)
target_compile_features(nidVk PUBLIC cxx_std_17)
target_include_directories(nidVk PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
