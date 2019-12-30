# cachemark

Benchmarking hit rate and throughput for various C++ cache replacement policies. This by no means includes ready-to-use templates for your own C++ web server, but can be easily changed in order to include such.

Most of these are based upon other implementations, while some have just been created as new here.

## Roadmap

v.1.1 (February 2020)

- multiple classes of objects in the trace generator and cache class
- changing request sizes for same id, corresponds to changed content in practice
- trace parsers for actual HTTP requests

v.1.2 (March/April 2020)

- machine learning based algorithms

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

- lru.hpp (least-recently used)
- gdsf.hpp (greedy dual size-frequency)
- wtflu.hpp (window tiny-lfu)
- hyp.hpp (hyperbolic)
- lhd.hpp (least hit-density)

## References

The following works were used

    LHD: Improving Cache Hit Rate by Maximizing Hit Density
    Nathan Beckmann, Haoxian Chen, Asaf Cidon
    USENIX NSDI, April 2018.
