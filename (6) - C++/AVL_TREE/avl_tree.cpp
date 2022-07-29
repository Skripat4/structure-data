#include "avl_tree.h"

avl_tree::avl_tree(){

}
avl_tree::~avl_tree(){

}

void avl_tree::createMemory(int size){
for (int i = 0; i < size; i++){
		itemTreeAvlInteger a;
		a.value = 0;
		a.right = 0 ;
		a.left = 0;
		a.balance = 1;
		a.next = i + 1;
		a.last = i - 1;
		tree.push_back(a);
		
	}
	tree[0].next = 0;
	tree[0].last = 0;
	tree[size - 1].value = 0;
	tree[size - 1].next = 0;
	tree[size - 1].right = 0;
	tree[size - 1].left = 0;
	tree[size - 1].balance = 1;
	lFree = 1;
	lastFree = 0;
}

void avl_tree::addToFree(int index)
{
	tree[tree[index].last].next = tree[index].next;
	tree[tree[index].next].last = tree[index].last;
	tree[index].next = lFree;
	tree[lFree].last = index;
	tree[index].last = 0;
	lFree = index;
}

int *avl_tree::getHead(){
	return &head;
}
vector<itemTreeAvlInteger> *avl_tree::getMemory(){
	return &tree;
}