#ifndef AVL_TREE_H
#define AVL_TREE_H
#include<vector>

using namespace std;

struct itemTreeAvlInteger{
 int value; int next;int last;
 int parent; int left; int right; unsigned char balance; // avl tree
};

class avl_tree
{
private:
 vector<itemTreeAvlInteger> tree;

	int lFree;
	int head;
	void createMemory(int size);
public:
	avl_tree();
	~avl_tree();

	
}
#endif