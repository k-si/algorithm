#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N], q[N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);


    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i ++) cin >> a[i];

    int hh = 0, tt = -1;

    for (int i = 0; i < n; i ++) {
        if (i - k + 1 > q[hh]) hh ++;
        while (hh <= tt && a[i] < a[q[tt]]) tt--;
        q[++tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << " ";
    }

    cout << endl;

    hh = 0, tt = -1;

    for (int i = 0; i < n; i ++) {
        if (i - k + 1 > q[hh]) hh ++;
        while (hh <= tt && a[i] > a[q[tt]]) tt--;
        q[++tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << " ";
    }

    return 0;
}