//
// Created by xxzxcuzx_me on 12.03.19.
//

#include "Tests.h"
#include "Timer.h"
#include "Array.h"
#include "List.h"
#include "Heap.h"
#include "Tree.h"
#include <iostream>
#include <fstream>

void Tests::testArray() {
    Timer timer;
    Array array;
    int choice = -1;
    int value;
    int index;
    std::ifstream inputFile;
    std::string inputFileName;

    while(choice != 0) {
        printMenuArray();
        std::cin>>choice;
        switch(choice) {
            case 0:
                break;
            case 1:
                value = getValue();
                timer.start();
                array.addFirst(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 2:
                value = getValue();
                timer.start();
                array.addLast(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 3:
                value = getValue();
                index = getIndex();
                timer.start();
                array.addAt(index, value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 4:
                timer.start();
                array.deleteFirst();
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 5:
                timer.start();
                array.deleteLast();
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 6:
                index = getIndex();
                timer.start();
                array.deleteAt(index);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 7:
                value = getValue();
                timer.start();
                array.findValue(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 8:
                array.printArray();
                break;
            case 9:
                std::cout << "Podaj sciezke pliku z danymi \n>";
                std::cin >> inputFileName;
                inputFile.open(inputFileName);

                if (!inputFile.is_open()) {
                    std::cout << "Nie udalo sie otworzyc pliku " << inputFileName << "\n";
                    continue;
                }
                while(!inputFile.eof()) {
                    inputFile >> value;
                    array.addLast(value);
                }
                break;
            default:
                std::cout<<"Nie ma takiej opcji\n";
        }
    }
}

void Tests::testList() {
    Timer timer;
    List list;
    int choice = -1;
    int value;
    int addAfterThat;
    std::ifstream inputFile;
    std::string inputFileName;

    while(choice != 0) {
        printMenuList();
        std::cin>>choice;
        switch(choice) {
            case 0:
                break;
            case 1:
                value = getValue();
                timer.start();
                list.addFirst(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 2:
                value = getValue();
                timer.start();
                list.addLast(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 3:
                std::cout<<"Za ta wartoscia zostanie dodana nowa wartosc\n";
                addAfterThat = getValue();
                std::cout<<"Nowa wartosc\n";
                value = getValue();
                timer.start();
                list.addAt(addAfterThat, value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 4:
                timer.start();
                list.deleteFirst();
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 5:
                timer.start();
                list.deleteLast();
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 6:
                value = getValue();
                timer.start();
                list.deleteAt(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 7:
                value = getValue();
                timer.start();
                list.findValue(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 8:
                list.printList();
                break;
            case 9:
                std::cout << "Podaj sciezke pliku z danymi \n>";
                std::cin >> inputFileName;
                inputFile.open(inputFileName);

                if (!inputFile.is_open()) {
                    std::cout << "Nie udalo sie otworzyc pliku " << inputFileName << "\n";
                    continue;
                }
                while(!inputFile.eof()) {
                    inputFile >> value;
                    list.addLast(value);
                }
                break;
            default:
                std::cout<<"Nie ma takiej opcji\n";
        }
    }
}

void Tests::testHeap() {
    Timer timer;
    Heap heap;
    int choice = -1;
    int value;
    std::ifstream inputFile;
    std::string inputFileName;

    while(choice != 0) {
        printMenuHeap();
        std::cin>>choice;
        switch(choice) {
            case 0:
                break;
            case 1:
                value = getValue();
                timer.start();
                heap.add(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 2:
                value = getValue();
                timer.start();
                heap.remove(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 3:
                value = getValue();
                timer.start();
                heap.findValue(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 4:
                heap.printHeap();
                break;
            case 5:
                std::cout << "Podaj sciezke pliku z danymi \n>";
                std::cin >> inputFileName;
                inputFile.open(inputFileName);

                if (!inputFile.is_open()) {
                    std::cout << "Nie udalo sie otworzyc pliku " << inputFileName << "\n";
                    continue;
                }
                while(!inputFile.eof()) {
                    inputFile >> value;
                    heap.add(value);
                }
                break;
            default:
                std::cout<<"Nie ma takiej opcji\n";
        }
    }
}


void Tests::testTree() {
    Timer timer;
    Tree tree;
    int choice = -1;
    int value;
    std::ifstream inputFile;
    std::string inputFileName;

    while(choice != 0) {
        printMenuTree();
        std::cin>>choice;
        switch(choice) {
            case 0:
                break;
            case 1:
                value = getValue();
                timer.start();
                tree.add(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 2:
                value = getValue();
                timer.start();
                tree.remove(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 3:
                value = getValue();
                timer.start();
                tree.findValue(value);
                timer.stop();
                printTime(timer.getDuration());
                break;
            case 4:
                tree.printTree();
                break;
            case 5:
                std::cout << "Podaj sciezke pliku z danymi \n>";
                std::cin >> inputFileName;
                inputFile.open(inputFileName);

                if (!inputFile.is_open()) {
                    std::cout << "Nie udalo sie otworzyc pliku " << inputFileName << "\n";
                    continue;
                }
                while(!inputFile.eof()) {
                    inputFile >> value;
                    tree.add(value);
                }
                break;
            default:
                std::cout<<"Nie ma takiej opcji\n";
        }
    }
}
void Tests::printTime(long time) {
    std::cout<<"Czas wykonania wyniosl "<<time<<" nanosekund\n";
}

int Tests::getValue() {
    std::cout<<"Podaj wartosc: ";
    int value;
    std::cin>>value;
    return value;
}

int Tests::getIndex() {
    std::cout<<"Podaj indeks: ";
    int index;
    std::cin>>index;
    return index;
}

void Tests::printMenuArray() {
    std::cout<<"Operacje na tablicy: \n";
    std::cout<<"  [1] Dodaj na poczatek \n";
    std::cout<<"  [2] Dodaj na koniec \n";
    std::cout<<"  [3] Dodaj pod indeks \n";
    std::cout<<"  [4] Usun z poczatku \n";
    std::cout<<"  [5] Usun z konca \n";
    std::cout<<"  [6] Usun spod indeksu \n";
    std::cout<<"  [7] Znajdz element \n";
    std::cout<<"  [8] Wypisz tablice \n";
    std::cout<<"  [9] Zbuduj z pliku \n";
    std::cout<<"  [0] Wyjscie \n";
    std::cout<<">";
}

void Tests::printMenuList() {
    std::cout<<"Operacje na liscie: \n";
    std::cout<<"  [1] Dodaj na poczatek \n";
    std::cout<<"  [2] Dodaj na koniec \n";
    std::cout<<"  [3] Dodaj za elementem \n";
    std::cout<<"  [4] Usun z poczatku \n";
    std::cout<<"  [5] Usun z konca \n";
    std::cout<<"  [6] Usun element \n";
    std::cout<<"  [7] Znajdz element \n";
    std::cout<<"  [8] Wypisz liste \n";
    std::cout<<"  [9] Zbuduj z pliku \n";
    std::cout<<"  [0] Wyjscie \n";
    std::cout<<">";
}

void Tests::printMenuHeap() {
    std::cout<<"Operacje na kopcu: \n";
    std::cout<<"  [1] Dodaj element \n";
    std::cout<<"  [2] Usun element \n";
    std::cout<<"  [3] Znajdz element \n";
    std::cout<<"  [4] Wypisz kopiec \n";
    std::cout<<"  [5] Zbuduj z pliku \n";
    std::cout<<"  [0] Wyjscie \n";
    std::cout<<">";
}

void Tests::printMenuTree() {
    std::cout<<"Operacje na drzewie: \n";
    std::cout<<"  [1] Dodaj element \n";
    std::cout<<"  [2] Usun element \n";
    std::cout<<"  [3] Znajdz element \n";
    std::cout<<"  [4] Wypisz drzewo \n";
    std::cout<<"  [5] Zbuduj z pliku \n";
    std::cout<<"  [0] Wyjscie \n";
    std::cout<<">";
}