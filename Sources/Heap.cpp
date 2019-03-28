//
// Created by xxzxcuzx_me on 10.03.19.
//

#include "Heap.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>

Heap::Heap() noexcept {
    size = 0;
    root = nullptr;
}

void Heap::add(int value) {
    auto newHeap = std::make_unique<int []>(size+1);
    for(int i=0; i<size; i++)
        newHeap[i] = root[i];

    newHeap[size] = value;
    root = std::move(newHeap);
    size++;

    //Konieczna naprawa kopca w górę
    repairHeapUp();
}

void Heap::remove(int value) {
    if(isInHeap(value)) {
        auto newHeap = std::make_unique<int []>(size-1);
        int i=0;
        while(root[i] != value) {
            newHeap[i] = root[i];
            i++;
        }
        if(i != size-1) {
            //Wstaw ostatni węzeł na miejsce usuwanego węzła
            newHeap[i] = root[size - 1];
            int removedNodeIndex = i;
            i++;
            for (; i < size - 1; i++) {
                newHeap[i] = root[i];
            }
            root = std::move(newHeap);
            size--;
            //Konieczna naprawa zarówno w górę jak i w dół
            repairHeapUp();
            repairHeapDown(removedNodeIndex);
        } else {
            //Nie ma potrzeby dodawać reszty elementów i poprawiać kopca
            root = std::move(newHeap);
            size--;
        }
    } else
        std::cout<<"Wartości "<<value<<" nie ma w kopcu\n";
}

void Heap::printHeap() {
    std::cout<<"Kopiec:\n";
    if(root != nullptr)
        printNodeAndItsChildren(0, "", true);
    else if(size == 0)
        std::cout<<"W kopcu nie ma ani jednego elementu\n";
    else //Nie powinno do tego dojść
        std::cout<<"Wskaźnik na kopiec został uszkodzony\n";
}

void Heap::printNodeAndItsChildren(int index, std::string indent, bool last) {
    std::cout<<indent;
    if(last) {
        std::cout<<"\\-";
        indent += "  ";
    } else {
        std::cout<<"|-";
        indent += "| ";
    }
    std::cout<<" "<<root[index]<<"\n";

    //Jeśli istnieje lewy potomek węzła to go wypisz
    if(2*index+1<size)
        printNodeAndItsChildren(2*index + 1, indent, false);
    //Jeśli istnieje prawy potomek węzła to go wypisz
    if((2*index+2)<size)
        printNodeAndItsChildren(2*index + 2, indent, true);
}

bool Heap::isInHeap(int value) {
    if(root == nullptr)
        return false;

    for(int i=0; i<size; i++)
        if(root[i] == value)
            return true;

    return false;
}

void Heap::findValue(int value) {
    if(isInHeap(value))
        return;
        //std::cout<<"Wartosc "<<value<<" znajduje sie w kopcu\n";
    else
        std::cout<<"Wartosc "<<value<<" nie znajduje sie w kopcu\n";
}

void Heap::repairHeapUp() {
    int tmpValue;
    int currentIndex = size-1;
    int parentIndex = (currentIndex - 1)/2;

    //Wykonuj dopóki obecny węzeł nie jest korzeniem
    //i wartość jego rodzica jest mniejsza od jego wartości
    while(currentIndex>0 && root[parentIndex] < root[currentIndex]) {
        tmpValue = root[parentIndex];
        root[parentIndex] = root[currentIndex];
        root[currentIndex] = tmpValue;
        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }
}

void Heap::repairHeapDown(int currentIndex) {
    //Sprawdź czy nie mamy już do czynienia z liściem
    if(2*currentIndex >= size)
        return;

    int tmpValue;
    int biggerChildIndex;
    //Jeśli jest tylko jeden potomek to musi być on większy
    if(2*currentIndex+1 >= size)
        biggerChildIndex = 2*currentIndex;
    //Jeśli są dwaj potomkowie to wybierz większego
    else {
        if (root[2 * currentIndex] > root[2 * currentIndex + 1])
            biggerChildIndex = 2 * currentIndex;
        else
            biggerChildIndex = 2 * currentIndex + 1;
    }
    //Wykonuj dopóki istnieją potomkowie obecnego węzła
    //i wartość większego z nich jest mniejsza od jego wartości
    while(root[currentIndex] < root[biggerChildIndex]) {
        tmpValue = root[biggerChildIndex];
        root[biggerChildIndex] = root[currentIndex];
        root[currentIndex] = tmpValue;
        currentIndex = biggerChildIndex;

        //Sprawdź czy nie mamy już do czynienia z liściem
        if(2*currentIndex >= size)
            return;
        //Jeśli jest tylko jeden potomek to musi być on większy
        if(2*currentIndex+1 >= size)
            biggerChildIndex = 2*currentIndex;
        //Jeśli są dwaj potomkowie to wybierz większego
        else {
            if (root[2 * currentIndex] > root[2 * currentIndex + 1])
                biggerChildIndex = 2 * currentIndex;
            else
                biggerChildIndex = 2 * currentIndex + 1;
        }
    }
}

void Heap::clear() {
    root = nullptr;
    size = 0;
}

int Heap::returnRandomValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size-1);

    int index = dis(gen);
    return root[index];
}