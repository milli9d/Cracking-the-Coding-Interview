#include <iostream>
#include <array>
#include <memory>

namespace ctci {

template<typename T, size_t S>
class ring_buf
{
  private:
    size_t _sz{ 0u };
    size_t _cap{ S };

    size_t _tail{ 0u };
    size_t _head{ 0u };

    std::shared_ptr<T[]> _data{ nullptr };

  public:
    /**
     * @brief Constructor
     */
    ring_buf(void)
    {
        /* allocate the buffer */
        _data = std::shared_ptr<T[]>(new T[_cap]);
        if (!_data) {
            throw std::runtime_error("Out of memory!");
        }
    };

    friend std::ostream& operator<<(std::ostream& os, ring_buf<T, S>& obj)
    {
        os << "Size = " << obj.size() << std::endl;

        for (size_t i = 0u; i < obj._cap; i++) {
            os << obj._data[i];

            if (obj._head == i) {
                os << " <- HEAD";
            }

            if (obj._tail == i) {
                os << " <- TAIL";
            }

            os << std::endl;
        }

        return os;
    }

    size_t size()
    {
        return _sz;
    }

    /**
     * @brief
     */
    int32_t push(const T& val)
    {
        /* sanity check  */
        if (_sz >= _cap) {
            printf("No more space!\n");
            return -ENOMEM;
        }

        /* calculate next index */
        _data[_tail] = val;
        _tail = (_tail + 1u) % _cap;
        _sz++;

        return 0;
    }

    int32_t pop(T& val)
    {
        /* sanity check */
        if (_sz <= 0) {
            printf("Empty buffer.\n");
            return -ENODATA;
        }

        val = _data[_head++];
        _sz--;
        return 0;
    }

    int32_t clear()
    {
        _sz = 0u;
        _tail = 0u;
        _head = 0u;
        return 0;
    }
};

} // namespace ctci