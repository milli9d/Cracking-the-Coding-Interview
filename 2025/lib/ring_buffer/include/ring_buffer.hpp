#include <iostream>
#include <array>
#include <mutex>
#include <memory>

namespace ctci {

template<typename T, size_t S>
class ring_buf
{
  private:
    std::shared_ptr<T[]> _data{};
    std::mutex _mtx{};

    size_t _cap{ S };
    size_t _sz{ 0u };

    size_t _head{ 0u };
    size_t _tail{ 0u };

  public:
    /**
     * @brief overload the << operator
     * @param os
     * @param obj
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os, ring_buf<T, S>& obj)
    {
        std::lock_guard<std::mutex> _lock(obj._mtx);
        os << "Size = " << obj.size() << std::endl;
        for (size_t i = 0u; i < obj._cap; i++) {
            os << obj._data[i];
            if (obj._head == i) {
                os << " <- HEAD";
            }
            if (obj._tail == i) {
                os << " <- TAIL";
            }
            os << " |";
        }
        os << std::endl;
        return os;
    }

    ring_buf()
    {
        _data = std::make_shared<T[]>(S);
    }

    ~ring_buf() {}

    /**
     * @brief push a single value into the buffer
     * @param val
     */
    void push(const T& val)
    {
        std::lock_guard<std::mutex> _lock(_mtx);
        if (_sz + 1u > _cap) {
            printf("ERROR; Out of memory\n");
            return;
        }

        _data[_head] = val;
        _head = (_head + 1u) % _cap;
        _sz++;
    }

    /**
     * @brief push an array of data into the buffer
     * @param data
     * @param data_sz
     */
    void push(T* data, size_t data_sz)
    {
        std::lock_guard<std::mutex> _lock(_mtx);
        if (_sz + data_sz > _cap) {
            printf("ERROR; Out of memory\n");
            return;
        }

        /* if we are going to wrap, handle here */
        size_t size_till_end = _cap - _head;
        if (data_sz > size_till_end) {
            memcpy(_data.get() + _head, data, size_till_end * sizeof(T));
            _head = (_head + size_till_end) % _cap;
            _sz += size_till_end;
            data = data + size_till_end;
            data_sz = data_sz - size_till_end;
        }

        /* write rest of data; OR all data */
        memcpy(_data.get() + _head, data, data_sz * sizeof(T));
        _head = (_head + data_sz) % _cap;
        _sz += data_sz;
    }

    /**
     * @brief pop an element
     */
    void pop()
    {
        std::lock_guard<std::mutex> _lock(_mtx);
        if (!_sz) {
            printf("ERROR; no more elements\n");
            return;
        }

        _tail = (_tail + 1u) % _cap;
        _sz--;
    }

    /**
     * @brief pop multiple elements
     * @param sz
     */
    void pop(size_t sz)
    {
        std::lock_guard<std::mutex> _lock(_mtx);
        if (sz > _sz) {
            printf("ERROR: not enough elements\n");
            return;
        }

        _tail = (_tail + sz) % _cap;
        _sz -= sz;
    }

    /**
     * @brief read the specified amount of bytes
     * @param data
     * @param data_sz
     */
    void read(T* data, size_t data_sz)
    {
        std::lock_guard<std::mutex> _lock(_mtx);
        /* sanity check */
        if (data_sz > _sz) {
            printf("ERROR: not enough data to read\n");
            return;
        }

        /* read till end of buffer */
        size_t size_till_end = _cap - _tail;
        if (data_sz > size_till_end) {
            memcpy(data, _data.get() + _tail, size_till_end * sizeof(T));
            _tail = (_tail + size_till_end) % _cap;
            data_sz -= size_till_end;
            data += size_till_end;
            _sz -= size_till_end;
        }

        /* read the rest of data */
        memcpy(data, _data.get() + _tail, data_sz * sizeof(T));
        _tail = (_tail + data_sz) % _cap;
        _sz -= data_sz;
    }

    /**
     * @brief size of the buffer in use
     * @return
     */
    size_t size()
    {
        return _sz;
    }

    /**
     * @brief capacity of the buffer
     * @return
     */
    size_t cap()
    {
        return _cap;
    }
};

} // namespace ctci