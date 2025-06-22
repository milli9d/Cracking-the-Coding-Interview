#include <iostream>
#include <ctime>

#include <ring_buffer.hpp>

int main()
{
    ctci::ring_buf<uint32_t, 16u> _buf;

    for (size_t i = 0u; i < _buf.cap(); i++) {
        _buf.push(i);
    }
    std::cout << _buf;

    std::array<uint32_t, 32u> _temp_data;
    for (size_t i = 0u; i < _temp_data.size(); i++) {
        _temp_data[i] = 100 + i;
    }


    std::array<uint32_t, 12u> _read_data;
    _buf.read(_read_data.data(), _read_data.size());
    for (auto i : _read_data) {
        printf("%d\n", i);
    }
    std::cout << _buf;

    _buf.push(_temp_data.data(), 12u);
    std::cout << _buf;
    
    _buf.push(_temp_data.data() + 12u, 6u);
    _buf.read(_read_data.data(), _read_data.size());
    for (auto i : _read_data) {
        printf("%d\n", i);
    }
    std::cout << _buf;

    return 0;
}