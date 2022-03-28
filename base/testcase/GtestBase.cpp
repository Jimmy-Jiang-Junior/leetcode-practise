#include <cstdio>
#include <gtest/gtest.h>
#include "hello.h"
using namespace std;

TEST(GTEST_BASE, CASE_001)
{
    printf("This is the base gtest case\n");
    Hello();
}