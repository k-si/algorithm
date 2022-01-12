#include<iostream>

using namespace std;

const int N = 31 * (1e5 + 10);

int a[N][2], idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i --) {
        int u = 1 & (x >> i);
        if (!a[p][u]) a[p][u] = ++idx;
        p = a[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int u = 1 & (x >> i);
        if (a[p][!u]) {
            res |= 1 << i;
            p = a[p][!u];
        } else{
            p = a[p][u];
        }
    }
    return res;
}

int main() {
    int n, res = 0;
    cin >> n;

    for (int i = 0; i < n; i ++ ) {
        int x;
        scanf("%d", &x);
        insert(x);
        res = max(res, query(x));
    }
    cout << res << endl;

    return 0;
}