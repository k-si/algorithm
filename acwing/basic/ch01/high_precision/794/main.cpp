/*
 * 高精度除法，大数除小数
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> C;

    r = 0; // 余数
    for (int i = 0; i < A.size(); i ++ ) {
        int div = (r * 10 + A[i]) / b; // 商
        C.push_back(div);
        r = (r * 10 + A[i]) % b;
    }

    reverse(C.begin(), C.end());

    // 去除前置0
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    reverse(C.begin(), C.end());

    return C;
}

int main() {
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    int r = 0; // 余数

    for (int i = 0; i < a.size(); i ++ ) A.push_back(a[i] - '0');

    auto C = div(A, b, r);

    for (int i = 0; i < C.size(); i ++ ) printf("%d", C[i]);

    cout << endl << r;

    return 0;
}
