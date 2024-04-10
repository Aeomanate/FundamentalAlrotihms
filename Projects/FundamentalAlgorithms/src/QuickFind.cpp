#include "QuickFind.h"
#include <string>
#include <algorithm>
#include <numeric>
#include <ranges>

void QuickFind::InputElements(size_t elementsCount, ReaderF&& readNextPair)
{
    groups.resize(elementsCount);
    // Creating linking groups
    std::ranges::iota(groups, 0);

    for(std::weakly_incrementable auto i : std::views::iota(0u, groups.size()))
    {
        ElementPair elementPair = readNextPair();

        ElementType firstGroup = groups[elementPair.first];
        if(firstGroup == groups[elementPair.second])
        {
            // Already linked
            continue;
        }

        // Group which second element belongs
        // will be replaced group which first element belongs
        for(ElementType& curGroup: groups)
        {
            if(curGroup == firstGroup)
            {
                curGroup = groups[elementPair.second];
            }
        }
    }
}

bool QuickFind::IsConnected(size_t i, size_t j)
{
    return groups[i] == groups[j];
}
