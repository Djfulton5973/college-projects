#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

struct DynamicNode{ // node is the same as in the dynamic list code 
  char info;
  DynamicNode *next;
};

class DynamicQueue {
public:
	//---------------------------------------------------------------
	// constructors
	//---------------------------------------------------------------
	DynamicQueue(int size);

	//---------------------------------------------------------------
	// methods (inserts and deletes)
	//---------------------------------------------------------------
	bool empty();
	// void insert(char x);
    DynamicNode* dynamicInsert(char n);
	int remove();
    void printQueue();

private:
	DynamicNode* front;
	DynamicNode* rear;
    int QUEUESIZE;
    int count = 0;
};
#endif

