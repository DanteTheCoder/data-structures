#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"

template <class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList &obj);

    ~LinkedList();

    Node<T> *getFirstNode() const;
    int getNumberOfNodes();
    bool isEmpty();

    void insertAtTheFront(const T &data);
    void insertAtTheEnd(const T &data);
    void insertAfterGivenNode(const T &data, Node<T> *prev);

    void removeNode(Node<T> *node);
    void removeAllNodes();

    Node<T> *findNode(const T &data);

    void swapNodes(Node<T> *node1, Node<T> *node2);

    void printAllNodes();

    LinkedList &operator=(const LinkedList &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    Node<T> *tail;
};

template<class T>
LinkedList<T>::LinkedList() {
    /* TODO */

    head = NULL;
    tail = NULL;

}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj) {
    /* TODO */

    head=NULL;
    tail=NULL;

    *this=obj;


}

template<class T>
LinkedList<T>::~LinkedList() {
    /* TODO */

    this->removeAllNodes();
}

template<class T>
Node<T> * LinkedList<T>::getFirstNode() const {
    /* TODO */

    return head;
}

template<class T>
int LinkedList<T>::getNumberOfNodes() {
    /* TODO */
    int i=0;
    Node <T> * tmp = head;

    while(tmp != NULL){

        tmp = tmp->next;
        i++;
    }

    return i;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    /* TODO */
    if(head == NULL){

        return true;

    }

    return false;
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data) {
    /* TODO */
    if(head == NULL){ //check if list is empty

        head = new Node <T> (data,NULL,NULL);
        tail=head;
        return;
    }

    Node <T> * new_node = new Node <T> (data,NULL,head);
    head->prev = new_node;
    head=new_node;

}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data) {
    /* TODO */

    if(head == NULL){ // check if list is empty

        head = new Node <T> (data,NULL,NULL);
        tail = head;
        return;
    }

    Node <T> * new_node = new Node <T> (data,tail,NULL);
    tail->next=new_node;
    tail = new_node;
}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev) {
    /* TODO */

    if(findNode(prev->element) == NULL){

        return;
    }

    if(prev == tail){

        insertAtTheEnd(data);
        return;
    }

    Node <T> *new_node = new Node <T> (data,prev,prev->next);
    prev->next = new_node;
    new_node ->next->prev = new_node;
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node) {
    /* TODO */

    Node <T> *tmp = head;

    if(findNode(node->element) == NULL){

        return;
    }

    if(head == tail && node == head){ //only 1 element case
        head = NULL;
        tail = NULL;
        delete node;
        return;
    }

    if(node == head){

        head=head->next;
        head->prev = NULL;
        delete tmp;

    }

    else if(node == tail){

        tmp=tail;
        tail=tail->prev;
        tail->next = NULL;
        delete tmp;
    }

    else {

        tmp = node->prev;
        tmp->next = tmp->next->next;
        tmp->next->prev = tmp;
        delete node;

    }
}

template<class T>
void LinkedList<T>::removeAllNodes() {
    /* TODO */
    Node <T> * tmp ;

    if(head == NULL){

        return;
    }

    tmp=head;

    while(head != NULL){

        head = head->next;
        delete tmp;
        tmp=head;

    }
    tail=NULL;
}



template<class T>
Node<T> * LinkedList<T>::findNode(const T &data) {
    /* TODO */

    Node <T> * tmp = head;

    while(tmp != NULL){


        if(tmp->element == data){

            return tmp;

        }

        tmp = tmp->next;
    }

    if(tmp == NULL){

        return NULL;
    }
}

