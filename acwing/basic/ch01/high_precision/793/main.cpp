/*
 * 高精度乘法，大数乘小数
 */

#include<iostream>
#include<vector>

using namespace std;

// 计算过程中，把小数b看成一个整体
vector<int> mul(vector<int> A, int b) {
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size(); i ++ ) {
        int mul = A[i] * b + t;
        C.push_back(mul % 10);
        t = mul / 10;
    }
    if (t) C.push_back(t);


    return C;
}

int main() {
    string a; // 大数a string
    int b; // 小数b int

    cin >> a >> b;

    if (a == "0" || b == 0) { // 特殊情况提前处理吧
        cout << 0;
        return 0;
    }

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);

    return 0;
}
