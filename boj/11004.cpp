//
// K-th smallest number
// Problem: https://www.acmicpc.net/problem/11004
//

#include <iostream>
#include <algorithm>
#include <sys/stat.h>
#include <sys/mman.h>
class fio {
    size_t rsize;
    unsigned char* rbuf;
    int ridx;

public:
    fio() : ridx(0) {
        struct stat rstat;
        fstat(0, &rstat);
        rsize = rstat.st_size;
        rbuf = (unsigned char*)mmap(0,rsize,PROT_READ,MAP_FILE|MAP_PRIVATE,0,0);
    }

    inline bool isBlank() {
        return
                rbuf[ridx] == '\n' || rbuf[ridx] == '\t' || rbuf[ridx] == '\r' ||
                rbuf[ridx] == '\f' || rbuf[ridx] == '\v' || rbuf[ridx] == ' ';
    }
    inline void consumeBlank() { while (isBlank()) ridx++; }

    inline int readInt(){
        int res = 0, flag = 0;
        consumeBlank();
        if (rbuf[ridx] == '-'){
            flag = 1;
            ridx++;
        }
        while (!isBlank() && ridx < rsize)
            res = 10 * res + rbuf[ridx++] - '0';
        return flag ? -res : res;
    }
};

using namespace std;
const int MAX_SIZE{5000000};
int N, K, e;
int nums[MAX_SIZE];

void swap(int &a, int &b);

int partition(int arr[], int l, int r, int x);

int findMedian(int subarr[], int n);

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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    cout << quick_select(nums, 0, N - 1, K);

    return 0;
}

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