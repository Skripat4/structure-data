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
}