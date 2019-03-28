//
// Created by xxzxcuzx_me on 10.03.19.
//

#ifndef SDIZO1_HEAP_H
#define SDIZO1_HEAP_H

#include <memory>

class Heap {

    std::unique_ptr<int []> root;

    bool isInHeap(int);
    void repairHeapUp();
    void repairHeapDown(int);
    void printNodeAndItsChildren(int, std::string, bool);

public:
    unsigned int size;

    Heap() noexcept;
    void add(int);
    void remove(int);
    void findValue(int);
    void printHeap();
    void clear();
    int returnRandomValue();
};


#endif //SDIZO1_HEAP_H
