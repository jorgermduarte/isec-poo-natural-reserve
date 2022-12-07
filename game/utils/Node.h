//
// Created by duarte on 06-12-2022.
//
#ifndef POO_NATURAL_RESERVE_NODE_H
#define POO_NATURAL_RESERVE_NODE_H

template<class T> class Node {
public:
    T* value;
    Node<T> *next;
    Node<T> *prev;
    Node();
    Node(T *value);
    Node<T>* getTail();
    Node<T>* getHead();
};


#endif //POO_NATURAL_RESERVE_NODE_H
