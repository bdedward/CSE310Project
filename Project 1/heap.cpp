//This file is used to complete all the min-heap operations


#include "util.h"
#include "heap.h"

using namespace std;

//Function used to initialize the heap.  The function is passed
//an integer which is assigned to the capacity of the heap.

HEAP* Initialize(int n){
	HEAP *heap = new HEAP;
	heap -> capacity = n;
	heap -> size = 0;
	return heap;
}


//Function used to build the heap.  Function is passed a pointer
//to the heap, a pointer to an ELEMENT array and an integer which
//is the size of the heap.

void BuildHeap(HEAP *heap, ELEMENT *A, int n){
	heap -> H = new ELEMENT[heap -> capacity + 1];
	heap -> size = n;
		
	for(int i = 1; i < n + 1; i++)
		heap -> H[i].key = A[i].key;
		
	for(int i = n / 2; i > 0; i--)
		MinHeapify(heap, i);
		
}

//Function used to ensure the min-heap property is maintained.
//It is passed a pointer to the heap and an integer i which is 
//the parent location.  The function is recursivly called until
//The smallest value is the parent.

void MinHeapify(HEAP *heap, int i){
	int l = 2 * i;
	int r = 2 * i + 1;
	int smallest;
	int temp;
	if(heap -> H[l].key < heap -> H[i].key && l <= heap -> size)
		smallest = l;
	else 
		smallest = i;
	if(heap -> H[r].key < heap ->H[smallest].key && r <= heap -> size)
		smallest = r;
	if(smallest != i){
		temp = heap -> H[i].key;
		heap -> H[i].key = heap -> H[smallest].key;
		heap -> H[smallest].key = temp;
		MinHeapify(heap, smallest);
	}
		
}

//Function to insert an element into the heap.  The funciton is passed
//a pointer to the heap, a flag to print the contents of heap before and
//after, and an integer k which is the value being inserted. 

void Insert(HEAP *heap, int flag, int k){
	int size = heap -> size;
	int count = 0;
	HEAP *ptr = new HEAP;
	ptr -> H = NULL;
	
	
	//Instance where Insert is called on Initialized Heap with no array memory allocated
	if(heap -> capacity != 0 && heap -> size == 0)
		heap -> H = new ELEMENT[heap -> capacity + 1];
	
	//Condition where element is inserted into a heap that is at capacity and new heap is allocated
	if(heap -> capacity < (heap -> size + 1)){
		if(flag == 2)
			printHeap(heap);
		while(1){
			size = size / 2;
			count++;
			if(size == 0)
				break;
		}
		heap -> capacity = pow(2, count);
		//Attempt a reallocation of memory...
		ptr -> H  = (ELEMENT*) realloc(heap -> H, heap -> capacity + 10 * sizeof(ELEMENT));
		
		if(ptr -> H == NULL){
	
			ELEMENT* temp = new ELEMENT[heap -> size + 1];
			for(int i = 1; i <= heap -> size; i++)
				temp[i].key  = heap -> H[i].key;
	
	
			//De-allocate old array 
			delete [] heap -> H;
			//Allocate new memory for larger heap
			heap -> H = new ELEMENT[2^count];
			//Transfer values into new heap
			for(int i = 1; i <= heap -> size; i++)
				heap -> H[i].key = temp[i].key;
		
			//Delete temp array
			delete [] temp;
		}
		else
			heap -> H = ptr -> H;
	}

	heap -> size += 1;
	heap -> H[heap -> size].key = INT_MAX;
	DecreaseKey(heap, flag, heap -> size, k);
}

//Function used to delete the min element of the heap, which is the first
//element of the heap.  The fucntion is passed a flag which enables option
//to print the contents of the heap before and after.
int DeleteMin(HEAP *heap, int flag){
	int min = 0;
	
	if(flag == 2)
		printHeap(heap);

	min = heap -> H[1].key;
	heap -> H[1] = heap -> H[heap -> size];
	heap -> size -= 1;
	MinHeapify(heap, 1);

	if(flag == 2)
		printHeap(heap);
	
	return min; 
}

//Function used to decrease an element in the heap to the indicated value.
//The function is passed a pointer to the heap, a flag to enable option
//to print the contents before and after, an integer index which indicates
//which element is being updated, and an integer value which is the value being
//updated to.

void DecreaseKey(HEAP *heap, int flag, int index, int value){
	int temp;
	
	if(index > heap -> size)
		cout << "There are only " << heap -> size << " elements in the heap. Hence this operation cannot be completed.\n";
	else if(value > heap ->H[index].key)
			cout << "\n" << value << " cannot be larger than the current value in the heap at index " << index << ". Hence this operation cannot be completed.\n";
			
	else{
		heap -> H[index].key = value;
		while(index > 1 && heap -> H[index/2].key > heap -> H[index].key){
			temp = heap -> H[index].key;
			heap -> H[index].key = heap -> H[index/2].key;
			heap -> H[index/2].key = temp;
			index = index/2;
		}
				
	
		if(flag ==2)
			printHeap(heap);
		
	}
}
//Function used to print the contents of the heap.

void printHeap(HEAP* heap){
	cout << "The capacity is " << heap -> capacity << '\n';
	cout << "Size is " << heap -> size << '\n';
	for(int i = 1; i <= heap -> size; i++){
		cout << heap -> H[i].key << '\n';
	}	
}
