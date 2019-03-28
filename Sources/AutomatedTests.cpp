//
// Created by xxzxcuzx_me on 12.03.19.
//

#include "AutomatedTests.h"
#include "Timer.h"
#include "Array.h"
#include "List.h"
#include "Heap.h"
#include "Tree.h"
#include <iostream>
#include <fstream>
#include <random>

void AutomatedTests::testArray() {
    Timer timer;
    Array array;
    int choice = -1;
    int value;
    int index;
    std::string inputFileName;
    std::string outputFileName;

    std::ifstream inputFile;
    std::ofstream outputFile;

    while(choice != 0) {
        printMenuArray();
        std::cin>>choice;

        //Pomiń pytanie o pliki jeśli masz przerwać lub wypisać tablicę
        if(choice != 0 && choice != 8) {
            std::cout << "Podaj sciezke pliku z danymi testowymi \n>";
            std::cin >> inputFileName;
            std::cout << "Podaj sciezke pliku do ktorego nalezy zapisac dane wyjsciowe \n>";
            std::cin >> outputFileName;

            inputFile.open(inputFileName);
            outputFile.open(outputFileName, std::fstream::out);

            if (!inputFile.is_open()) {
                std::cout << "Nie udalo sie otworzyc pliku " << inputFileName << "\n";
                continue;
            }

            if (!outputFile.is_open()) {
                std::cout << "Nie udalo sie otworzyc pliku " << outputFileName << "\n";
                continue;
            }

            array.clear();
        }

        switch(choice) {
            case 0:
                break;
            case 1:
                while(!inputFile.eof()) {
                    inputFile>>value;
                    timer.start();
                    array.addFirst(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 2:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    timer.start();
                    array.addLast(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 3:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> dis(0, array.size-1);

                    index = dis(gen);
                    timer.start();
                    array.addAt(index, value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 4:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    array.addFirst(value);
                }
                while(array.size > 0) {
                    timer.start();
                    array.deleteFirst();
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 5:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    array.addFirst(value);
                }
                while(array.size > 0) {
                    timer.start();
                    array.deleteLast();
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 6:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    array.addFirst(value);
                }
                while(array.size > 0) {
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> dis(0, array.size-1);

                    index = dis(gen);
                    timer.start();
                    array.deleteAt(index);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 7:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    array.addFirst(value);
                    value = array.returnRandomValue();
                    timer.start();
                    array.findValue(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 8:
                array.printArray();
                break;
            default:
                std::cout<<"Nie ma takiej opcji\n";
        }
        inputFile.close();
        outputFile.close();
    }
}

void AutomatedTests::testList() {
    Timer timer;
    List list;
    int choice = -1;
    int value;
    int index;
    std::string inputFileName;
    std::string outputFileName;

    std::ifstream inputFile;
    std::ofstream outputFile;

    while(choice != 0) {
        printMenuList();
        std::cin>>choice;

        //Pomiń pytanie o pliki jeśli masz przerwać lub wypisać listę
        if(choice != 0 && choice != 8) {
            std::cout << "Podaj sciezke pliku z danymi testowymi \n>";
            std::cin >> inputFileName;
            std::cout << "Podaj sciezke pliku do ktorego nalezy zapisac dane wyjsciowe \n>";
            std::cin >> outputFileName;

            inputFile.open(inputFileName);
            outputFile.open(outputFileName, std::fstream::out);

            if (!inputFile.is_open()) {
                std::cout << "Nie udalo sie otworzyc pliku " << inputFileName << "\n";
                continue;
            }

            if (!outputFile.is_open()) {
                std::cout << "Nie udalo sie otworzyc pliku " << outputFileName << "\n";
                continue;
            }

            list.clear();
        }

        switch(choice) {
            case 0:
                break;
            case 1:
                while(!inputFile.eof()) {
                    inputFile>>value;
                    timer.start();
                    list.addFirst(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 2:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    timer.start();
                    list.addLast(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 3:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    index = list.returnRandomValue();
                    timer.start();
                    list.addAt(index, value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 4:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    list.addFirst(value);
                }
                while(list.size > 0) {
                    timer.start();
                    list.deleteFirst();
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 5:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    list.addFirst(value);
                }
                while(list.size > 0) {
                    timer.start();
                    list.deleteLast();
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 6:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    list.addFirst(value);
                }
                while(list.size > 0) {
                    index = list.returnRandomValue();
                    timer.start();
                    list.deleteAt(index);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 7:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    list.addFirst(value);
                    value = list.returnRandomValue();
                    timer.start();
                    list.findValue(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 8:
                list.printList();
                break;
            default:
                std::cout<<"Nie ma takiej opcji\n";
        }
        inputFile.close();
        outputFile.close();
    }
}

void AutomatedTests::testHeap() {
    Timer timer;
    Heap heap;
    int choice = -1;
    int value;

    std::string inputFileName;
    std::string outputFileName;

    std::ifstream inputFile;
    std::ofstream outputFile;

    while(choice != 0) {
        printMenuHeap();
        std::cin>>choice;

        //Pomiń pytanie o pliki jeśli masz przerwać lub wypisać kopiec
        if(choice != 0 && choice != 4) {
            std::cout << "Podaj sciezke pliku z danymi testowymi \n>";
            std::cin >> inputFileName;
            std::cout << "Podaj sciezke pliku do ktorego nalezy zapisac dane wyjsciowe \n>";
            std::cin >> outputFileName;

            inputFile.open(inputFileName);
            outputFile.open(outputFileName, std::fstream::out);

            if (!inputFile.is_open()) {
                std::cout << "Nie udalo sie otworzyc pliku " << inputFileName << "\n";
                continue;
            }

            if (!outputFile.is_open()) {
                std::cout << "Nie udalo sie otworzyc pliku " << outputFileName << "\n";
                continue;
            }

            heap.clear();
        }

        switch(choice) {
            case 0:
                break;
            case 1:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    timer.start();
                    heap.add(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 2:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    heap.add(value);
                }
                while(heap.size > 0) {
                    value = heap.returnRandomValue();
                    timer.start();
                    heap.remove(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 3:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    heap.add(value);
                    value = heap.returnRandomValue();
                    timer.start();
                    heap.findValue(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 4:
                heap.printHeap();
                break;
            default:
                std::cout<<"Nie ma takiej opcji\n";
        }
        inputFile.close();
        outputFile.close();
    }
}


void AutomatedTests::testTree() {
    Timer timer;
    Tree tree;
    int choice = -1;
    int value;

    std::string inputFileName;
    std::string outputFileName;

    std::ifstream inputFile;
    std::ofstream outputFile;

    while(choice != 0) {
        printMenuTree();
        std::cin>>choice;

        //Pomiń pytanie o pliki jeśli masz przerwać lub wypisać drzewo
        if(choice != 0 && choice != 4) {
            std::cout << "Podaj sciezke pliku z danymi testowymi \n>";
            std::cin >> inputFileName;
            std::cout << "Podaj sciezke pliku do ktorego nalezy zapisac dane wyjsciowe \n>";
            std::cin >> outputFileName;

            inputFile.open(inputFileName);
            outputFile.open(outputFileName, std::fstream::out);

            if (!inputFile.is_open()) {
                std::cout << "Nie udalo sie otworzyc pliku " << inputFileName << "\n";
                continue;
            }

            if (!outputFile.is_open()) {
                std::cout << "Nie udalo sie otworzyc pliku " << outputFileName << "\n";
                continue;
            }

            tree.clear();
        }

        switch(choice) {
            case 0:
                break;
            case 1:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    timer.start();
                    tree.add(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 2:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    tree.add(value);
                }
                while(tree.size > 0){
                    value = tree.returnRandomValue();
                    timer.start();
                    tree.remove(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 3:
                while(!inputFile.eof()) {
                    inputFile >> value;
                    tree.add(value);
                    value = tree.returnRandomValue();
                    timer.start();
                    tree.findValue(value);
                    timer.stop();
                    outputFile<<timer.getDuration()<<"\n";
                }
                break;
            case 4:
                tree.printTree();
                break;
            default:
                std::cout<<"Nie ma takiej opcji\n";
        }
        inputFile.close();
        outputFile.close();
    }
}

void AutomatedTests::printMenuArray() {
    std::cout<<"Operacje na tablicy: \n";
    std::cout<<"  [1] Dodaj na poczatek \n";
    std::cout<<"  [2] Dodaj na koniec \n";
    std::cout<<"  [3] Dodaj pod indeks \n";
    std::cout<<"  [4] Usun z poczatku \n";
    std::cout<<"  [5] Usun z konca \n";
    std::cout<<"  [6] Usun spod indeksu \n";
    std::cout<<"  [7] Znajdz element \n";
    std::cout<<"  [8] Wypisz tablice \n";
    std::cout<<"  [0] Wyjscie \n";
    std::cout<<">";
}

void AutomatedTests::printMenuList() {
    std::cout<<"Operacje na liscie: \n";
    std::cout<<"  [1] Dodaj na poczatek \n";
    std::cout<<"  [2] Dodaj na koniec \n";
    std::cout<<"  [3] Dodaj za elementem \n";
    std::cout<<"  [4] Usun z poczatku \n";
    std::cout<<"  [5] Usun z konca \n";
    std::cout<<"  [6] Usun element \n";
    std::cout<<"  [7] Znajdz element \n";
    std::cout<<"  [8] Wypisz liste \n";
    std::cout<<"  [0] Wyjscie \n";
    std::cout<<">";
}

void AutomatedTests::printMenuHeap() {
    std::cout<<"Operacje na kopcu: \n";
    std::cout<<"  [1] Dodaj element \n";
    std::cout<<"  [2] Usun element \n";
    std::cout<<"  [3] Znajdz element \n";
    std::cout<<"  [4] Wypisz kopiec \n";
    std::cout<<"  [0] Wyjscie \n";
    std::cout<<">";
}

void AutomatedTests::printMenuTree() {
    std::cout<<"Operacje na drzewie: \n";
    std::cout<<"  [1] Dodaj element \n";
    std::cout<<"  [2] Usun element \n";
    std::cout<<"  [3] Znajdz element \n";
    std::cout<<"  [4] Wypisz drzewo \n";
    std::cout<<"  [0] Wyjscie \n";
    std::cout<<">";
}