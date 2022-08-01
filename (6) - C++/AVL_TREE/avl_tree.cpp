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

int avl_tree::findElement(int *head, int value){
	int i = *head;
	while (i != 0){
		if (tree[i].value == value){
			return i;
			
		}
		if (tree[i].value < value){
			i = tree[i].right;
		}
		else{ i = tree[i].left; }
	}
	return i;
}

void avl_tree::addElement(int *head, int value)
{
	int n;
	int i = *head;
	int j = 0;
	while (i != 0){
		j = i;
		if (tree[i].value < value){
			i = tree[i].right;
		}
		else{
			i = tree[i].left;
		}

	}
	if (j == 0){ *head = lFree; }
	      else {
			if (tree[j].value < value)
				{ tree[j].right = lFree; }
				else    { tree[j].left = lFree; }		
		   }
	int temp = tree[lFree].next;
	tree[lFree].value = value;
	tree[lFree].parent = j;
	tree[lFree].right = 0;
	tree[lFree].left = 0;
	tree[lFree].balance = balanced;
	tree[lFree].last = lastFree;
	tree[lastFree].next = lFree;
	lastFree = lFree;
	i = lFree;
	
	tree[lFree].next = 0;
	lFree = temp;
	tree[lFree].last = 0;

//correct balance
	int q = 1;
	while (j != 0 && q == 1){
		if (tree[j].right == i)
				{tree[j].balance++;}
			else{    tree[j].balance--;}

		if (tree[j].balance == balanced){ q = 0; }
		if (tree[j].balance == balanced+2 || tree[j].balance==balanced-2)
								{ q = 2; }
							else
								{
								i = j;
								j = tree[j].parent;
								}
	}//while 

	//balanced
	if (q == 0){}
	else{
		if (tree[j].balance == balanced+2 && tree[i].balance == balanced+1){
			int mm = tree[j].parent;
			 n = tree[i].left;
			tree[n].parent = j;
			if (mm == 0){
				*head = i;
			}
			else{
				if (tree[mm].left == j){ tree[mm].left = i; }
				else{ tree[mm].right = i; }
			}
			tree[i].parent = mm;
			tree[j].parent = i;
			tree[j].right = n;
			tree[i].left = j;
			tree[i].balance = balanced;
			tree[j].balance = balanced;
		}
		if (tree[j].balance == balanced - 2 & tree[i].balance == balanced - 1){
			int mm = tree[j].parent;
			 n = tree[i].right;//!
			tree[n].parent = j;
			if (mm == 0){
				*head = i;
			}
			else{
				if (tree[mm].left == j){ tree[mm].left = i; }
				else{ tree[mm].right = i; }
			}
			tree[i].parent = mm;
			tree[j].parent = i;
			tree[i].right = j;//!
			tree[j].left = n;//!
			tree[i].balance = balanced;
			tree[j].balance = balanced;
		}
		if (tree[j].balance == balanced + 2 && tree[i].balance == balanced - 1){
			int mm = tree[j].parent;
			n = tree[tree[i].left].left;
			q = tree[tree[i].left].right;
			if (mm == 0){ *head = tree[i].left; }
			else
			{
				if (tree[mm].left == j){ tree[mm].left = tree[i].left; }
									else{tree[mm].right = tree[i].left;}
			
			}
			tree[tree[i].left].parent = mm;
			mm = tree[i].left;
			tree[j].parent = mm;
			tree[i].parent = mm;
			tree[mm].right = i;
			tree[mm].left = j;
			tree[j].right = n;
			tree[i].left = q;
			tree[n].parent = j;
			tree[q].parent = i;
			tree[mm].balance = balanced;
			tree[i].balance = balanced;
			tree[j].balance = balanced;

		}
}//else q==0

}


int *avl_tree::getHead(){
	return &head;
}
vector<itemTreeAvlInteger> *avl_tree::getMemory(){
	return &tree;
}