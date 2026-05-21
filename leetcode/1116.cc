// 1116. Print Zero Even Odd
// https://leetcode.com/problems/print-zero-even-odd/

class ZeroEvenOdd {
 private:
  int n;
  condition_variable cv1_, cv2_, cv3_;
  mutex mtx_;

  int flag_ = -1;

 public:
  ZeroEvenOdd(int n) { this->n = n; }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    for (int i = 1; i <= n; ++i) {
      unique_lock<mutex> ulk(mtx_);
      cv3_.wait(ulk, [this] { return flag_ == -1; });
      printNumber(0);
      if (i % 2 == 0) {
        flag_ = 0;
        cv1_.notify_one();
      } else {
        flag_ = 1;
        cv2_.notify_one();
      }
    }
  }

  void even(function<void(int)> printNumber) {
    for (int i = 2; i <= n; i += 2) {
      unique_lock<mutex> ulk(mtx_);
      cv1_.wait(ulk, [this] { return flag_ == 0; });
      printNumber(i);
      flag_ = -1;
      cv3_.notify_one();
    }
  }

  void odd(function<void(int)> printNumber) {
    for (int i = 1; i <= n; i += 2) {
      unique_lock<mutex> ulk(mtx_);
      cv2_.wait(ulk, [this] { return flag_ == 1; });
      printNumber(i);
      flag_ = -1;
      cv3_.notify_one();
    }
  }
};