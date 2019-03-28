//
// Created by xxzxcuzx_me on 09.03.19.
//

#ifndef SDIZO1_ARRAY_H
#define SDIZO1_ARRAY_H


#include <bits/unique_ptr.h>

class Array {
    std::unique_ptr<int []> head;
public:
    unsigned int size;

    Array() noexcept;
    void addFirst(int);
    void addLast(int);
    void addAt(int, int);
    void deleteFirst();
    void deleteLast();
    void deleteAt(int);
    void findValue(int);
    void printArray();
    void clear();
    int returnRandomValue();
};


#endif //SDIZO1_ARRAY_H
