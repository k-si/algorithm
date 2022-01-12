#include<iostream>

using namespace std;

const int N = 100010;

int stk[N], tt = -1;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++ ) {
        int x;
        cin >> x;

        while (tt != -1 && stk[tt] >= x) tt--;
        if (tt == -1) cout << -1 << " ";
        else cout << stk[tt] << " ";
        stk[++tt] = x;
    }
    cout << endl;

    return 0;
}