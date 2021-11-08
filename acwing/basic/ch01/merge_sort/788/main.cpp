/*
 * 归并排序练习题 求逆序对数量
 */

#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int tmp[N];
long long cnt;

void divide_and_conquer(int a[], int l, int r) {
    if (l >= r) return;

    int mid = (l + r) >> 1;
    divide_and_conquer(a, l, mid), divide_and_conquer(a, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k ++] = a[i ++];
        else {
            cnt += (mid - i + 1); // 有序的两个数组，数组2小于数组1的开头，那么也小于数组1后面的数
            tmp[k ++] = a[j ++];
        }
    }
    while (i <= mid) tmp[k ++] = a[i ++];
    while (j <= r) tmp[k ++] = a[j ++];

    for (int q = l, t = 0; q <= r; q ++ , t ++) a[q] = tmp[t];
}

int main() {
    int n;
    scanf("%d", &n);

    int a[N];
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);

    divide_and_conquer(a, 0, n - 1);

    printf("%lld", cnt);
    // cout << cnt;

    return 0;
}

