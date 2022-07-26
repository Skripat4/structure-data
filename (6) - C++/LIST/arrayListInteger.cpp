#pragma once
#include "arrayListInteger.h"

arrayListInteger::arrayListInteger(){
	
}
arrayListInteger::~arrayListInteger(){

}

void arrayListInteger::createMemory(int size){
	for (int i = 0; i < size; i++){
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

void arrayListInteger::createList(int *head, int *tail,int value){
	
	*head = lFree;
	lFree = list[lFree].next;
	*tail = *head;
	list[*head].next = 0;
	list[*head].value = value;
}

void arrayListInteger::deleteList(int *head, int *tail){
	list[*tail].next = lFree;
	lFree = *head;
	*head = 0;
	*tail = 0;
}

void arrayListInteger::addToHead(int *head, int value){
	int temp = list[lFree].next;
	list[lFree].next = *head;
	*head = lFree;
	lFree = temp;
	list[*head].value = value;
}

void arrayListInteger::addToAfter(int *tail,int index, int value){
	int temp = list[lFree].next;
	list[lFree].next = list[index].next;
	list[index].next = lFree;
	list[lFree].value = value;
	if (*tail == index){ *tail = lFree; }
	lFree = temp;
}

void arrayListInteger::deleteAfter(int *tail,int index){
	int temp = list[index].next;
	if (temp == *tail){ *tail = index; }
	list[index].next = list[temp].next;
	list[temp].next = lFree;
	lFree = temp;

}

void arrayListInteger::deleteTail(int *head, int *tail){
	if (*head == *tail){ deleteList(head,tail); }
	else{
		int j = *head;
		while (list[j].next != *tail ){ j = list[j].next; }
		list[j].next = 0;
		list[(*tail)].next = lFree;
		lFree = *tail;
		*tail = j;
	}
}