#ifndef cache_hpp
#define cache_hpp

#include <string_view>
#include <vector>
#include <cstdint>

// default cache class that others inherit from
class cache {
protected:
    // basic cache properties
    size_t capacity; // size of cache in bytes
    size_t threshold; // maximum possible size of object in cache
    size_t usage; // total size of objects in cache in bytes

    virtual void evict() = 0;
public:
    // create and destroy a cache
    cache(size_t cap, size_t thr):
    capacity(cap),
    threshold(thr),
    usage(0) {}

    ~cache(){}

    // check if item exists
    virtual bool get(uint64_t id) = 0;

    // add item
    virtual void set(uint64_t id, uint32_t size) = 0;

    // purge specific item
    virtual void evict(uint64_t id) = 0;

    // get name of cache
    virtual std::string_view name() const = 0;
};

#endif
