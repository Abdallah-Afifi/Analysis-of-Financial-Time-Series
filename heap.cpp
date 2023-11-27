#include "Heap.h"
#include <String>

void MaxHeap::insert(const std::string& date, double value) {
    heap.emplace_back(date, value);
    heapifyUp(heap.size() - 1);
}

DateValuePair MaxHeap::extractMax() {
    if (heap.empty()) {
        // Handle error, the heap is empty
    }

    DateValuePair maxNode = heap.front();
    std::swap(heap.front(), heap.back());
    heap.pop_back();
    heapifyDown(0);

    return maxNode;
}

void MaxHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].second > heap[parent].second) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}

void MaxHeap::heapifyDown(int index) {
    int leftChild, rightChild, largestChild;

    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largestChild = index;

        if (leftChild < heap.size() && heap[leftChild].second > heap[largestChild].second) {
            largestChild = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild].second > heap[largestChild].second) {
            largestChild = rightChild;
        }

        if (largestChild != index) {
            std::swap(heap[index], heap[largestChild]);
            index = largestChild;
        }
        else {
            break;
        }
    }
}

void MaxHeap::buildHeap() {
    for (int i = heap.size() / 2 - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}

void MinHeap::insert(const std::string& date, double value) {
    heap.emplace_back(date, value);
    heapifyUp(heap.size() - 1);
}

DateValuePair MinHeap::extractMin() {
    if (heap.empty()) {
        // Handle error, the heap is empty
    }

    DateValuePair minNode = heap.front();
    std::swap(heap.front(), heap.back());
    heap.pop_back();
    heapifyDown(0);

    return minNode;
}

void MinHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].second < heap[parent].second) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}

void MinHeap::heapifyDown(int index) {
    int leftChild, rightChild, smallestChild;

    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        smallestChild = index;

        if (leftChild < heap.size() && heap[leftChild].second < heap[smallestChild].second) {
            smallestChild = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild].second < heap[smallestChild].second) {
            smallestChild = rightChild;
        }

        if (smallestChild != index) {
            std::swap(heap[index], heap[smallestChild]);
            index = smallestChild;
        }
        else {
            break;
        }
    }
}

void MinHeap::buildHeap() {
    for (int i = heap.size() / 2 - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}