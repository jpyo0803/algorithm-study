// 생일
// https://www.acmicpc.net/problem/5635

#include <stdio.h>

#include <string>

using namespace std;

int n, y, m, d;
char name[16];

struct Person {
  string name;
  int year, month, day;
  Person(string _name, int _year, int _month, int _day)
      : name(_name), year(_year), month(_month), day(_day) {}

  bool operator<(const Person& other) {
    if (year == other.year) {
      if (month == other.month) {
        return day > other.day;
      } else {
        return month > other.month;
      }
    }
    return year > other.year;
  }

  bool operator>(const Person& other) { return !(*this < other); }
};

int main() {
  scanf("%d", &n);
  Person oldest("old", 2011, 0, 0);
  Person youngest("young", 0, 0, 0);
  for (int i = 0; i < n; i++) {
    scanf("%s%d%d%d", name, &d, &m, &y);
    Person tmp(name, y, m, d);
    if (oldest < tmp) oldest = tmp;
    if (youngest > tmp) youngest = tmp;
  }
  printf("%s\n%s\n", youngest.name.c_str(), oldest.name.c_str());
  return 0;
}
