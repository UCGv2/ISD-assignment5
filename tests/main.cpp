// @author G. Hemingway, copyright 2018 - All rights reserved
//
#include "tests.h"
#include <optional>

int main(int argc, char** argv)
{
    // Run the registered tests
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
