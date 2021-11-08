/*
 * 二分算法联系 数的三次方根
 */

#include<iostream>

using namespace std;

int main() {
    double n;
    scanf("%lf", &n);

    double l = -100, r = 100;

    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid <= n) l = mid;
        else r = mid;
    }

    printf("%.6lf", l);

    return 0;
}
