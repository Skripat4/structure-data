#pragma pack(push,1)
struct itemListInteger{
	int value; int next;
};
#pragma pack(pop)

struct itemListInteger *m;
int Lfree;

void  createMemory(struct itemListInteger **memory,int sizeList)
{
	struct itemListInteger *tmpPtr = *memory;
        //
	tmpPtr = (struct itemListInteger *) malloc(sizeList*sizeof(struct itemListInteger));
	if (tmpPtr){
		//create list free memory Lfree - head list free memory
		for (int i = 1; i < sizeList - 1; i++){
			tmpPtr[i].next = i + 1;
			tmpPtr[i].value = 0;
		}
		tmpPtr[0].next = 0;
		tmpPtr[0].value = 0;
		tmpPtr[sizeList - 1].next = 0;
		tmpPtr[sizeList - 1].value = 0;
	}
	*memory = tmpPtr;
	Lfree = 1;
}

void freeMemory(struct itemListInteger **memory){
	if (*memory){
		free(*memory);
		*memory = NULL;
	}
}

void createList(struct itemListInteger **memory,int *head, int *tail, int value)
{
	struct itemListInteger *list = *memory;
	(*head) = Lfree;
	(*tail) = (*head);
	Lfree = list[Lfree].next;
	list[(*tail)].next = 0;
	list[(*head)].value = value;
	*memory = list;
}

void deleteList(struct itemListInteger **memory, int *head, int *tail)
{
	struct itemListInteger *list = *memory;
	list[(*tail)].next = Lfree;
	Lfree = (*head);
	(*head) = 0;
	(*tail) = 0;
	*memory = list;
}

void addToTail(struct itemListInteger **memory, int *tail, int value){
	struct itemListInteger *list = *memory;
	list[(*tail)].next = Lfree;
	(*tail) = Lfree;
	Lfree = list[Lfree].next;
	list[(*tail)].next = 0;
	list[(*tail)].value = value;
	*memory = list;
}
