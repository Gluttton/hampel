#include <gtest/gtest.h>
#include <hampel/hampel.h>



TEST (Hampel, Window3_Case_001)
{
    // Arrange.
    std::vector <int> x {0, 1, 2};

    // Act. Assert.
    EXPECT_EQ (Hampel::Hampel (x.begin (), x.end () ), 1);
}



// The following four tests based on the following material:
// https://www.mathworks.com/help/dsp/ref/hampelfilter.html .
TEST (Hampel, Window5_Case_002)
{
    // Arrange.
    std::vector <int> x {1, 2, 4, 9, 23};

    // Act. Assert.
    EXPECT_EQ (Hampel::Hampel (x.begin (), x.end () ), 4);
}

TEST (Hampel, Window5_Case_003)
{
    // Arrange.
    std::vector <int> x {2, 4, 9, 23, 8};

    // Act. Assert.
    EXPECT_EQ (Hampel::Hampel (x.begin (), x.end () ), 9);
}

TEST (Hampel, Window5_Case_004)
{
    // Arrange.
    std::vector <int> x {4, 9, 23, 8, 12};

    // Act. Assert.
    EXPECT_EQ (Hampel::Hampel (x.begin (), x.end () ), 23);
}

TEST (Hampel, Window5_Case_005)
{
    // Arrange.
    std::vector <int> x {4, 9, 23, 8, 12};

    // Act. Assert.
    EXPECT_EQ (Hampel::Hampel (x.begin (), x.end (), 2), 9);
}



TEST (Hampel, Window3_Case_006)
{
    // Arrange.
    std::vector <int> x {0, 1, 2};

    // Act. Assert.
    EXPECT_EQ (Hampel::Hampel (x.begin (), x.end (), 0), 1);
}



TEST (Hampel, Window3_Case_007)
{
    // Arrange.
    std::vector <int> x {3, 1, 2};

    // Act. Assert.
    EXPECT_EQ (Hampel::Hampel (x.begin (), x.end (), 0), 2);
    EXPECT_EQ (Hampel::Hampel (x.begin (), x.end (), 1), 1);
}
