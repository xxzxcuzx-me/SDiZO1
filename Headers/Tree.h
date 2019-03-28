//
// Created by xxzxcuzx_me on 10.03.19.
//

#ifndef SDIZO1_TREE_H
#define SDIZO1_TREE_H

#include <memory>

class Tree {
    class ElementTree {
    public:
        std::shared_ptr<ElementTree> parent;
        std::shared_ptr<ElementTree> leftChild;
        std::shared_ptr<ElementTree> rightChild;
        bool isBlack;
        int value;

        ElementTree() : parent(), leftChild(), rightChild() {
            leftChild = nullptr;
            rightChild = nullptr;
            parent = nullptr;
            isBlack = false;
        }

        ElementTree(int value) : parent(), leftChild(), rightChild() {
            isBlack = false;
            this->value = value;
        }
    };
    std::shared_ptr<ElementTree> guard;
    std::shared_ptr<ElementTree> root;

    std::shared_ptr<ElementTree> findElement(int, std::shared_ptr<ElementTree>);
    std::shared_ptr<ElementTree> findSmallestElement(std::shared_ptr<ElementTree>);
    std::shared_ptr<ElementTree> findNextElement(std::shared_ptr<ElementTree>);
    void rotateLeft(std::shared_ptr<ElementTree>);
    void rotateRight(std::shared_ptr<ElementTree>);
    void printNodeAndItsChildren(std::shared_ptr<ElementTree>, std::string, bool);

public:
    unsigned int size;

    Tree() noexcept;
    void add(int);
    void remove(int);
    void findValue(int);
    void printTree();
    void clear();
    int returnRandomValue();
};


#endif //SDIZO1_TREE_H
