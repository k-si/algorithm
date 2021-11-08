/*
 * 二分算法
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int a[N];
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);

    while (m --) {
        int x;
        scanf("%d", &x);

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            // 性质为 >=3
            if (a[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if (x != a[l]) {
            printf("-1 -1\n");
            continue;
        } else {
            printf("%d ", l);
            int i = 0, j = n - 1;
            while (i < j) {
                int mid = (i + j + 1) >> 1;
                // 性质为 <=3
                if (a[mid] <= x) i = mid;
                else j = mid - 1;
            }
            printf("%d\n", i);
        }
    }

    return 0;
}

