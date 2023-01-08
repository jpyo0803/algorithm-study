#ifndef AUXILIARY_MY_SORT_H_
#define AUXILIARY_MY_SORT_H_

namespace jpyo0803 {
namespace algorithm {
template <typename T>
uint64_t BubbleSort(T* array, std::size_t size) {
  uint64_t swap_count = 0;
  for (std::size_t i = 0; i < size; ++i) {
    for (std::size_t j = i + 1; j < size; ++j) {
      if (array[i] > array[j]) {
        T tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        ++swap_count;
      }
    }
  }
  return swap_count;
}
}  // namespace algorithm
}  // namespace jpyo0803

#endif  // AUXILIARY_MY_SORT_H_