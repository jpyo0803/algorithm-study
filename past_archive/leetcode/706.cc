// 706. Design HashMap
// https://leetcode.com/problems/design-hashmap/

class MyHashMap {
 public:
  int data[1000010];

  MyHashMap() { memset(data, 0xff, sizeof(int) * 1000010); }

  void put(int key, int value) { data[key] = value; }

  int get(int key) { return data[key]; }

  void remove(int key) { data[key] = -1; }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */