#include "EmployeeTable.h"
#include "ItemNotFoundException.h"


Node::Node() {
    this->prev = NULL;
    this->next = NULL;
}

Node::Node(Employee element, Node *prev, Node *next) {
    this->element.setCity(element.getCity());
    this->element.setExperience(element.getExperience());
    this->element.setName(element.getName());
    this->element.setSsn(element.getSsn());
    this->prev = prev;
    this->next = next;
}


LinkedList::LinkedList() {
    /* TODO */

    head = NULL;
    tail = NULL;

}


LinkedList::LinkedList(const LinkedList &obj) {
    /* TODO */

    head=NULL;
    tail=NULL;

    *this=obj;


}

LinkedList::~LinkedList() {
    /* TODO */

    this->removeAllNodes();
}


Node * LinkedList::getFirstNode() const {
    /* TODO */

    return head;
}


int LinkedList::getNumberOfNodes() {
    /* TODO */
    int i=0;
    Node  * tmp = head;

    while(tmp != NULL){

        tmp = tmp->next;
        i++;
    }

    return i;
}


bool LinkedList::isEmpty() {
    /* TODO */
    if(head == NULL){

        return true;

    }

    return false;
}


void LinkedList::insertAtTheFront(const Employee &data) {
    /* TODO */
    if(head == NULL){ //check if list is empty

        head = new Node (data,NULL,NULL);
        tail=head;
        return;
    }

    Node  * new_node = new Node  (data,NULL,head);
    head->prev = new_node;
    head=new_node;

}


void LinkedList::removeNode(Node *node) {
    /* TODO */

    Node  *tmp = head;

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


void LinkedList::removeAllNodes() {
    /* TODO */
    Node * tmp ;

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



Node * LinkedList::findNode(Employee &data) {
    /* TODO */

    Node  * tmp = head;

    while(tmp != NULL){


        if(tmp->element.getSsn().compare(data.getSsn()) == 0){

            return tmp;

        }

        tmp = tmp->next;
    }

    if(tmp == NULL){

        return NULL;
    }
}


LinkedList & LinkedList::operator=(const LinkedList &rhs) {
    /* TODO */

    Node  *tmp = rhs.tail;


    if(this != &rhs){

        if(head != NULL){ // if not an empty list , empty the list

            this->removeAllNodes();

        }

        while(tmp != NULL){

            this->insertAtTheFront(tmp->element);
            tmp=tmp->prev;

        }

    }

    return *this;
}





/********************************TABLE START********************************************/




EmployeeTable::EmployeeTable() {
// TODO:

    bucketno = 151;
    theLists.resize(bucketno);
    std::cout << "default table constructed"<<std::endl;

}

EmployeeTable::EmployeeTable(int numberOfBuckets) {
// TODO:

    bucketno = numberOfBuckets;
   theLists.resize(bucketno);
    std::cout << " table constructed with bucket number : "<<bucketno <<  std::endl;

}

EmployeeTable::EmployeeTable(const EmployeeTable& empTable) {
// TODO:

    *this = empTable ;

}

EmployeeTable& EmployeeTable:: operator=(const EmployeeTable& rhs) {
// TODO:

    if(this != &rhs){

    bucketno = rhs.bucketno;

    for(int i = 0 ; i < bucketno ; i++){

            theLists[i] = rhs.theLists[i];          // Since = assignment for linked lists is already implemented

        }
    }

    std::cout << "= op called"<< std::endl;

}

EmployeeTable::~EmployeeTable() {
// TODO:

    for(int i=0 ; i< bucketno ; i++){

            theLists[i].removeAllNodes();

    }

 theLists.clear();
}

int EmployeeTable::hashEmployee(string ssn) {
// TODO:

    if(ssn.length() != 11) return -1;

    int hashcode = 0;

    for(int i=0 ; i<ssn.length() ; i++ )
        hashcode = 53*hashcode + ssn[i];

    hashcode = hashcode % bucketno; //i.e. tablesize
    if(hashcode<0)
            hashcode += bucketno;

    std::cout << this->bucketno << " employee with ssn: " << ssn << " is hashed with hashcode : " << hashcode << std::endl;

    return hashcode;
}

void EmployeeTable::addEntry(Employee& employee) {
// TODO:

    LinkedList &thatlist = theLists[ hashEmployee(employee.getSsn())];

    Node* ep = thatlist.findNode(employee);

    if(ep == NULL)
            thatlist.insertAtTheFront(employee);

}

void EmployeeTable::removeEntry(Employee& employee) {
// TODO:

    LinkedList &thatlist =  theLists[hashEmployee(employee.getSsn())];
    thatlist.removeNode(thatlist.findNode(employee));

}

int EmployeeTable::getNumberOfEmployeeInBucket(int bucket) {
// TODO:

    return theLists[bucket].getNumberOfNodes();

}

Employee EmployeeTable::findEmployee(string ssn) {
// TODO:


    Node* ep;
    Employee emp;
    emp.setSsn(ssn);

    ep = theLists[hashEmployee(ssn)].findNode(emp);

    if(ep == NULL)
        throw ItemNotFoundException();
    else
        return ep->element;

}


