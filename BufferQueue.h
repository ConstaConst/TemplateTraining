//
// Created by konstantin-ub on 30.05.17.
//

#ifndef TEMPLATETRAINING_BUFFERQUEUE_H
#define TEMPLATETRAINING_BUFFERQUEUE_H

#include <cstddef>
#include <iostream>

template <typename ItemType, size_t N>
class BufferQueue {
public:
    BufferQueue();
    BufferQueue<ItemType, N>& push(const ItemType& item);
    ItemType pop();

    bool isFull() const;
    bool isEmpty() const;

    void printBuf() const {
        for(int i  = 0; i < bufSize; i++)
            if (i < counter)
                std::cout << buffer[i] << " ";
            else
                std::cout << "_ ";
    }
    ~BufferQueue();

private:
    ItemType* buffer;
    const size_t bufSize;

    size_t counter;
};

template <typename ItemType, size_t N>
BufferQueue<ItemType, N>::BufferQueue():
bufSize(N),
buffer(new ItemType [N]),
counter(0) {}

template <typename ItemType, size_t N>
BufferQueue<ItemType, N>::~BufferQueue() {
    delete [] buffer;
};

template <typename ItemType, size_t N>
BufferQueue<ItemType, N>& BufferQueue<ItemType, N>::push(const ItemType &item) {
    buffer[counter] = item;
    counter++;
}

template <typename ItemType, size_t N>
ItemType BufferQueue<ItemType, N>::pop() {
    ItemType temp = buffer[0];

    for(int i = 0; i < counter - 1; i++) {
        buffer[i] = buffer[i + 1];
    }
    counter--;

    return temp;
}

template <typename ItemType, size_t N>
bool BufferQueue<ItemType, N>::isFull() const {
    return counter == bufSize;
}

template <typename ItemType, size_t N>
bool BufferQueue<ItemType, N>::isEmpty() const {
    return counter == 0;
}

#endif //TEMPLATETRAINING_BUFFERQUEUE_H
