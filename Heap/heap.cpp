#include "heap.h"
Heap::Heap(int size = 100) {
	m_heapSize = size;
	m_heap = new Node[m_heapSize];
	m_numElements = 0;
	m_ROOT_INDEX = 1;
}
Heap::~Heap() {
	delete[] m_heap;
}
bool Heap::empty() {
	return (m_numElements == 0);
}
bool Heap::full() {
	return (m_numElements == m_heapSize);
}
Node Heap::top() {
	return m_heap[m_ROOT_INDEX];
}
void Heap::dump() {
	for (int i = m_ROOT_INDEX; i <= m_numElements; i++) {
		cout << m_heap[i].m_data << " => " << m_heap[i].m_key << endl;
	}
}
void Heap::enqueue(int key, int data) {
	if (!full()) {
		Node newNode = Node(key, data);
		m_numElements++;
		m_heap[m_numElements] = newNode;
		upHeap(m_numElements);//The swapping of elements function
	}
}
void Heap::upHeap(int index) {
	if (index > m_ROOT_INDEX) {
		if (m_heap[index].m_key < m_heap[index / 2].m_key) {
			Node temp = m_heap[index];
			m_heap[index] = m_heap[index / 2];
			m_heap[index / 2] = temp;
			upHeap(index / 2);
		}
	}
}
Node Heap::dequeue() {
	Node temp;
	if (!empty()) {
		temp = m_heap[m_ROOT_INDEX];
		m_heap[m_ROOT_INDEX] = m_heap[m_numElements];
		m_numElements--;
		downHeap(m_ROOT_INDEX);
	}
	return temp;
}
void Heap::downHeap(int index) {
	int minChild = index;
	int left = index * 2;
	int right = (index * 2) + 1;
	if (left <= m_numElements && m_heap[left].m_key < m_heap[minChild].m_key) {
		minChild = left;
	}
	if (right <= m_numElements && m_heap[right].m_key < m_heap[minChild].m_key) {
		minChild = right;
	}
	if (index != minChild) {
		Node temp = m_heap[minChild];
		m_heap[minChild] = m_heap[index];
		m_heap[index] = temp;
		downHeap(minChild);
	}
}
void Heap::downHeap(int index, int end) {
	int minChild = index;
	int left = index * 2;
	int right = (index * 2) + 1;
	if (left < end && m_heap[left].m_key < m_heap[minChild].m_key) {
		minChild = left;
	}
	if (right < end && m_heap[right].m_key < m_heap[minChild].m_key) {
		minChild = right;
	}
	if (index != minChild) {
		Node temp = m_heap[minChild];
		m_heap[minChild] = m_heap[index];
		m_heap[index] = temp;
		downHeap(minChild, end);
	}
}
void Heap::reHeapify() {
	for (int i = m_numElements / 2; i >= m_ROOT_INDEX; i--) {
		downHeap(i);
	}
}
void Heap::heapSort() {
	for (int i = m_numElements; i > m_ROOT_INDEX; i--) {
		swap(m_heap[m_ROOT_INDEX], m_heap[i]);
		downHeap(m_ROOT_INDEX, i);
	}
}