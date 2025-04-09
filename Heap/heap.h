#include <iostream>
using namespace std;

class Node {
public:
	friend class Heap;
	Node() { m_key = 0; m_data = 0;}
	Node(int key, int data) { m_key = key; m_data = data; }
private:
	int m_key;
	int m_data;
};

class Heap {
public:
	Heap(int size);
	~Heap();
	void enqueue(int key, int data);
	Node dequeue();
	Node top();
	void dump();
	bool full();
	bool empty();
	void upHeap(int index);
	void downHeap(int index);
	void downHeap(int index, int end);
	void heapSort();
	void reHeapify();
private:
	Node* m_heap;
	int m_heapSize;
	int m_numElements;
	int m_ROOT_INDEX;
};