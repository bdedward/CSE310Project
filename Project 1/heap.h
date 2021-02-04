//This contains the Structs used in the heap.cpp

struct ELEMENT{
	int key;
};

struct HEAP{
	int capacity;
	int size;
	ELEMENT *H;
};

HEAP* Initialize(int);
void BuildHeap(HEAP*, ELEMENT*, int);
void Insert(HEAP*, int, int);
int DeleteMin(HEAP*, int);
void DecreaseKey(HEAP*, int, int, int);
void printHeap(HEAP*);
void MinHeapify(HEAP*, int);
