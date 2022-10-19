/**
 * Array Data Structure
 *
 * This is a template implementation of an arrays which are statically or dynamically
 * allocated.
 */

#include <iostream>
#include <memory>
#include <cstdio>

namespace CTCI
{
    template <typename _T, std::size_t _S>
    class static_array
    {
    public:
        /* constructors */
        static_array()
            : _capacity(_S), _size(0u), _name("") {}

        static_array(const char *name)
            : _capacity(_S), _size(0u), _name(name) {}

        /* public API */
        size_t size(void)
        {
            printf("%s Size = %ld\n", _name.c_str(), _size);
            return _size;
        }

        size_t capacity(void)
        {
            printf("%s Capacity = %ld\n", _name.c_str(), _capacity);
            return _capacity;
        }

        bool insert(_T obj)
        {
            if (_size >= _capacity)
            {
                printf("%s array full, not inserted.\n", _name.c_str());
                return false;
            }
            _data[_size++] = obj;
            return true;
        }

        _T &operator[](size_t x)
        {
            return _data[x];
        }

        bool operator==(static_array &arr)
        {
            if (arr.size() != size()) {
                return false;
            }

            for (size_t i = 0u; i < _size; i++) {
                if (arr[i] != _data[i]) {
                    return false;
                }
            }
            return true;
        }

        void print_all()
        {
            for (size_t i = 0; i < _capacity; i++) {
                printf("arr[%ld] = %ld\n", i, _data[i]);
            }
        }

    private:
        /* private members */
        size_t _capacity = 0u;
        size_t _size = 0u;
        std::string _name;
        _T _data[_S]{};
    };
}
