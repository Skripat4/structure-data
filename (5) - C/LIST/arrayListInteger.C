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
		//прошиваем память (cоздаем список свободной памяти) Lfree - голова списка свободной памяти
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