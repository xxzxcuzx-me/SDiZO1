//
// Created by xxzxcuzx_me on 09.03.19.
//

#include "Array.h"
#include <iostream>
#include <random>

Array::Array() noexcept {
    size = 0;
    head = std::unique_ptr<int []>(new int [0]);
}

void Array::addFirst(int value) {
    size++;
    //Rozszerz tablicę
    auto newHead = std::make_unique<int []>(size);
    //Dodaj nowy element
    newHead[0] = value;
    //Dodaj elementy ze starej tablicy
    for(int i = 0; i<size-1; i++)
        newHead[i + 1] = head[i];

    //Przenieś unique_ptr z newHead na head
    head = std::move(newHead);
}

void Array::addLast(int value) {
    size++;
    //Rozszerz tablicę
    auto newHead = std::make_unique<int []>(size);
    int i = 0;
    //Dodaj elementy ze starej tablicy
    for(; i<size-1; i++)
        newHead[i] = head[i];
    //Dodaj nowy element
    newHead[i] = value;

    //Przenieś unique_ptr z newHead na head
    head = std::move(newHead);
}

void Array::addAt(int index, int value) {
    if(index == 0) {
        addFirst(value);
        return;
    }

    if(index > 0 && index < size) {
        size++;
        //Rozszerz tablicę
        auto newHead = std::make_unique<int []>(size);
        int i = 0;
        //Dodaj elementy z pierwszej części starej tablicy
        for (; i < index; i++)
            newHead[i] = head[i];
        //Dodaj nowy element
        newHead[i] = value;
        i++;
        //Dodaj elementy z drugiej części starej tablicy
        for (; i < size; i++)
            newHead[i] = head[i - 1];

        //Przenieś unique_ptr z newHead na head
        head = std::move(newHead);
    } else
        std::cout<<"Nie ma takiego indeksu\n";
}

void Array::deleteFirst() {
    if(size > 0) {
        //Zmniejsz tablicę
        size--;
        auto newHead = std::make_unique<int []>(size);
        //Dodaj elementy ze starej tablicy pomijając pierwszy
        for (int i = 0; i < size; i++)
            newHead[i] = head[i + 1];

        //Przenieś unique_ptr z newHead na head
        head = std::move(newHead);
    } else
        std::cout<<"Tablica jest pusta\n";
}

void Array::deleteLast() {
    //Zmniejsz tablicę
    if (size > 0) {
        size--;
        auto newHead = std::make_unique<int []>(size);
        //Dodaj elementy ze starej tablicy pomijając ostatni
        for (int i = 0; i < size; i++)
            newHead[i] = head[i];

        //Przenieś unique_ptr z newHead na head
        head = std::move(newHead);
    } else
        std::cout<<"Tablica jest pusta\n";
}

void Array::deleteAt(int index) {
    if(index == 0) {
        deleteFirst();
        return;
    }

    //Zmniejsz tablicę
    if(index > 0 && index < size) {
        size--;
        auto newHead = std::make_unique<int []>(size);
        int i = 0;
        //Dodaj elementy z pierwszej części starej tablicy
        for (; i < index; i++)
            newHead[i] = head[i];
        //Pomijamy dodanie elementu, który mamy usunąć
        //Dodaj elementy z drugiej części starej tablicy
        for (; i < size; i++)
            newHead[i] = head[i + 1];

        //Przenieś unique_ptr z newHead na head
        head = std::move(newHead);
    } else
        std::cout<<"Nie ma takiego elementu\n";
}

void Array::findValue(int value) {
    for(int i=0; i<size; i++) {
        if(head[i] == value) {
            //std::cout<<"Wartosc "<<value<<" znajduje sie na "<<i<<" pozycji\n";
            return;
        }
    }
    std::cout<<"Wartosc "<<value<<" nie znajduje sie w tablicy\n";
}

void Array::printArray() {
    std::cout<<"Tablica:\n";
    if(head != nullptr)
        for (int i = 0; i < size; i++)
            std::cout << "[" << i << "] " << head[i] << "\n";
    else if(size == 0)
            std::cout<<"W tablicy nie ma ani jednego elementu\n";
        else //Nie powinno do tego dojść
            std::cout<<"Wskaźnik na tablicę został uszkodzony\n";
}

void Array::clear() {
    while(size > 0)
        deleteLast();
}

int Array::returnRandomValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size-1);

    int index = dis(gen);
    return head[index];
}