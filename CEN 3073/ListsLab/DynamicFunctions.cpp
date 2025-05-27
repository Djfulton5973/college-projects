//
// Created by Darren Fulton on 2/16/2023.
//
#include "DynamicList.h"

void DynamicList::insertFirst(int x) {
    DynamicNode* q = new DynamicNode;
    q->info = x;
    q->next = head;
    head = q;
}

void DynamicList::insertAfter(DynamicNode *p, int x) {
    if (p == nullptr) {
        std::cout << "void insertion\n";
        exit(1);
    }
    DynamicNode* q = new DynamicNode;
    q->info = x;
    q->next = p->next;
    p->next = q;
}

DynamicNode* DynamicList::search(int x) {
    DynamicNode* p = head;
    for (p; p != nullptr; p = p->next)
        if (p->info == x)
            return p;
    return nullptr; // x is not on the list
}

int DynamicList::deleteFirst() {
    if (isEmpty()) {
        std::cout << "void deletion";
        exit(1);
    }
    int temp = head->info; // the info of the head
    if (head->next != nullptr) { // more than one node in list)
        DynamicNode* newHead = head->next; // move to next of head
        delete head;
        head = newHead;
    }
    else { // one node in the list -> make list empty
        delete head;
        head = nullptr;
    }
    return temp;
}

int DynamicList::deleteAfter(DynamicNode *p) {
    if ((p == nullptr) || p->next == nullptr) {
        std::cout << "void deletion";
        exit(1);
    }
    DynamicNode *q = p->next; // just a tempt to the next of p
    int temp = q->info; // the info so that we can return it
    p->next = q->next; // update the next's
    delete q; // delete the actual node in memory
    return temp; // return the info on the node you deleted
}

/**
 * Returns the N-th node in the list
 * remember there is no index in the list, so it needs to count to the N-th
 * If the list does not contain as many nodes, it returns nullptr
 */

DynamicNode* DynamicList::getNth (int pos) {
    // checks if the list is empty
    if (head == nullptr) {
        return nullptr;
    }
    // create a temporary node to traverse the list
    DynamicNode *p;
    int index = -1;
    for (p = head; p != nullptr ; p = p->next) {
        index++;
        // if the index is at the wanted position on the list
        if (index == pos) {
            // returns the address of the node
            return p;
        }
    }
    // if the node of the wanted position does not exist; the default value
    return nullptr;

}

DynamicNode* DynamicList::findOrInsert (int x) {
    // checks if the list is empty
    if (head == nullptr) {
        DynamicNode *g = new DynamicNode;
        g->info = x;
        g->next = nullptr;
        head = g;
        return g;
    }
    // create a temporary node to traverse the list
    DynamicNode *p;
    for (p = head; p->next != nullptr ; p = p->next) {
        // returns the address of the node that has the same value as x
        if (x == p->info)
            return p;
    }
    /*
     * Checks if there is only a single node in the list
     * and if its info matches x.
     * It does this without traversing the list again.
     */
    if (p->next == nullptr && p->info == x) {
        return p;
    }
    else { // creates a new node if x is not found in any of the nodes
        DynamicNode *z = new DynamicNode;
        z->info = x;
        z->next = p->next;
        p->next = z;
        return z;
    }

}

bool DynamicList::isEmpty() {

    if (head == nullptr)
        return true;
    else
        return false;
}

void DynamicList::print() {
    if (head == nullptr) {
        std::cout << "Empty list\n";
    }
    DynamicNode* p = head;
    while (p != nullptr) {
        std::cout << p->info;
        if (p->next != nullptr) {
            std::cout << "->";
        }
        else {
            std::cout << "\n";
        }
        p = p->next;
    }
}
