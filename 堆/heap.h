#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HPDataType;

typedef struct Heap 
{ 
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
void ADjustdown(HPDataType* a, int n, int root);
void ADjustup(HPDataType* a, size_t root);
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp); 
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp,int k);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
void HeapTopk(HPDataType* a, int k, int n);
void HeapSort(int* a, int n);

void TestHeap();