// 232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
 public:
  stack<int> stk1_, stk2_;

  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { stk1_.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int ret = peek();
    stk2_.pop();
    return ret;
  }

  /** Get the front element. */
  int peek() {
    if (stk2_.empty()) {
      while (!stk1_.empty()) {
        stk2_.push(stk1_.top());
        stk1_.pop();
      }
    }

    return stk2_.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return stk1_.empty() && stk2_.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */