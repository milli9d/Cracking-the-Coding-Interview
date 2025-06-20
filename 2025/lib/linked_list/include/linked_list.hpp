#include <iostream>
#include <iomanip>
#include <array>
#include <memory>

namespace ctci {

template<typename T>
class linked_list
{
  public:
    class node_t
    {
      public:
        T val;
        std::shared_ptr<node_t> next;
        node_t(const T& val, std::shared_ptr<node_t> next)
            : val(val), next(next)
        {
            /* do nothing */
        }
    };

  private:
    std::shared_ptr<node_t> _head{ nullptr };
    std::shared_ptr<node_t> _tail{ nullptr };
    size_t sz{ 0u };

  public:
    friend std::ostream& operator<<(std::ostream& os,
                                    const linked_list<T>& list)
    {
        if (list.size() == 0) {
            os << "[ Empty List ]";
            return os;
        }

        auto curr = list._head;
        os << "[HEAD] ";
        while (curr) {
            os << std::setw(2) << curr->val << " -> ";
            if (curr == list._tail) {
                os << "[TAIL]";
            }
            curr = curr->next;
        }

        return os;
    }

    void push_front(const T& val)
    {
        _head = std::make_shared<node_t>(val, _head);
        if (!_tail) {
            _tail = _head;
        }
        sz++;
    }

    void push_back(const T& val)
    {
        if (!_head && !_tail) {
            push_front(val);
            return;
        }

        if (!_tail) {
            throw std::runtime_error(
                "Invalid state: head is not null but tail is null");
        }

        /* tail is the last element */
        _tail->next = std::make_shared<node_t>(val, nullptr);
        _tail = _tail->next;
        sz++;
    }

    const T& front() const
    {
        if (!_head) {
            throw std::runtime_error("List is empty");
        }
        return _head->val;
    }

    const T& back() const
    {
        if (!_tail) {
            throw std::runtime_error("List is empty");
        }
        return _tail->val;
    }

    void pop_front()
    {
        if (_head) {
            if (_tail == _head) {
                _tail = nullptr;
            }
            _head = _head->next;
            sz--;
        }
    }

    void pop_back()
    {
        /* if only single element */
        if (_tail == _head) {
            _tail = nullptr;
            _head = nullptr;
            sz = 0;
            return;
        }

        /* otherwise detach tail from second last element */
        std::shared_ptr<node_t> curr = _head;
        while (curr && curr->next && curr->next != _tail) {
            curr = curr->next;
        }
        curr->next = nullptr;
        _tail = curr;
        sz--;
    }

    /**
     * @brief reverse the linked list in place
     */
    void reverse()
    {
        std::shared_ptr<node_t> curr = _head;
        std::shared_ptr<node_t> prev = nullptr;
        _tail = _head;
        while (curr) {
            std::shared_ptr<node_t> link_fw = curr->next;
            /* reverse links */
            curr->next = prev;
            /* move forward */
            prev = curr;
            curr = link_fw;
        }
        _head = prev;
    }

    void insert(size_t idx, const T& val)
    {
        if (idx > sz) {
            printf("%s : ERROR: Out of range\n", __func__);
            return;
        }
        printf("insert %d\n", val);

        if (idx == 0) {
            push_front(val);
            return;
        }

        std::shared_ptr<node_t> n_node = std::make_shared<node_t>(val, nullptr);
        if (idx == sz) {
            _tail = n_node;
        }

        /* go to idx - 1th element */
        std::shared_ptr<node_t> curr = _head;
        while (curr && (idx-- > 1u)) {
            curr = curr->next;
        }

        /* now attach new node */
        n_node->next = curr->next;
        curr->next = n_node;
        sz++;
    }

    void remove(size_t idx)
    {
        if (idx >= sz) {
            printf("ERROR: out of range\n");
            return;
        }

        if (idx == 0) {
            pop_front();
            return;
        }

        // navigate to element - 1u
        std::shared_ptr<node_t> elem_before = _head;
        while (elem_before && idx-- > 1u) {
            elem_before = elem_before->next;
        }

        if (idx == sz - 1u) {
            _tail = elem_before;
        }

        // now remove the element and connect rest
        elem_before->next = elem_before->next->next;
        sz--;
    }

    /**
     * @brief
     * @return
     */
    size_t size() const
    {
        return sz;
    }
};

} // namespace ctci