#include <iostream>
#include <ctime>

#include <lru_cache.hpp>

int main()
{
    ctci::lru_cache<100u> _cache;

    for (int i = 0; i < INT16_MAX; i++) {
        int key = rand() % 10u;
        int val = rand() % 255u;
        _cache.push(key, val);
    }

    std::cout << _cache << std::endl;

    for (int i = 0; i < 10; i++) {
        _cache.read(i);
        std::cout << _cache << std::endl;
    }

    return 0;
}