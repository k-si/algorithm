/*
 * 算法练习题 第k个数
 */

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

bool flag;

void quick_sort(int a[], int l, int r, int n) {
    if (l >= r) return;

    int base = a[l], i = l, j = r;

    while (i < j) {
        while (i < j && a[j] >= base) j --;
        a[i] = a[j];
        while (i < j && a[i] <= base) i ++;
        a[j] = a[i];
    }
    a[i] = base;

    // 快排每次能确定base的绝对位置，
    // 如果恰好排到，直接返回，没排到就等全排完再取
    if (i == n - 1) {
        printf("%d", a[i]);
        flag = true;
        return;
    }

    quick_sort(a, l, i - 1, n), quick_sort(a, i + 1, r, n);
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);

    int a[N];
    for (int i = 0; i < m; i ++) scanf("%d", &a[i]);

    quick_sort(a, 0, m - 1, n);

    if (!flag) printf("%d", a[n - 1]);

    return 0;
}