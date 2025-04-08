#include <iostream>
#include "heap.h"
using namespace std;

int main() {
	Heap aHeap(1001);
	for (int i = 11; i > 0; i--) {
		aHeap.enqueue(i, i * 10);
	}
	aHeap.dump();
	return 0;
}