#include "main.c"
#include <gtest/gtest.h>

TEST (CountingTest, Right_Input)
{
double[] x = {0, 0, 4, 4};
double[] y = {0, 4, 4, 0};
double *result = null;
ASSERT_EQ(Polygon_square(4, x, y, result), 16);
}