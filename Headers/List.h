//
// Created by xxzxcuzx_me on 09.03.19.
//

#ifndef SDIZO1_LIST_H
#define SDIZO1_LIST_H

#include <memory>

class List {

    class ElementList {
    public:
        int value;
        std::shared_ptr<ElementList> prev;
        std::shared_ptr<ElementList> next;

        ElementList() : prev(), next(){
            value = 0;
            prev = nullptr;
            next = nullptr;
        }

        ElementList(int value) : prev(), next(){
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
    };
    std::shared_ptr<ElementList> head;
    std::shared_ptr<ElementList> tail;

public:
    unsigned int size;

    List() noexcept;
    void addFirst(int);
    void addLast(int);
    void addAt(int, int);
    void deleteFirst();
    void deleteLast();
    void deleteAt(int);
    void findValue(int);
    void printList();
    void clear();
    int returnRandomValue();
};


#endif //SDIZO1_LIST_H
