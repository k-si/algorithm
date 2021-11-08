/*
 * 归并排序
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int tmp[N];

void merge_sort(int a[], int l, int r) {
    if (l >= r) return;

    // 找分界点
    int mid = (l + r) >> 1;

    // 先递归
    merge_sort(a, l, mid), merge_sort(a, mid + 1, r);

    int k = 0, i = l, j = mid + 1;

    // 合并成tmp
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k ++] = a[i ++];
        else tmp[k ++] = a[j ++];
    }
    while (i <= mid) tmp[k ++] = a[i ++];
    while (j <= r) tmp[k ++] = a[j ++];

    // tmp -> a
    for (int q = l, m = 0; q <= r; q ++, m ++) a[q] = tmp[m];
}

int main() {
    int n;
    scanf("%d", &n);

    int a[N];
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);

    merge_sort(a, 0, n - 1);

    for (int i = 0; i < n; i ++) printf("%d ", a[i]);

    return 0;
}
