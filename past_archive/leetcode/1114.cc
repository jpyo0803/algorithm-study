// 1114. Print in Order
// https://leetcode.com/problems/print-in-order/

// May not be optimal solution
class Foo {
 public:
  mutex mtx1_, mtx3_, mtx4_;
  condition_variable cv1_, cv2_, cv3_, cv4_;

  bool second_ready_ = false;
  bool third_ready_ = false;
  bool first_done_ = false;
  bool second_done_ = false;

  Foo() {}

  void first(function<void()> printFirst) {
    {
      unique_lock<mutex> ulk1(mtx3_, defer_lock);
      unique_lock<mutex> ulk2(mtx4_, defer_lock);
      lock(ulk1, ulk2);
      cv3_.wait(ulk1, [this] { return second_ready_; });
      cv4_.wait(ulk2, [this] { return third_ready_; });
    }

    lock_guard<mutex> lg(mtx1_);

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    first_done_ = true;
    cv1_.notify_one();
  }

  void second(function<void()> printSecond) {
    second_ready_ = true;
    cv3_.notify_one();

    unique_lock<mutex> ulk(mtx1_);
    cv1_.wait(ulk, [this] { return first_done_; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    second_done_ = true;
    cv2_.notify_one();
  }

  void third(function<void()> printThird) {
    third_ready_ = true;
    cv4_.notify_one();

    unique_lock<mutex> ulk(mtx1_);
    cv2_.wait(ulk, [this] { return second_done_; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};