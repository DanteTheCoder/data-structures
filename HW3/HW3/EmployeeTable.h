#ifndef EMPLOYEETABLE_H
#define EMPLOYEETABLE_H

#include <vector>
#include "Employee.h"



class Node {
public:
    Employee element;
    Node *prev;
    Node *next;

    Node();
    Node(Employee element, Node *prev, Node *next);

    };



/**************************************** LINKED LIST ( DOUBLY ) **************************************************************/


class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList &obj);

    ~LinkedList();

    Node *getFirstNode() const;
    int getNumberOfNodes();
    bool isEmpty();

    void insertAtTheFront(const Employee &data);
    void removeNode(Node *node);
    void removeAllNodes();

    Node *findNode(Employee &data);

   LinkedList &operator=(const LinkedList &rhs);

  private:
    Node *head;
    Node *tail;
};




/* ***********************************TABLE START **************************************************/



class EmployeeTable {

private:
// TODO:

    int bucketno;   //number of buckets are given as input
    std::vector<LinkedList> theLists;// the array of  linked lists consisting of employees

// ... members, methods

public:
// Constructors & Destructor, be careful about memory leaks.
    EmployeeTable(); // Default table size is 151 buckets.
    EmployeeTable(int numberOfBuckets); // numberOfBuckets is a prime number.
    EmployeeTable(const EmployeeTable& empTable);
    ~EmployeeTable();
    EmployeeTable& operator=(const EmployeeTable& rhs);

// Hash an employee to a non-negative integer ( return hash value, not
// bucket number). Use hashValue(mod numberOfBuckets) as bucket number.
// Return -1 on invalid parameters.
    int hashEmployee(string ssn);

// Put an employee to the hash table.
// Do nothing on invalid parameters.
    void addEntry(Employee& employee);

// Remove the entry from the hash table.
// Do nothing on invalid parameters.
    void removeEntry(Employee& employee);

// Get the total number of employees in the given bucket.
// Return -1 on invalid bucket number.
    int getNumberOfEmployeeInBucket(int bucket);

// Find employee of the given ssn.
// Important: To add an extra flavor to your homework, your code
// will be evaluated by how much time it takes to access an employee
// on the average. You will get a small portion of your grade
// depending on the average access time of your code.
// For invalid cases, throw ItemNotFoundException.
    Employee findEmployee(string ssn);
};


#endif // EMPLOYEETABLE_H
