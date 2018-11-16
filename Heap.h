

class Heap{
private:
	int heap_size;
	int *arrPtr;
	int heap_capacity;

public:
	Heap(){};
	Heap(int heap_capacity);
	void max_heapify(int A[], int i);
	void build_max_heap(int A[]);
	void heapsort(int A[]);
	int maximum(int A[]);
	int extract_max(int A[]);
	void increase_key(int A[], int i, int key);
	void insert(int A[], int key);
	void swap(int *i, int *j);
	int parent(int i) { return (i - 1) / 2; } // might need to take floor correctly, as integer.
	int left_child(int i) { return 2 * i + 1; }
	int right_child(int i) { return 2 * i + 2; }
};