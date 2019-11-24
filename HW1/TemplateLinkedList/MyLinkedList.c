#ifndef _LList
#define _LList
#include "Node.h"
#include "NoSuchElementException.h"
template <T>
class LinkedList{
public:
    LinkedIntList() {
        front = nullptr;
    }
    void add (int value);
    void add (int index, int value);
    void addSorted(int value);
    int get (int index);
    int remove(); // throws NoSuchElementException;
    void remove(int index);
    void print();
private:
    ListNode *front;
};
#endif

