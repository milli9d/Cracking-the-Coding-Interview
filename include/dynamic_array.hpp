/**
 * Array Data Structure
 *
 * This is a template implementation of an arrays which are statically or dynamically
 * allocated.
 */

#include <iostream>
#include <memory>
#include <cstdio>
#include <string>
#include <cstring>

#include "common.hpp"

namespace CTCI
{
    #define ARRAY_CAPACITY_INCR 5u

    template <typename _T>
    class array
    {
    public:

        /* ==================================================== constructors */
        array(std::string name, size_t capacity)
            : _capacity(capacity), _size(0u), _name(name) 
            {
                _data = (_T*) malloc(_capacity * sizeof(_T));
            }

        /* ====================================================== public API */

        /**
         * @brief Get number of elements in array
         *
         * @return count of elements present in array
         *
         */
        size_t size(void)
        {
            return _size;
        }

        void resize(size_t size)
        {
            if (size > _capacity){
                _incr_capacity(size - _capacity);
            }
        }

        /**
         * @brief Get current capacity of array
         *
         * @return count of memrory locations in array
         *
         */
        size_t capacity(void)
        {
            return _capacity;
        }

        /**
         * 
        */
        void insert(const _T& obj)
        {
            /* sanity checks */
            BUG_ON(_data == NULL, "data pointer invalid");

            /* check size of available space */
            if (_size >= _capacity) {
                _incr_capacity(ARRAY_CAPACITY_INCR);
            }

            /* insert object */
            _data[_size++] = obj;
        }

        _T &operator[](size_t x)
        {
            BUG_ON(x >= _capacity, "");
            return _data[x];
        }

        bool operator==(array &arr)
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
            printf("Printing %s : %ld of %ld elements\n",
                   _name.c_str(), _size, _capacity);

            for (size_t i = 0; i < _size; i++) {
                printf("arr[%ld] = %ld\n", i, _data[i]);
            }
        }

    private:

        /* ================================================= private members */\
        size_t _capacity = 0u;
        size_t _size = 0u;
        std::string _name{};
        _T* _data{};

        /**
         * Increment array capacity by given size
         */
        void _incr_capacity(size_t capacity) {
            /* sanity check */
            BUG_ON(_data == NULL, "array data pointer invalid");

            /* allocate new memory */
            size_t new_sz = (_capacity + capacity) * sizeof(_T);
            _T *_mem = (_T *)malloc(new_sz);

            /* perform copy */
            memcpy(&_mem[0], &_data[0], _capacity * sizeof(_T));

            _capacity += capacity;
            _data = _mem;
        }
    };
}
