#ifndef AVL_TREE_H
#define AVL_TREE_H
#include<vector>

using namespace std;

struct itemTreeAvlInteger{
 int value; int next;int last;
 int parent; int left; int right; unsigned char balance; // avl tree
};

#define balanced 2

class avl_tree
{
private:
 vector<itemTreeAvlInteger> tree;

	int lFree;
	int lastFree;
	int head;
	void createMemory(int size);
	void addToFree(int index);
public:
	avl_tree();
	~avl_tree();
	void addElement(int *head,int value);
	int *getHead();
	vector<itemTreeAvlInteger> *getMemory();
}
#endif