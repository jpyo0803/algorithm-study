/* heap based priority queue */

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template<typename T>
class Container {
public:
    Container() : key(-1) {}
    Container(int _key, T _data) : key(_key), data(_data) {}
    int key;
    T data;
};

inline int PARENT(int i) { return (i - 1) / 2; }
inline int LEFT(int i) { return (i * 2) + 1; }
inline int RIGHT(int i) { return (i * 2) + 2; }

const int NINF{-1000000000};

template<typename T>
class Max_Heap {
public:
    Max_Heap() {};
    void Max_Heapify(int i) {
        int l = LEFT(i);
        int r = RIGHT(i);
        int largest;
        if (l < heap.size() && heap[i].key < heap[l].key) {
            largest = l;
        } else {
            largest = i;
        }
        if (r < heap.size() && heap[largest].key < heap[r].key) {
            largest = r;
        }
        if (largest != i) {
            swap(heap[i], heap[largest]);
            Max_Heapify(largest);
        }
    }
    void Build_Max_Heap(vector<Container<T>> &input_arr) {
        heap = input_arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            Max_Heapify(i);
        }
    }
    Container<T> Heap_Extract_Max() {
        Container<T> ret;
        if (heap.size() == 0) {
            return ret;
        }
        ret = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        Max_Heapify(0);
        return ret;
    }
    void Heap_Increase_Key(int i, int new_key) {
        if (new_key < heap[i].key) {
            return;
        }
        heap[i].key = new_key;
        int p = PARENT(i);
        while (i > 0 && heap[PARENT(i)].key < heap[i].key) {
            swap(heap[i], heap[PARENT(i)]);
            i = PARENT(i);
        }
    }
    void Max_Heap_Insert(int key, T data) {
        heap.emplace_back(NINF, data);
        Heap_Increase_Key(heap.size() - 1, key);
    }

    bool is_empty() {
        return heap.size() == 0;
    }
    Container<T> Heap_Maximum() { return heap[0]; }

private:
    vector<Container<T>> heap;
};