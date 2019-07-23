set(ECS_TEST_SRCS
    main.cpp

)
add_executable(test_nidecs ${ECS_TEST_SRCS})
target_link_libraries(test_nidecs PRIVATE gtest gmock gtest_main nidECS)
add_test(NAME test_nidecs COMMAND test_nidecs)
set_target_properties(test_nidecs PROPERTIES FOLDER test)