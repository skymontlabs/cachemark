# cachemark

Benchmarking hit rate and throughput for various C++ cache replacement policies. This by no means includes ready-to-use templates for your own C++ web server, but can be easily changed in order to include such.

Most of these are based upon other implementations, while some have just been created as new here.

## Roadmap

v.1.1

- multiple classes of objects in the trace generator and cache class
- changing request sizes for same id, corresponds to changed content in practice
- trace parsers for actual HTTP requests

v.1.2

- deep reinforcement learning policy
- deep q-learning policy

## Compile

    cmake .
    make
    sudo make test
    ./test

## Traces

Request traces must be given in a space-separated format with two
- id should be a 64-bit unsigned int (unique identifier)
- size should be a 64-bit unsigned int (size of request in bytes)

| id  | size |
| --- | ---- |
|   1 |  440 |
|   2 |  204 |
|   1 |  440 |
|   3 |  195 |
|   4 |  102 |


## Available caching policies
All cache policies inherit from cache in "cache.hpp"

#### Static caching methods
Traditional "dummy" methods that don't change based upon new data.

- LRU (least-recently used)
- GDSF (greedy dual size-frequency)

#### Dynamic caching methods
Adaptive methods that attempt to learn certain distributions, etc.

- QSF (quadratic size-frequency eviction)
- LHD (least hit-density)
- AdaptSize (dynamic exp-lru)

## References

The following works were used

    AdaptSize: Orchestrating the Hot Object Memory Cache in a CDN
    Daniel S. Berger, Ramesh K. Sitaraman, Mor Harchol-Balter
    USENIX NSDI, March 2017.
    
    LHD: Improving Cache Hit Rate by Maximizing Hit Density
    Nathan Beckmann, Haoxian Chen, Asaf Cidon
    USENIX NSDI, April 2018.
