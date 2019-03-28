//
// Created by xxzxcuzx_me on 10.03.19.
//

#include "Tree.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>

Tree::Tree() noexcept {
    size = 0;

    //Przygotuj wartownika
    guard = std::make_shared<ElementTree>();
    guard->isBlack = true;
    guard->parent = guard;
    guard->leftChild = guard;
    guard->rightChild = guard;
    root = guard;
}

//Wykonaj operację obrotu w lewo wokół wskazanego węzła
void Tree::rotateLeft(std::shared_ptr<Tree::ElementTree> currentElement) {
    auto y = currentElement->rightChild;
    if(y != guard) {
        auto p = currentElement->parent;
        currentElement->rightChild = y->leftChild;
        if(currentElement->rightChild != guard)
            currentElement->rightChild->parent = currentElement;

        y->leftChild = currentElement;
        y->parent = p;
        currentElement->parent = y;

        if(p != guard) {
            if(p->leftChild == currentElement)
                p->leftChild = y;
            else
                p->rightChild = y;
        } else
            root = y;
    }
}

//Wykonaj operację obrotu w prawo wokół wskazanego węzła
void Tree::rotateRight(std::shared_ptr<Tree::ElementTree> currentElement) {
    auto y = currentElement->leftChild;
    if(y != guard) {
        auto p = currentElement->parent;
        currentElement->leftChild = y->rightChild;
        if(currentElement->leftChild != guard)
            currentElement->leftChild->parent = currentElement;

        y->rightChild = currentElement;
        y->parent = p;
        currentElement->parent = y;

        if(p != guard) {
            if(p->leftChild == currentElement)
                p->leftChild = y;
            else
                p->rightChild = y;
        } else
            root = y;
    }
}

void Tree::add(int value) {
    auto Y = std::make_shared<ElementTree>();
    auto X = std::make_shared<ElementTree>(value);
    X->value = value;
    X->leftChild = guard;
    X->rightChild = guard;
    X->parent = root;

    //Sprawdź czy dodajesz pierwszy element
    if(X->parent == guard) {
        root = X;
        size++;
    }
    else {
        while(true) {
            if(value < X->parent->value) {
                if(X->parent->leftChild == guard) {
                    X->parent->leftChild = X;
                    break;
                }
                X->parent = X->parent->leftChild;
            } else if(value > X->parent->value) {
                if(X->parent->rightChild == guard) {
                    X->parent->rightChild = X;
                    break;
                }
                X->parent = X->parent->rightChild;
            } else
                return;
        }

        //Ustaw kolor węzła na czerwony
        X->isBlack = false;
        //Napraw drzewo
        while((X != root) && (!X->parent->isBlack)) {
            if(X->parent == X->parent->parent->leftChild) {
                Y = X->parent->parent->rightChild;

                if(!Y->isBlack) {
                    X->parent->isBlack = true;
                    Y->isBlack = true;
                    X->parent->parent->isBlack = false;
                    X = X->parent->parent;
                    continue;
                }

                if(X == X->parent->rightChild) {
                    X = X->parent;
                    rotateLeft(X);
                }

                X->parent->isBlack = true;
                X->parent->parent->isBlack = false;
                rotateRight(X->parent->parent);
                break;
            } else {
                //Obsłuż przypadki symetryczne
                Y = X->parent->parent->leftChild;

                if(!Y->isBlack) {
                    X->parent->isBlack = true;
                    Y->isBlack = true;
                    X->parent->parent->isBlack = false;
                    X = X->parent->parent;
                    continue;
                }

                if(X == X->parent->leftChild) {
                    X = X->parent;
                    rotateRight(X);
                }

                X->parent->isBlack = true;
                X->parent->parent->isBlack = false;
                rotateLeft(X->parent->parent);
                break;
            }
        }
        root->isBlack = true;
        size++;
    }
}

void Tree::remove(int value) {
    auto toRemove = findElement(value, root);
    if(toRemove == guard)
        std::cout<<"Takiej wartosci nie ma w drzewie\n";

    std::shared_ptr<ElementTree> W, Y, Z;

    if(toRemove->leftChild == guard || toRemove->rightChild == guard)
        Y = toRemove;
    else
        Y = findNextElement(toRemove);

    if(Y->leftChild != guard)
        Z = Y->leftChild;
    else
        Z = Y->rightChild;

    Z->parent = Y->parent;

    if(Y->parent == guard)
        root = Z;
    else if(Y == Y->parent->leftChild)
        Y->parent->leftChild = Z;
    else
        Y->parent->rightChild = Z;
    if(Y != toRemove)
        toRemove->value = Y->value;

    //Napraw drzewo
    if(Y->isBlack) {
        while(Z != root && Z->isBlack) {
            if(Z->parent->leftChild) {
                W = Z->parent->rightChild;

                if(!W->isBlack) {
                    W->isBlack = true;
                    Z->parent->isBlack = false;
                    rotateLeft(Z->parent);
                    W = Z->parent->rightChild;
                }

                if(W->leftChild->isBlack && W->rightChild->isBlack) {
                    W->isBlack = false;
                    Z = Z->parent;
                    continue;
                }

                if(W->rightChild->isBlack) {
                    W->leftChild->isBlack = true;
                    W->isBlack = false;
                    rotateRight(W);
                    W = Z->parent->rightChild;
                }

                W->isBlack = Z->parent->isBlack;
                Z->parent->isBlack = true;
                W->rightChild->isBlack = true;
                rotateLeft(Z->parent);

                Z = root;
            } else {
                //Obsłuż przypadki symetryczne
                W = Z->parent->leftChild;

                if(!W->isBlack) {
                    W->isBlack = true;
                    Z->parent->isBlack = false;
                    rotateLeft(Z->parent);
                    W = Z->parent->leftChild;
                }

                if(W->leftChild->isBlack && W->rightChild->isBlack) {
                    W->isBlack = true;
                    Z = Z->parent;
                    continue;
                }

                if(W->leftChild->isBlack) {
                    W->rightChild->isBlack = true;
                    W->isBlack = false;
                    rotateLeft(W);
                    W = Z->parent->leftChild;
                }

                W->isBlack = Z->parent->isBlack;
                Z->parent->isBlack = true;
                W->leftChild->isBlack = true;
                rotateRight(Z->parent);

                Z = root;
            }
        }
    }
    Z->isBlack = false;
    size--;
}

