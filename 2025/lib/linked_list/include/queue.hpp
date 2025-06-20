#pragma once

#include <iostream>
#include <iomanip>
#include <array>
#include <memory>

#include <linked_list.hpp>

namespace ctci {

template<typename T>
class queue: public linked_list<T>
{
  public:
    void push(const T& val)
    {
        this->push_back(val);
    }

    void pop()
    {
        this->pop_front();
    }

    const T& peek()
    {
        return this->front();
    }
};

} // namespace ctci