#include"heap.h"

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	int i=n-1;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_capacity = n;
	hp->_size = n;
	i = (i - 1)/2;
	for (; i >= 0; --i)
	{
		ADjustdown(a, hp->_size, i);
	}
	for (i = 0; i < n; ++i)
	{
		hp->_a[i] = a[i];
	}
}
void ADjustdown(HPDataType* a,int n,int root)
{
	int i;
	int temp;
	i = root * 2 + 1;
	while (root<n&&i<n)
	{
		if (i+1<n&&a[i]>a[i + 1])
		{
			i = i + 1;
		}
		if (a[root] > a[i])
		{
			temp = a[root];
			a[root] = a[i];
			a[i] = temp;
			root = i;
			i = root * 2 + 1;
		}
		else
			break;
	}


}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
void ADjustup(HPDataType* a, size_t root)
{
	int child=root;
	int father;
	int temp;
	while (child > 0)
	{
		father = (child - 1) / 2;
		if (a[child] < a[father])
		{
			temp = a[child];
			a[child] = a[father];
			a[father] = temp;
			child = father;
		}
		else
			break;
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_capacity = hp->_size)
	{
		HPDataType* temp;
		temp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)* 2*hp->_capacity);
		if (temp)
		{
			hp->_a = temp;
			hp->_capacity = hp->_capacity * 2;
		}
		else
		{
			printf("À©ÈÝÊ§°Ü");
			return;
		}
	}

	
	hp->_a[hp->_size]=x;
	hp->_size++;

	ADjustup(hp->_a, hp->_size - 1);

}
void HeapPop(Heap* hp)
{
	assert(hp);
	int temp;
	temp = hp->_a[0];
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = temp;
	hp->_size--;
	ADjustdown(hp->_a, hp->_size, 0);

}
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size - 1;
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	if (hp->_size)
		return 1;
	else
		return 0;
}
void HeapSort(int* a, int n)
{
	Heap hp;
	int temp;
	int i;
	HeapInit(&hp, a, n);
	while (hp._size > 1)
	{
		temp = hp._a[0];
		hp._a[0] = hp._a[hp._size - 1];
		hp._a[hp._size - 1] = temp;
		hp._size--;
		ADjustdown(hp._a, hp._size, 0);
	}
	hp._size = n;
	for (i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	HeapDestory(&hp);
}



void TestHeap()
{
	Heap hp;
	int i;
	int a[9] = { 99, 55, 44, 65, 34, 77, 88, 123, 45 };
	HeapInit(&hp,a,9);

	HeapPush(&hp, 1);

	for (i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	HeapDestory(&hp);
}
void HeapTopk(HPDataType* a, int k, int n)
{
	assert(a);
	int i;
	int temp;
	Heap hp;
	HeapInit(&hp,a,k);
	for (i = k; i < n; i++)
	{
		if (a[0] < a[i])
		{
			temp = a[i];
			a[i] = a[0];
			a[0] = temp;
		}
		ADjustdown(a, k, 0);
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}

	HeapDestory(&hp);

}