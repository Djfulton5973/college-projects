#include "DynamicQueue.h"
#include <iostream>
#include <stdlib.h>

//-------------------------------------------------------------------------------
// constructors
//-------------------------------------------------------------------------------
/********************************************************************************
default constructor
********************************************************************************/
DynamicQueue::DynamicQueue(int size) {
    QUEUESIZE = size;
	front = nullptr;
	rear = nullptr;
}

//---------------------------------------------------------------
// methods (inserts and deletes)
//---------------------------------------------------------------
bool DynamicQueue::empty() {
	return (front == nullptr);
}

/* void DynamicQueue::insert(char x) {
	DynamicNode* p = new DynamicNode;
	p->info = x;
	p->next = nullptr;

	if (empty()) {
		front = p;
	}
	else {
		rear->next = p;
	}

	rear = p;
} */

DynamicNode* DynamicQueue::dynamicInsert(char n) {
    // the bool used to ensure to not make more nodes
    bool exists = false;
    DynamicNode *k = new DynamicNode;
    k->info = n;
    k->next = nullptr;
    // the z pointer is for traversing the list once
    DynamicNode *z;
    // the v pointer is the previous node z was
    DynamicNode *v;

    // it checks if it does exist
    for (z = front; z != nullptr; z = z->next) {
        if (z->info == n) {
            exists = true;
            if (front->info == n) {
                // when the value is at the first node
                std::cout << k->info << " to rear. ";
                remove();
                count++;
                rear->next = k;
                rear = k;
                printQueue();
                return k;
            }
            // when the value is already in the rear
            else if (z == rear) {
                std::cout << " Key " << k->info << " is already in rear. ";
                printQueue();
            }
            // when the value exists in the queue already
            else {
                std::cout << k->info << " to rear. ";
                v->next = z->next;
                delete z;
                rear->next = k;
                rear = k;
                printQueue();
                return k;
            }
        }
        // updates v to become the previous node
        v = z;
    }

    // if it does not exist
    if (!exists) {
        // checks if the count exceeds the queue size
        if (count < QUEUESIZE) {
            count++;
            std::cout << k->info << " in rear. ";
            if (empty()) {
                front = k;
            }
            else {
                rear->next = k;
            }

            rear = k;
            printQueue();
            return k;
        }
        // reaches the statement once the count exceeds the queue size
        else {
            std::cout << k->info << " in rear. ";
            remove();
            count++;
            if (empty()) {
                front = k;
            }
            else {
                rear->next = k;
            }

            rear = k;
            printQueue();
            return k;
        }
    }

}

int DynamicQueue::remove() {
	if (empty()) {
		std::cout << "queue underflow";
		exit(1);
	}
    // decrements the count to make it possible to make the queue empty
    count--;
	DynamicNode* p = front;
	char temp = p->info;
	front = p->next;
	delete p;
	if (front == nullptr)
		rear = nullptr;

	return temp;
}
void DynamicQueue::printQueue() {
    DynamicNode *p;
    std::cout << "Queue: ";
    for (p = front; p != nullptr; p = p->next) {
        std::cout << p->info;
        if (p->next != nullptr)
            std::cout << "->";
    }
    // only when the queue is empty
    if (empty()) {
        std::cout << "Empty";
    }
    std::cout << std::endl;
}