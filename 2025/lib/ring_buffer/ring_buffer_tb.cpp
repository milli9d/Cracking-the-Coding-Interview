#include <iostream>
#include <ctime>

#include <ring_buffer.hpp>

int main()
{
    printf("Ring Buffer Testbench\n");
    ctci::ring_buf<int, 5> rb{};
    srand(time(0));

    for (size_t i = 0u; i < 5u; i++) {
        rb.push((int)i);
    }

    std::cout << rb << std::endl;

    for (size_t i = 0u; i < 3u; i++) {
        int out = 0;
        rb.pop(out);
    }

    std::cout << rb << std::endl;

    rb.clear();

    for (size_t i = 0u; i < 5u; i++) {
        rb.push((int)i * 50);
    }

    std::cout << rb << std::endl;

    return 0;
}