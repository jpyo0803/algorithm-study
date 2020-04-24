/* heap based priority queue */

#include <vector>
#include <memory>
#include <iostream>

using namespace std;

int parent(int me) { return (me - 1) / 2; }
int left_child(int me) { return me * 2 + 1; }
int right_child(int me) { return me * 2 + 2; }

template<typename KeyType, typename ObjectType>
class Container {
public:
    Container(KeyType _key, ObjectType _obj, int _idx) : key(_key), obj(_obj), idx(_idx) {}; 
    KeyType key;
    ObjectType obj;
    int idx;
};

template<typename KeyType, typename ObjectType>
void swap_container(shared_ptr<Container<KeyType, ObjectType>>& x, shared_ptr<Container<KeyType, ObjectType>>& y) {
    int tmp_idx = x->idx;
    x->idx = y->idx;
    y->idx = tmp_idx;
    std::swap(x, y);
}

template<typename KeyType, typename ObjectType>
class Max_Heap {
public:
    Max_Heap() {};
    ~Max_Heap() {};

    void insert(KeyType key, ObjectType obj) {
        auto tmp = make_shared<Container<KeyType, ObjectType>>(key, obj, arr.size());
        arr.push_back(tmp);
        max_order_key(arr.size() - 1);
    }

    shared_ptr<Container<KeyType, ObjectType>> extract_max() {
        if (is_empty()) return nullptr;

        swap_container(arr[0], arr[arr.size() - 1]);
        auto ret = arr[arr.size() - 1];
        arr.pop_back();
        max_heapify(0); 

        return ret;
    }

    shared_ptr<Container<KeyType, ObjectType>> get_max() {
        if (is_empty()) return nullptr;
        return arr[0];
    }

    void update_key(shared_ptr<Container<KeyType, ObjectType>> cont, KeyType new_key) {
        cont->key = new_key;
        max_order_key(cont->idx);
        max_heapify(cont->idx);
    }

    bool is_empty() { return arr.size() == 0; }

private:
    void max_order_key(int i) {
        int p = parent(i);
        if (p < 0) return;

        if (arr[i]->key > arr[p]->key) {
            swap_container(arr[i], arr[p]);
            max_order_key(p);
        }
    } 

    void max_heapify(int i) {
        int left = left_child(i);
        int right = right_child(i);

        int largest;
        if (left < arr.size() && arr[left]->key > arr[i]->key) largest = left;
        else largest = i;

        if (right < arr.size() && arr[right]->key > arr[largest]->key) largest = right;

        if (largest != i) {
            swap_container(arr[i], arr[largest]);
            max_heapify(largest);
        }
    }
    vector<shared_ptr<Container<KeyType, ObjectType>>> arr;
};


template<typename KeyType, typename ObjectType>
class Min_Heap {
public:
    Min_Heap() {};
    ~Min_Heap() {};

    void insert(KeyType key, ObjectType obj) {
        auto tmp = make_shared<Container<KeyType, ObjectType>>(key, obj, arr.size());
        arr.push_back(tmp);
        min_order_key(arr.size() - 1);
    }

    shared_ptr<Container<KeyType, ObjectType>> extract_min() {
        if (is_empty()) return nullptr;

        swap_container(arr[0], arr[arr.size() - 1]);
        auto ret = arr[arr.size() - 1];
        arr.pop_back();
        min_heapify(0); 

        return ret;
    }

    shared_ptr<Container<KeyType, ObjectType>> get_min() {
        if (is_empty()) return nullptr;
        return arr[0];
    }

    void update_key(shared_ptr<Container<KeyType, ObjectType>> cont, KeyType new_key) {
        cont->key = new_key;
        min_order_key(cont->idx);
        min_heapify(cont->idx);
    }

    bool is_empty() { return arr.size() == 0; }

private:
    void min_order_key(int i) {
        int p = parent(i);
        if (p < 0) return;

        if (arr[i]->key < arr[p]->key) {
            swap_container(arr[i], arr[p]);
            min_order_key(p);
        }
    } 

    void min_heapify(int i) {
        int left = left_child(i);
        int right = right_child(i);

        int smallest;
        if (left < arr.size() && arr[left]->key < arr[i]->key) smallest = left;
        else smallest = i;

        if (right < arr.size() && arr[right]->key < arr[smallest]->key) smallest = right;

        if (smallest != i) {
            swap_container(arr[i], arr[smallest]);
            min_heapify(smallest);
        }
    }
    vector<shared_ptr<Container<KeyType, ObjectType>>> arr;
};
