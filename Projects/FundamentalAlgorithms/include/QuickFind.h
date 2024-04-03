#ifndef ALGORITHMSONQT_QUICKFIND_H
#define ALGORITHMSONQT_QUICKFIND_H


#include <functional>
#include <optional>

// QuickFind is checks whether i-th and j-th elements are connected
// through several elements or not.
//
// For given elements array
// the connection between i-th and j-th elements
// is defined when a[i] == a[j].
class QuickFind
{
public:
    using ElementType = size_t;
    using Connection = std::pair<ElementType, ElementType>;
    using ReaderF = std::function<std::optional<Connection>()>;

public:
    // readNextElement until it returns non-empty optional
    void InputElements(size_t elementsCount, ReaderF&& readNextElement);

    bool IsConnected(ElementType i, ElementType j);

private:
    std::vector<ElementType> id;
};


#endif //ALGORITHMSONQT_QUICKFIND_H
