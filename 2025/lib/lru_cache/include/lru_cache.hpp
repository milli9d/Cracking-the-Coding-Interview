#include <iostream>
#include <list>
#include <unordered_map>

namespace ctci {

template<size_t S>
class lru_cache
{
  private:
    size_t _cap{ S };
    std::list<int> _lru_q;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> _map;

    void _evict_lru()
    {
        /* evict oldest key */
        int key = _lru_q.back();
        _lru_q.pop_back();
        _map.erase(key);
    }

    void _update(const int& key, const int& val)
    {
        if (!_map.count(key)) {
            std::cerr << "ERROR: key not found in cache" << std::endl;
            return;
        }

        /* find entry in queue and pop and push back */
        auto entry = _map.find(key);
        auto q_entry = entry->second.second;

        _lru_q.erase(q_entry);
        _lru_q.push_front(key);

        _map[key] = { val, _lru_q.begin() };
    }

  public:
    friend std::ostream& operator<<(std::ostream& os, lru_cache<S>& obj)
    {
        os << "Size = " << obj._lru_q.size() << std::endl;
        for (const auto& key: obj._lru_q) {
            os << "[ " << key << " | ";
            auto entry = obj._map.find(key);
            if (entry != obj._map.end()) {
                os << entry->second.first;
            } else {
                os << "NOT FOUND";
            }
            os << " ] -> ";
        }
        os << std::endl;
        return os;
    }

    void push(const int& key, const int& val)
    {
        /* first if this key exists, then just update it */
        if (_map.find(key) != _map.end()) {
            _update(key, val);
            return;
        }

        /* evict if we are full */
        if (_lru_q.size() + 1u > _cap) {
            _evict_lru();
        }

        /* now insert */
        _lru_q.push_front(key);
        _map[key] = { val, _lru_q.begin() };
    };

    void read(int key)
    {
        /* find the key */
        if (_map.find(key) != _map.end()) {
            /* read the key and push back to front */
            auto entry = _map.find(key);
            auto q_entry = entry->second.second;
            auto val = entry->second.first;

            _lru_q.erase(q_entry);
            printf("Found [ key %4d | val %4d ]\n", key, val);
            _lru_q.push_front(key);
            _map[key] = { val, _lru_q.begin() };
        }
    }
};

} // namespace ctci