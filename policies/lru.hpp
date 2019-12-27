#ifndef lru_hpp
#define lru_hpp

#include "cache.hpp"
#include <unordered_map>
#include <list>

class lru : public cache {
    typedef std::list<std::pair<uint64_t, size_t> > lru_list;
    typedef std::unordered_map<uint64_t, lru_list::iterator> cache_map;

    lru_list ll;
    cache_map cm;

    virtual void evict();

    virtual void hit(lru_list::iterator it);
public:
    lru(size_t capacity, size_t threshold):
    cache(capacity, threshold) {}

    ~lru() {}

    virtual bool get(uint64_t id);

    virtual void set(uint64_t id, size_t size);

    virtual void evict(uint64_t id);

    virtual std::string_view name() const { return std::string_view("lru"); }
};

#endif /* lru_hpp */
