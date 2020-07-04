//
// Number Card
// Problem: https://www.acmicpc.net/problem/10815
//

#include <cstdio>

const int MAX{500000};
int N, M, card;
int cards[MAX];

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int j = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    swap(arr[j], arr[r]);
    return j;
}

void QuickSort(int arr[], int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        QuickSort(arr, l, p - 1);
        QuickSort(arr, p + 1, r);
    }
}

bool BinarySearch(int arr[], int l, int r, int key) {
    if (l > r) return false;
    int m = (l + r) / 2;

    if (arr[m] < key) {
        return BinarySearch(arr, m + 1, r, key);
    } else if (arr[m] > key) {
        return BinarySearch(arr, l, m - 1, key);
    }
    return true;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &cards[i]);
    }
    QuickSort(cards, 0, N - 1);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &card);
        printf("%d ", BinarySearch(cards, 0, N - 1, card));
    }
}

