#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include <iostream>

struct DynamicNode{
  int info;
  DynamicNode *next;
};

class DynamicList{
public:
	// constructors
	DynamicList(){	head = nullptr;} // default constructor

	// methods (inserts, deletes, print, search)
	void insertFirst(int x);
	void insertAfter(DynamicNode *p, int x);
	DynamicNode* search(int x);
	int deleteFirst();
	int deleteAfter(DynamicNode *p);
    DynamicNode* getNth (int pos);
    DynamicNode* findOrInsert (int x);
    bool isEmpty();
	void print();
	
private:
	DynamicNode* head;
};
#endif //DYNAMICLIST_H