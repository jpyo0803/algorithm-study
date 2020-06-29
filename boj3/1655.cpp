//
// Say Middle
// Problem: https://www.acmicpc.net/problem/1655
//

#include <cstdio>
#include <vector>

using namespace std;

int parent(int c) { return (c - 1) / 2; }

int left(int p) { return p * 2 + 1; }

int right(int p) { return p * 2 + 2; }

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int N, e;

vector<int> min_heap, max_heap;

void min_heapify(int p) {
    int l = left(p);
    int r = right(p);

    int smallest = p;
    if (l < min_heap.size() && min_heap[p] > min_heap[l]) {
        smallest = l;
    }
    if (r < min_heap.size() && min_heap[smallest] > min_heap[r]) {
        smallest = r;
    }

    if (smallest != p) {
        swap(min_heap[smallest], min_heap[p]);
        min_heapify(smallest);
    }
}

void max_heapify(int p) {
    int l = left(p);
    int r = right(p);

    int largest = p;
    if (l < max_heap.size() && max_heap[p] < max_heap[l]) {
        largest = l;
    }
    if (r < max_heap.size() && max_heap[largest] < max_heap[r]) {
        largest = r;
    }

    if (largest != p) {
        swap(max_heap[largest], max_heap[p]);
        max_heapify(largest);
    }
}

void insert_min(int e) {
    min_heap.push_back(e);

    int i = min_heap.size() - 1;
    while (i != 0 && min_heap[i] < min_heap[parent(i)]) {
        swap(min_heap[i], min_heap[parent(i)]);
        i = parent(i);
    }
}

void insert_max(int e) {
    max_heap.push_back(e);

    int i = max_heap.size() - 1;
    while (i != 0 && max_heap[i] > max_heap[parent(i)]) {
        swap(max_heap[i], max_heap[parent(i)]);
        i = parent(i);
    }
}

int extract_min() {
    int ret = min_heap[0];
    min_heap[0] = min_heap[min_heap.size() - 1];
    min_heap.pop_back();
    min_heapify(0);
    return ret;
}

int extract_max() {
    int ret = max_heap[0];
    max_heap[0] = max_heap[max_heap.size() - 1];
    max_heap.pop_back();
    max_heapify(0);
    return ret;
}

int get_min() { return min_heap[0]; }

int get_max() { return max_heap[0]; }

int main() {
    scanf("%d", &N);
    int ref = 100000000;
    for (int i = 0; i < N; i++) {
        scanf("%d", &e);

        if (ref < e) insert_min(e);
        else insert_max(e);

        if (max_heap.size() > min_heap.size() + 1) {
            insert_min(extract_max());
        } else if (max_heap.size() < min_heap.size()) {
            insert_max(extract_min());
        }
        ref = get_max();
        printf("%d\n", ref);
    }

    return 0;
}

