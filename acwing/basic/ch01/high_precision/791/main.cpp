/*
 * 高精度加法
 */

#include<iostream>
#include<vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    if (B.size() > A.size()) return add(B, A);

    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size(); i ++) {
        int sum = t + A[i];
        if (i < B.size()) sum += B[i]; // 假定A的长度大于B
        C.push_back(sum % 10);
        t = sum / 10;
    }
    if (t) C.push_back(1);

    return C;
}

int main() {
    string a, b;
    cin >> a >> b;

    vector<int> A, B;

    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    vector<int> C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i --) cout << C[i];

    return 0;
}

