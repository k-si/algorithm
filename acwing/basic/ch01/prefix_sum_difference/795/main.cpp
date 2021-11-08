/*
 * 一维前缀和
 */

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];

int main() {
    int n, m;
    cin >> n >> m;

    // a[l, r] = b[r] - b[l - 1]
    // 为了l - 1 >= 0, i从1开始
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) b[i] += b[i - 1] + a[i];

    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << b[r] - b[l - 1] << endl;
    }
    return 0;
}
