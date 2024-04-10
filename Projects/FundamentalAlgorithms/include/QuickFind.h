#ifndef ALGORITHMSONQT_QUICKFIND_H
#define ALGORITHMSONQT_QUICKFIND_H


#include <functional>

// Assume element is an integer from 0 to n-1 which n is elements count.
// QuickFind is checks whether i-th and j-th elements are connected
// through several elements or not
//
// For given elements array
// the connection between i-th and j-th elements
// is defined when a[i] == a[j].
//
// It's worked via assigning a connection group for each element.
// When new element pair is entered, the group of second element
// will redefine by self entire group of first element.
class QuickFind
{
public:
    using ElementType = size_t;
    using ElementPair = std::pair<ElementType, ElementType>;
    using ReaderF = std::function<ElementPair()>;

public:
    void InputElements(size_t elementsCount, ReaderF&& readNextPair);

    bool IsConnected(ElementType i, ElementType j);
private:
    std::vector<ElementType> groups;
};


#endif //ALGORITHMSONQT_QUICKFIND_H
