#include <cstdio>
#include <memory>
#include <iostream>

namespace CTCI
{
    template <typename _T>
    class linked_list
    {
    private:
        class node
        {
            _T data;
            node &next;
        };

        node &_head;
        node &_tail;

        size_t size;

    public:
    };
}