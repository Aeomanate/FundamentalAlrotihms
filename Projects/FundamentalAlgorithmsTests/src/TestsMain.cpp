#include <gtest/gtest.h>
#include "QuickFind.h"
#include <ranges>

TEST(QuickFindSuite, BaseTest)
{
    std::vector<QuickFind::ElementPair> elementPairs {
        { 3, 4 },
        { 4, 9 },
        { 8, 0 },
        { 2, 3 },
        { 5, 6 },
        { 2, 9 },
        { 5, 9 },
        { 7, 3 },
        { 4, 8 },
        { 5, 6 },
        { 0, 2 },
        { 6, 1 },
    };

    QuickFind quickFind;
    int curElement = 0;
    quickFind.InputElements(elementPairs.size(), [&elementPairs, &curElement]()
    {
        return elementPairs[curElement++];
    });

    for (std::weakly_incrementable auto i: std::views::iota(0, 9))
    {
        for (std::weakly_incrementable auto j: std::views::iota(i+1, 9))
        {
            ASSERT_EQ(quickFind.IsConnected(i, j), true) << "I: " << i << ", J: " << j;
        }
    }
}
