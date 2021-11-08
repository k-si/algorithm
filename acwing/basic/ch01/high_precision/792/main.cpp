/*
 * 高精度减法
 */

#include<iostream>
#include<vector>

using namespace std;

// 判断A >= B
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i])
            return A[i] > B[i];
        return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size(); i++) {
        int sum = A[i] - t;
        if (i < B.size()) sum -= B[i];
        C.push_back((sum + 10) % 10); // 兼容 sum <= 0 和 sum > 0
        if (sum < 0) t = 1;
        else t = 0;
    }
    // 123 - 122 = 003 去除前置0
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main() {
    string a, b;
    cin >> a >> b;

    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if (cmp(A, B)) {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    } else {
        auto C = sub(B, A);
        cout << "-";
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    }

    return 0;
}
