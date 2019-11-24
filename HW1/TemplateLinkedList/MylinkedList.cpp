#include <iostream>
#include "MyLinkedList.h"
using namespace std;

template<class T>
void MyLinkedList<T>::add( T value){
    if (front == nullptr) {
        // adding to an empty list
        front = new Node<T>(value);
    }
    else {
        // adding to the end of an existing list
        Node<T> *current = front;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node<T>(value);
    }
}
template<class T>
void MyLinkedList<T>::add(int index, T value) {
    if (index == 0) {
        // adding to an empty list
        front = new Node<T>(value, front);
    }
    else {
        // inserting into an existing list
        Node<T> *current = front;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        current->next = new Node<T>(value,current->next);
    }
}
template<class T>
void MyLinkedList<T>::addSorted(T value){
    Node<T> *current = front;
    while (current->next->data < value) {
        current = current->next;
    }
    current->next = new Node<T>(value,current->next);
}

template<class T>
T  MyLinkedList<T>::get(int index) {
    Node<T> *current = front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}
template<class T>
T MyLinkedList<T>::remove() {
    if (front == nullptr) {
        throw NoSuchElementException();
    }
    else {
        T result = front->data;
        Node<T> *tmp = front;
        front = front->next;
        delete tmp;
        return result;
    }
}
template<class T>
void MyLinkedList<T>::remove(int index) {
    if (index == 0) {
        // special case: removing first element
        Node<T>* tmp = front;
        front = front->next;
        delete tmp;
    }
    else {
        // removing from elsewhere in the list
        Node<T> *current = front;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<T> *tmp = current->next;
        current->next = current->next->next;
        delete tmp;
    }
}
template<class T>
void MyLinkedList<T>::print(){
    Node<T> * current = front;
    while (current != nullptr){
        cout << current->data << " " ;
        current = current->next;
    }
    cout << endl;
}

