//
// Created by duarte on 06-12-2022.
//
#include "Node.h"
#include "../models/animal/Animal.h"
#include "../models/food/Food.h"


template <typename T> Node<T>::Node(T *value) {
    this->value = value;
    this->prev = NULL;
    this->next = NULL;
}

template <typename T> Node<T>* Node<T>::getTail() {
    Node<T> *current = this;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

template <typename T> Node<T>* Node<T>::getHead() {
    Node<T> *current = this;
    while (current->prev != NULL) {
        current = current->prev;
    }
    return current;
}

template <typename T> Node<T>::Node() {
    this->value = NULL;
    this->prev = NULL;
    this->next = NULL;
}

template class Node<Animal>;
template class Node<Food>;