template<class T>
void LinkedList<T>::swapNodes(Node<T> *node1, Node<T> *node2) {
    /* TODO */

   Node <T> * tmp = head , *tmp1 = head ;

    while(tmp != NULL && tmp1 != NULL){

        if(tmp != node1){
            tmp=tmp->next;
        }

        if(tmp1 != node2){
            tmp1=tmp1->next;
        }

        if(tmp == node1 && tmp1 == node2){
            break;
        }
    }


    if(tmp == NULL || tmp1 == NULL){
        return;
    }


    if(node1 == node2) { //only one element or empty list
        return;
    }

     if(node1 == head){

        tmp=node1->next;

        if(node2==tail){

            if(node1->next == node2){

                node2->prev=NULL;
                node1->prev=node2;
                node2->next=node1;
                node1->next=NULL;
                node2=head;
                }

            else{
            node2->prev->next=node1;
            node1->next->prev=node2;
            node2->next=node1->next;
            node1->prev=node2->prev;
            node2->prev=NULL;
            node1->next=NULL;
            head=node2;
            tail=node1;
            }

        }

        else{

            if(node1->next == node2){

                    tmp = node2->next;
                    node1->next = tmp;
                    node1->prev=node2;
                    node2->next=node1;
                    node2->prev=NULL;
                    tmp->prev=node1;
                    head=node2;
                }


            else{

            node1->next->prev=node2;
            node2->prev->next=node1;
            node1->next=node2->next;
            node1->prev=node2->prev;
            node2->prev=NULL;
            node2->next->prev=node1;
            node2->next=tmp;
            head=node2;
            }

        }

    }

    else if(node2 == head){

        tmp=node2->next;

        if(node1==tail){

            node1->prev->next=node2;
            node2->next->prev=node1;
            node1->next=node2->next;
            node2->prev=node1->prev;
            node1->prev=NULL;
            node2->next=NULL;
            head=node1;
            tail=node2;

        }

        else{

            node2->next->prev=node1;
            node1->prev->next=node2;
            node2->next=node1->next;
            node2->prev=node1->prev;
            node1->prev=NULL;
            node1->next->prev=node1;
            node1->next=tmp;
            head=node1;

        }

    }

    else if(node1 == tail && node2 != head){

        tmp = node2->prev;

        node2->next->prev = node1;
        node1->prev->next=node2;
        node2->prev=node1->prev;
        node1->prev=tmp;
        tmp->next = node1;
        node2->next=NULL;

    }

    else if(node2 == tail && node1 != head){

        tmp = node1->prev;
        tmp1 = node1->next;

        node1->next->prev = node2;
        node2->prev->next=node1;
        node1->prev=node2->prev;
        node2->prev=tmp;
        node2->next=tmp1;
        tmp->next = node2;
        node1->next=NULL;

    }

    else{

        if(node1->next == node2) {

            tmp = node1->prev;
            tmp1 = node2->next;

            tmp1->prev=node1;
            tmp->next=node2;
            node2->prev=tmp;
            node2->next=node1;
            node1->prev=node2;
            node1->next=tmp1;

        }

        else if(node2->next == node1){

            tmp = node2->prev;
            tmp1 = node1->next;

            tmp1->prev=node2;
            tmp->next=node1;
            node1->prev=tmp;
            node1->next=node2;
            node2->prev=node1;
            node2->next=tmp1;
        }


        else {
        tmp = node1->next;
        tmp1 = node1->prev;

        tmp->prev=node2;
        node2->next->prev=node1;
        tmp1->next=node2;
        node2->prev->next=node1;
        node1->next=node2->next;
        node2->next=tmp;
        node1->prev=node2->prev;
        node2->prev= tmp1;
        }

    }
}

template<class T>
void LinkedList<T>::printAllNodes() {
    /* TODO */

    Node <T> *tmp = head;

    while(tmp != NULL){

       std::cout << tmp->element << std::endl ;
       tmp=tmp->next;

    }
}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs) {
    /* TODO */

    Node <T> *tmp = rhs.getFirstNode();


    if(this != &rhs){

        if(head != NULL){ // if not an empty list , empty the list

            this->removeAllNodes();

        }

        while(tmp != NULL){

            this->insertAtTheEnd(tmp->element);
            tmp=tmp->next;

        }

    }

    return *this;
}


#endif //LINKED_LIST_HPP
