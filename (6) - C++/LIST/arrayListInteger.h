#include<vector>

using namespace std;

struct itemListInteger{
 int value; int next;
};

class arrayListInteger
{
private:
 vector<itemListInteger> list;

	int lFree;
	int head;
	int tail;
	void createMemory(int size);
public:
	arrayListInteger();
	~arrayListInteger();

	void showList(int *head);
	void createList(int *head, int *tail,int value);
	void deleteList(int *head, int *tail);
	void addToTail(int *tail, int value);
	void addToHead(int *head, int value);
	void addToAfter(int *tail, int index,int value);
	void deleteAfter(int *tail, int index);
	void deleteTail(int *head, int *tail);
	void deleteHead(int *head);
}