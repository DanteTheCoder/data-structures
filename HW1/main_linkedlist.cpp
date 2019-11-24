#include <iostream>

#include "LinkedList.hpp"


int main() {
    LinkedList<int> llist;
    LinkedList<int> alist;




    if(llist.isEmpty() == true){
        std::cout << "empty" << std::endl;
    }

    llist.printAllNodes();



    llist.insertAtTheEnd(2);



    llist.insertAtTheEnd(4);

    LinkedList<int> clist = llist;

    clist.printAllNodes();
    std::cout << std::endl;

    llist.insertAtTheEnd(6);

    llist.insertAtTheFront(1);

    alist=llist;

    alist.printAllNodes();
    std::cout << std::endl;

    llist.insertAfterGivenNode(3,llist.findNode(2));

    llist.printAllNodes();
    std::cout<<std::endl;

    llist.swapNodes(llist.findNode(1),llist.findNode(2));

    llist.printAllNodes();
    std::cout<<std::endl;

    std::cout<<llist.getFirstNode()->element<<std::endl;

    std::cout<<llist.getNumberOfNodes()<<std::endl;

    llist.removeNode(llist.findNode(4));

    llist.removeAllNodes();

    llist.printAllNodes();
    std::cout<<llist.getNumberOfNodes()<<std::endl;

    return 0;
}
