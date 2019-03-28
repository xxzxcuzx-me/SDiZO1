#include <iostream>
#include "Tests.h"
#include "AutomatedTests.h"

void printMenu() {
    std::cout<<"Dostepne testy: \n";
    std::cout<<"  [1] Tablica \n";
    std::cout<<"  [2] Lista \n";
    std::cout<<"  [3] Kopiec \n";
    std::cout<<"  [4] Drzewo \n";
    std::cout<<"  [0] Wyjscie \n";
    std::cout<<">";
}

int main() {
    Tests tests;
    AutomatedTests automatedTests;
    int choice = -1;
    char automated;
    std::cout<<"\tProjekt SDiZO 1\n";
    std::cout<<"Imię i nazwisko: Mateusz Wojciechowski\n Numer indeksu: 241307\n";
    while(choice != 0) {
        printMenu();
        std::cin>>choice;

        if(choice == 0)
            break;

        std::cout<<"Czy test ma byc automatyczny?(t/n)\n>";
        std::cin>>automated;
        switch(choice) {
            case 0:
                break;
            case 1:
                if(automated == 't')
                    automatedTests.testArray();
                else
                    tests.testArray();
                break;
            case 2:
                if(automated == 't')
                    automatedTests.testList();
                else
                    tests.testList();
                break;
            case 3:
                if(automated == 't')
                    automatedTests.testHeap();
                else
                    tests.testHeap();
                break;
            case 4:
                if(automated == 't')
                    automatedTests.testTree();
                else
                    tests.testTree();
                break;
            default:
                std::cout<<"Nie ma takiej opcji\n";
        }
    }
    return 0;
}