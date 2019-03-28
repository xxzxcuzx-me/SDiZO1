//
// Created by xxzxcuzx_me on 09.03.19.
//

#include "List.h"
#include <iostream>
#include <random>
List::List() noexcept : head(), tail() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

void List::addFirst(int value) {
    if(size > 0) {
        auto newHead = std::make_shared<ElementList>(value);
        newHead->next = head;
        head->prev = newHead;
        head = newHead;
    } else {
        //Jeśli dodajemy pierwszy element na liście to head i tail są takie same
        head = std::make_shared<ElementList>(value);
        tail = head;
    }
    size++;
}

void List::addLast(int value) {
    if(size > 0) {
        auto newTail = std::make_shared<ElementList>(value);
        newTail->prev = tail;
        tail->next = newTail;
        tail = newTail;
    } else {
        //Jeśli dodajemy pierwszy element na liście to head i tail są takie same
        head = std::make_shared<ElementList>(value);
        tail = head;
    }
    size++;
}

void List::addAt(int addAfterThat, int value) {
    //Sprawdź czy lista nie jest pusta
    if(head == nullptr) {
        addFirst(value);
        return;
    }

    auto currentElement = head;
    while(currentElement->value != addAfterThat && currentElement->next != nullptr)
        currentElement = currentElement->next;

    if(currentElement->value == addAfterThat) {
        auto newElement = std::make_shared<ElementList>(value);
        newElement->prev = currentElement;
        newElement->next = currentElement->next;
        //Sprawdź czy obecny element nie jest ostatnim, jeśli tak to zaktualizuj tail
        if(currentElement->next != nullptr)
            currentElement->next->prev = newElement;
        else
            tail = newElement;
        currentElement->next = newElement;
        size++;
    } else
        std::cout<<"Nie ma takiego elementu\n";
}

void List::deleteFirst() {
    if(size > 0) {
        size--;
        head = head->next;
        if(head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
    } else
        std::cout<<"Lista jest pusta\n";
}

void List::deleteLast() {
    if(size > 0) {
        size--;
        tail = tail->prev;
        if(tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;
    } else
        std::cout<<"Lista jest pusta\n";
}

void List::deleteAt(int value) {
    //Sprawdź czy lista nie jest pusta
    if(head == nullptr) {
        std::cout<<"Nie ma takiego elementu\n";
        return;
    }

    auto currentElement = head;
    while(currentElement->value != value && currentElement->next != nullptr)
        currentElement = currentElement->next;

    if(currentElement->value == value) {
        //Sprawdź czy obecny element nie jest pierwszym, jeśli tak to zaktualizuj head
        if(currentElement->prev != nullptr)
            currentElement->prev->next = currentElement->next;
        else
            head = currentElement->next;
        //Sprawdź czy obecny element nie jest ostatnim, jeśli tak to zaktualizuj tail
        if(currentElement->next != nullptr)
            currentElement->next->prev = currentElement->prev;
        else
            tail = currentElement->prev;

        size--;
    } else
        std::cout<<"Nie ma takiego elementu\n";
}

void List::findValue(int value) {
    int i = 0;
    auto current = head;
    while(current != nullptr) {
        if(current->value == value) {
            //std::cout<<"Wartosc "<<value<<" znajduje sie na "<<i<<" pozycji\n";
            return;
        }
        i++;
        current = current->next;
    }
    std::cout<<"Wartosc "<<value<<" nie znajduje sie na liscie\n";
}

void List::printList() {
    std::cout<<"Lista:\n";
    if(size == 0)
        std::cout<<"Lista jest pusta\n";
    auto current = head;
    int counter = 0;
    while(current != nullptr) {
        std::cout<<"["<<counter<<"] "<<current->value<<"\n";
        current = current->next;
        counter++;
    }
}

void List::clear() {
    while(size > 0)
        deleteLast();
}

int List::returnRandomValue() {
    if(size>0) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, size-1);
        int index = dis(gen);
        auto currentElement = head;
        //Lista jest pusta
        if (currentElement == nullptr)
            return 0;

        for (int i = 0; i < index; i++)
            currentElement = currentElement->next;
        return currentElement->value;
    } else
        return 0;
}