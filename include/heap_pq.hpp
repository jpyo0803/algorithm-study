/* heap based priority queue */

#include <vector>
#include <utility>
#include <cstring>
#include <iostream>

template<typename KeyType, typename ObjectType>
class Container {
 public:
    Container() {};
    Container(KeyType _key, ObjectType _obj) : key(_key), obj(_obj) {}

    KeyType key;
    ObjectType obj;
};

template<typename KeyType, typename ObjectType>
class Max_Heap {
public:
    Max_Heap() {
        arr.push_back(nullptr);
    };
    ~Max_Heap() {}

    void insert(Container<KeyType, ObjectType>* cont_ptr) {
        arr.push_back(cont_ptr);
        max_post_insert(arr.size() - 1);
    }

    Container<KeyType, ObjectType>* extract_max() {
        Container<KeyType, ObjectType>* ret = nullptr;
        if (!is_empty()) {
            std::swap(arr[1], arr[arr.size() - 1]);
            ret = arr[arr.size() - 1];
            arr.pop_back();
            max_heapify(1);
        }
        return ret;
    }

    const std::vector<Container<KeyType, ObjectType>*>& get_array() const {
        return arr;
    }

    bool is_empty() { return arr.size() < 2; }
    std::vector<Container<KeyType, ObjectType>*> arr;

private:
    void max_heapify(int i) {
        int left = i * 2;
        int right = left + 1;

        int largest;
        if (left < arr.size() && arr[left]->key > arr[i]->key) {
            largest = left;
        } else {
            largest = i;
        }

        if (right < arr.size() && arr[right]->key > arr[largest]->key) {
            largest = right;
        }

        if (largest != i) {
            std::swap(arr[largest], arr[i]);
            max_heapify(largest);
        }
    }
    void max_post_insert(int i) {
        int p = i / 2;
        if (p < 1) return;

        if (arr[i]->key > arr[p]->key) {
            std::swap(arr[i], arr[p]);
            max_post_insert(p);
        }
    } 
};

template<typename KeyType, typename ObjectType>
class Min_Heap {
public:
    Min_Heap() {
        arr.push_back(nullptr);
    };
    ~Min_Heap() {}

    void insert(Container<KeyType, ObjectType>* cont_ptr) {
        arr.push_back(cont_ptr);
        min_post_insert(arr.size() - 1);
    }

    Container<KeyType, ObjectType>* extract_min() {
        Container<KeyType, ObjectType>* ret = nullptr;
        if (!is_empty()) {
            std::swap(arr[1], arr[arr.size() - 1]);
            ret = arr[arr.size() - 1];
            arr.pop_back();
            min_heapify(1);
        }
        return ret;
    }

    const std::vector<Container<KeyType, ObjectType>*>& get_array() const {
        return arr;
    }

    bool is_empty() { return arr.size() < 2; }
    std::vector<Container<KeyType, ObjectType>*> arr;

private:
    void min_heapify(int i) {
        int left = i * 2;
        int right = left + 1;

        int smallest;
        if (left < arr.size() && arr[left]->key < arr[i]->key) {
            smallest = left;
        } else {
            smallest = i;
        }

        if (right < arr.size() && arr[right]->key < arr[smallest]->key) {
            smallest = right;
        }

        if (smallest != i) {
            std::swap(arr[smallest], arr[i]);
            min_heapify(smallest);
        }
    }
    void min_post_insert(int i) {
        int p = i / 2;
        if (p < 1) return;

        if (arr[i]->key < arr[p]->key) {
            std::swap(arr[i], arr[p]);
            min_post_insert(p);
        }
    } 
};