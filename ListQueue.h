//
// Created by konstantin-ub on 30.05.17.
//

#ifndef TEMPLATETRAINING_LISTQUEUE_H
#define TEMPLATETRAINING_LISTQUEUE_H

#include "LinkedList.h"
#include "BufferQueue.h"


template <typename ItemType, size_t N>
class ListQueue {
public:
    ListQueue ();
    ~ListQueue() {}

    void push(const ItemType& value);
    void pop();

    bool isEmpty() const;

    void print() const;

private:
    LinkedList<BufferQueue<ItemType, N>> list;
    int nodeCounter, size;
};

template <typename ItemType, size_t N>
ListQueue<ItemType, N>::ListQueue():
size(0),
nodeCounter(0) {}

template <typename ItemType, size_t N>
void ListQueue<ItemType, N>::push(const ItemType &value) {
    if(!nodeCounter || list[nodeCounter - 1].isFull()) {
        BufferQueue<ItemType, N> *tmpBuf = new BufferQueue<ItemType, N>;
        tmpBuf->push(value);
        list.addInTail(*tmpBuf);
        nodeCounter++;
    } else {
        list[nodeCounter - 1].push(value);
    }
    size++;
}

template <typename ItemType, size_t N>
void ListQueue<ItemType, N>::pop() {
    if(isEmpty())
        return;
    list[0].pop();
    size--;
    if(list[0].isEmpty()) {
        list.removeFromHead();
        nodeCounter--;
        return;
    }
    //какая-то дичь
    for(int i = 0; i < nodeCounter - 1; i++) {
        list[i].push(list[i + 1].pop());
    }
    if(list[nodeCounter - 1].isEmpty()) {
        list.removeFromTail();
        nodeCounter--;
    }
}

template <typename ItemType, size_t N>
bool ListQueue<ItemType, N>::isEmpty() const {
    return size == 0;
}

template <typename ItemType, size_t N>
void ListQueue<ItemType, N>::print() const {
    for(int i = 0; i < nodeCounter; i++) {
        std::cout << "(";
        list[i].printBuf();
        std::cout << ") ";
    }
    std::cout << std::endl;
}

#endif //TEMPLATETRAINING_LISTQUEUE_H
