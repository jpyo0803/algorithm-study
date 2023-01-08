// 1115. Print FooBar Alternately
// https://leetcode.com/problems/print-foobar-alternately/

class FooBar {
 private:
  int n;
  bool flag_ = true;
  mutex fmtx_;
  condition_variable cv1_, cv2_;

 public:
  FooBar(int n) { this->n = n; }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> ulk(fmtx_);
      cv1_.wait(ulk, [this] { return flag_; });
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();

      flag_ = !flag_;
      cv2_.notify_one();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> ulk(fmtx_);
      cv2_.wait(ulk, [this] { return !flag_; });
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();

      flag_ = !flag_;
      cv1_.notify_one();
    }
  }
};