#include <iostream>
#include <memory>
#include <cstdio>
#include <vector>
#include <array>
#include <thread>

#include "dynamic_array.hpp"
#include "smart_timer.hpp"

int main()
{
    CTCI::smart_timer main_time("main");

    CTCI::array<uint16_t> arr("unsigned vector", 3u);

    for (uint16_t i = 0u; i < UINT16_MAX; i++)
    {
        arr.insert(UINT16_MAX - i);
    }

    printf("Hello World\n");
    return 0;
}