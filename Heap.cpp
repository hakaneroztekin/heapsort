#include "Heap.h"
#include <math.h>

Heap::Heap(int heap_capacity){
	heap_size = 0;
	this->heap_capacity = heap_capacity;
	arrPtr = new int[heap_capacity];
};


void Heap::max_heapify(int A[], int i){
	int l = left_child(i);
	int r = right_child(i);
	int largest;

	if (l < heap_size && A[l] > A[i])
		largest = l;
	else largest = i;
	if (r < heap_size && A[r] > A[largest])
		largest = r;
	if (i != largest)
		swap(&A[i], &A[largest]);
	max_heapify(A, largest);
};


void Heap::build_max_heap(int A[]){
	heap_size = heap_capacity; // heap_capacity = A.length \ might be erroneous. I need to redeclare dynamic array for new heap size. Or delete this line?
	for (int i = floor(float(heap_capacity/2)); i > 1; i--){
		max_heapify(A, i);
	}
};


void Heap::heapsort(int A[]){
	build_max_heap(A);
	for (int i = heap_capacity; i >= 2; i--){ // heap_capacity = A.length
		swap(&A[i], &A[1]);
		heap_size -= 1;
		max_heapify(A, 1);
	}
};


int Heap::maximum(int A[]){

	return 0; // placeholder
};


int Heap::extract_max(int A[]){

	return 0; // placeholder
};


void Heap::increase_key(int A[], int i, int key){

};


void Heap::insert(int A[], int key){

};

void Heap::swap(int *i, int *j){
	int temp = *i;
	*i = *j;
	*j = temp;
};