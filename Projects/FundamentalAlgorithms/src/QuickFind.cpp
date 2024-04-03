#include "QuickFind.h"
#include <string>
#include <algorithm>
#include <numeric>

void QuickFind::InputElements(size_t elementsCount, ReaderF&& readNextElement)
{
    id.resize(elementsCount);
    // Creating linking groups
    std::iota(std::begin(id), std::end(id), 0);

    for(std::optional<Connection> connection { }; (connection = readNextElement()); )
    {
        ElementType firstElementLinkingGroup = id[connection->first];
        if(firstElementLinkingGroup == id[connection->second])
        {
            continue;
        }

        // Redefine for selected element his linking group
        for(ElementType& curElementLinkingGroup: id )
        {
            if(curElementLinkingGroup != firstElementLinkingGroup)
            {
                continue;
            }

            curElementLinkingGroup = connection->second;
        }
    }
}

bool QuickFind::IsConnected(size_t i, size_t j)
{
    return id[i] == id[j];
}
