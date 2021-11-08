/*
 * 快速排序
 */

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

void quick_sort(int q[], int low, int high) {
    if (low >= high) return;
    
    int base = q[low], L = low, R = high;
    
    while (L < R) {
        while (L < R && q[R] >= base) R --;
        q[L] = q[R];
        while (L < R && q[L] <= base) L ++;
        q[R] = q[L];
    }
    q[L] = base;
    
    quick_sort(q, low, L - 1);
    quick_sort(q, L + 1, high);
}

void quick_sort2(int q[], int l, int r) {
    if (l >= r) return;

    int x = q[(l + r) >> 1], i = l - 1, j = r + 1;

    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort2(q, l, j);
    quick_sort2(q, j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);

    int q[N];
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);

    quick_sort2(q, 0, n - 1);

    for (int i = 0; i < n; i ++) printf("%d ", q[i]);
}