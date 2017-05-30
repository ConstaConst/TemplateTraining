//
// Created by konstantin-ub on 30.05.17.
//

#ifndef TEMPLATETRAINING_LINKEDLIST_H
#define TEMPLATETRAINING_LINKEDLIST_H


#include <glob.h>
#include <iostream>

template <typename ItemType>
class LinkedListNode
{
private:
    LinkedListNode<ItemType>* next;
    LinkedListNode<ItemType>* prev;

    LinkedListNode(const ItemType& value,
                   LinkedListNode<ItemType>* nextNode,
                   LinkedListNode<ItemType>* prevNode)
            : data(value), next(nextNode), prev(prevNode)
    {
        if (nextNode)
            nextNode->prev = this;
        if (prevNode)
            prevNode->next = this;
    }
public:
    ItemType data;
    LinkedListNode(const ItemType& value) : data(value)
    {
        next = prev = nullptr;
    }
    LinkedListNode<ItemType>* addAfter(const ItemType& value)
    {
        return new LinkedListNode<ItemType>(value, this->next, this);
    }

    LinkedListNode<ItemType>* operator[] (const int index)
    {
        int i = index;
        LinkedListNode<ItemType>* pointer = this;
        if (i >= 0)
            while (i-- && pointer->next)
                pointer = pointer->next;
        else
            while (i++ && pointer->prev)
                pointer = pointer->prev;
        return pointer;
    }
    void remove()
    {
        if (next)
            next->prev = prev;
        if (prev)
            prev->next = next;

        next = prev = nullptr;
        delete this;
        //~LinkedListNode<ItemType>();
    }

    ~LinkedListNode()
    {
        if (next)
            delete next;
        if (prev)
            delete prev;
    }
};


template <typename ItemType>
class LinkedList
{
private:
    LinkedListNode<ItemType>* m_pHead;
    LinkedListNode<ItemType>* m_pTail;
    int m_size;

public:

    LinkedList();

    LinkedList<ItemType>& addInTail(const ItemType& Item);
    LinkedList<ItemType>& removeFromHead();
    LinkedList<ItemType>& removeFromTail();

    ItemType& operator[] (const int index);
    const ItemType& operator[] (const int index) const;

    const int size() const {
        return m_size;
    }
    const bool isEmpty() const {
        return m_size == 0;
    }


    ~LinkedList();
    template <typename T>
    friend std::ostream& operator<< (std::ostream& os, const LinkedList<T>& list);
};

template <typename ItemType>
std::ostream& operator<< (std::ostream& os, const LinkedList<ItemType>& list)
{
    for (int i = 0; i < list.m_size; i++)
        os << list[i] << " ";
    os << std::endl;
    return os;
}


template <typename ItemType>
LinkedList<ItemType>::LinkedList()
{
    m_pHead = m_pTail = nullptr;
    m_size = 0;
}

template <typename ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::addInTail(const ItemType& Item)
{
    if (m_size)
        m_pTail = m_pTail->addAfter(Item);
    else
        m_pHead = m_pTail = new LinkedListNode<ItemType>(Item);

    m_size++;

    return *this;
}

template <typename ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::removeFromHead()
{
    switch (m_size)
    {
        case 0: return *this;
        case 1:
            m_pHead->remove();
            m_pHead = m_pTail = nullptr;
            break;
        default:
            LinkedListNode<ItemType>* temp = m_pHead;
            m_pHead = m_pHead->operator[](1);
            temp->remove();
    }

    m_size--;

    return *this;
}

template <typename ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::removeFromTail()
{
    switch (m_size)
    {
        case 0: return *this;
        case 1:
            m_pHead->remove();
            m_pHead = m_pTail = nullptr;
            break;
        default:
            LinkedListNode<ItemType>* temp = m_pTail;
            m_pTail = m_pTail->operator[](-1);
            temp->remove();
    }

    m_size--;

    return *this;
}


template <typename ItemType>
ItemType& LinkedList<ItemType>::operator[] (const int index)
{
    if (index<m_size/2)
        return m_pHead->operator[](index)->data;
    else
        return m_pTail->operator[](index-m_size+1)->data;
}

template <typename ItemType>
const ItemType& LinkedList<ItemType>::operator[] (const int index) const
{
    if (index<m_size / 2)
        return m_pHead->operator[](index)->data;
    else
        return m_pTail->operator[](index - m_size + 1)->data;
}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
    if (m_size)
        delete m_pHead;
}


#endif //TEMPLATETRAINING_LINKEDLIST_H
