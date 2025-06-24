#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>

#include <ring_buffer_blocking_read.hpp>

#define BUF_SZ           40u
#define THREAD_PERIOD_MS 250u

void tb(void* args)
{
    ctci::ring_buf<uint32_t, BUF_SZ>& _buf =
        *(reinterpret_cast<ctci::ring_buf<uint32_t, BUF_SZ>*>(args));

    while (1) {
        // write sequential data
        size_t write_amt = rand() % _buf.cap();
        printf("write_amt %zu\n", write_amt);
        for (size_t i = 0u; i < write_amt; i++) {
            uint32_t val = rand() % BUF_SZ;
            // printf("WRITE %u\n", val);
            _buf.push(val);
        }
        std::cout << _buf;

        int read_amt = rand() % _buf.cap();
        std::vector<uint32_t> _read_data;
        _read_data.resize(read_amt);
        std::fill(_read_data.begin(), _read_data.end(), 0u);
        _buf.read(_read_data.data(), _read_data.size());
        for (auto i: _read_data) {
            printf("READ %d\n", i);
        }

        // prepare an array for testing purposes
        std::array<uint32_t, 32u> _temp_data;
        for (size_t i = 0u; i < _temp_data.size(); i++) {
            _temp_data[i] = 100 + i;
        }

        // block I/O
        _buf.push(_temp_data.data(), 12u);
        std::cout << _buf;

        _buf.push(_temp_data.data() + 12u, 6u);
        _buf.read(_read_data.data(), _read_data.size());
        for (auto i: _read_data) {
            printf("READ %d\n", i);
        }
        std::cout << _buf;
        srand(time(0));
        std::this_thread::sleep_for(
            std::chrono::milliseconds(THREAD_PERIOD_MS));
    }
}

static std::thread t1;
static std::thread t2;
static ctci::ring_buf<uint32_t, BUF_SZ> _buf;

int main()
{
    t1 = std::thread(tb, &_buf);
    std::this_thread::sleep_for(
        std::chrono::milliseconds(THREAD_PERIOD_MS / 2u));
    t2 = std::thread(tb, &_buf);

    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(100));
    }

    return 0;
}