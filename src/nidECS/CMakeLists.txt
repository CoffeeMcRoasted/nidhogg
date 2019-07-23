set(NID_ECS_LIB_SRCS
    Entity.hpp
    Component.hpp
    System.hpp
    EntityManager.hpp
)
add_library(nidECS STATIC ${NID_ECS_LIB_SRCS})
target_compile_features(nidECS PUBLIC cxx_std_17)
target_include_directories(nidECS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})