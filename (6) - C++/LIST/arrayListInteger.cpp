#pragma once
#include "arrayListInteger.h"

arrayListInteger::arrayListInteger(){
	
}
arrayListInteger::~arrayListInteger(){

}

void arrayListInteger::createMemory(int size){
	for (int i = 0; i < size-1; i++){
		itemListInteger a;
		a.value = 0;
		a.next = i + 1;
		list.push_back(a);
	}
	list[0].next = 0;
	list[size - 1].value = 0;
	list[size - 1].next = 0;
	lFree = 1;
}