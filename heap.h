#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <String>
#include <utility>

typedef std::pair<std::string, double> DateValuePair;  // Assuming Date is a string for simplicity

class MaxHeap {
public:
    void insert(const std::string& date, double value);
    DateValuePair extractMax();

private:
    std::vector<DateValuePair> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);
    void buildHeap();
};

class MinHeap {
public:
    void insert(const std::string& date, double value);
    DateValuePair extractMin();

private:
    std::vector<DateValuePair> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);
    void buildHeap();
};

#endif // HEAP_H