void Tree::printTree() {
    std::cout<<"Drzewo czerwono-czarne:  (czerwone w nawiasach okraglych, a czarne w kwadratowych)\n";
    if(root != nullptr && root != guard)
        printNodeAndItsChildren(root, "", true);
    else if(size == 0)
        std::cout<<"W drzewie nie ma ani jednego elementu\n";
    else //Nie powinno do tego dojść
        std::cout<<"Wskaźnik na drzewo został uszkodzony\n";
}

void Tree::printNodeAndItsChildren(std::shared_ptr<ElementTree> currentElement, std::string indent, bool last) {
    std::cout<<indent;
    if(last) {
        std::cout<<"\\-";
        indent += "  ";
    } else {
        std::cout<<"|-";
        indent += "| ";
    }
    if(currentElement->isBlack)
        std::cout<<" ["<<currentElement->value<<"]\n";
    else
        std::cout<<" ("<<currentElement->value<<")\n";

    //Jeśli istnieje lewy potomek węzła to go wypisz
    if(currentElement->leftChild != guard)
        printNodeAndItsChildren(currentElement->leftChild, indent, false);
    //Jeśli istnieje prawy potomek węzła to go wypisz
    if(currentElement->rightChild != guard)
        printNodeAndItsChildren(currentElement->rightChild, indent, true);
}

std::shared_ptr<Tree::ElementTree> Tree::findElement(int value, std::shared_ptr<ElementTree> localRoot) {
    if(localRoot != guard) {
        if(localRoot->value == value)
            return localRoot;

        if(value > localRoot->value)
            return findElement(value, localRoot->rightChild);
        else
            return findElement(value, localRoot->leftChild);
    }
    return guard;
}

std::shared_ptr<Tree::ElementTree> Tree::findNextElement(std::shared_ptr<Tree::ElementTree> localRoot) {
    if(localRoot != guard) {
        if(localRoot->rightChild != guard)
            return findSmallestElement(localRoot->rightChild);
        else {
            auto nextElement = localRoot->parent;
            while((nextElement != guard) && (localRoot == nextElement->rightChild)) {
                localRoot = nextElement;
                nextElement = nextElement->parent;
            }
            return nextElement;
        }
    }
    return guard;
}

std::shared_ptr<Tree::ElementTree> Tree::findSmallestElement(std::shared_ptr<Tree::ElementTree> localRoot) {
    if(localRoot != guard)
        while(localRoot->leftChild != guard)
            localRoot = localRoot->leftChild;
    return localRoot;
}

void Tree::findValue(int value) {
    if(findElement(value, root) != guard)
        return;
    //std::cout<<"Wartosc "<<value<<" znajduje sie w drzewie\n";
    else
        std::cout<<"Wartosc "<<value<<" nie znajduje sie w drzewie\n";
}

void Tree::clear() {
    size = 0;

    //Przygotuj wartownika
    guard = std::make_shared<ElementTree>();
    guard->isBlack = true;
    guard->parent = guard;
    guard->leftChild = guard;
    guard->rightChild = guard;
    root = guard;
}

int Tree::returnRandomValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9);

    auto currentElement = root;
    //Drzewo jest puste
    if(currentElement == guard)
        return 0;

    int shouldStop = dis(gen);
    //20 procent szans na zatrzymanie się w obecnym węźle
    while(shouldStop<7) {
        //50 procent szans na pójście w lewo
        int shouldGoLeft = dis(gen)%2;
        if(shouldGoLeft) {
            if(currentElement->leftChild != guard)
                currentElement = currentElement->leftChild;
            else if(currentElement->rightChild != guard)
                currentElement = currentElement->rightChild;
            else
                return currentElement->value;
        } else {
            if(currentElement->rightChild != guard)
                currentElement = currentElement->rightChild;
            else if(currentElement->leftChild != guard)
                currentElement = currentElement->leftChild;
            else
                return currentElement->value;
        }
        shouldStop = dis(gen);
    }
    return currentElement->value;
}