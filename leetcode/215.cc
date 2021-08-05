//
// 215. Kth Largest Element in an Array
// Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/
//

class Solution {

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(int arr[], int l, int r, int x) {
        int i;
        for (i = l; i < r; i++) {
            if (arr[i] == x) break;
        }
        swap(arr[i], arr[r]);

        i = l;
        for (int j = l; j < r; j++) {
            if (arr[j] <= x) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }

    int findMedian(int subarr[], int n) {
        sort(subarr, subarr + n);
        return subarr[n / 2];
    }

    int quick_select(int arr[], int l, int r, int k) {
        int n = r - l + 1;

        int i;
        int median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++) {
            median[i] = findMedian(arr + l + (i * 5), 5);
        }
        if (i * 5 < n) {
            median[i] = findMedian(arr + l + (i * 5), n % 5);
            i++;
        }

        int medOfMeds = (i == 1) ? median[i - 1] : quick_select(median, 0, i - 1, i / 2);

        int pivot = partition(arr, l, r, medOfMeds);

        if (pivot - l == k - 1) {
            return arr[pivot];
        } else if (pivot - l < k - 1) {
            return quick_select(arr, pivot + 1, r, k - (pivot - l) - 1);
        } else {
            return quick_select(arr, l, pivot - 1, k);
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int* arr = &nums[0];
        return quick_select(arr, 0, nums.size() - 1, nums.size() - k + 1);
    }
};