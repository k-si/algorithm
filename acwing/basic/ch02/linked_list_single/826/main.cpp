#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, head, val[N], nex[N], idx;

void init() {
    head = -1;
    idx = 0;
}

void insert_to_head(int x) {
    val[idx] = x;
    nex[idx] = head;
    head = idx;
    idx ++;
}

void remove(int k) {
    if (k == 0) {
        head = nex[head];
        return;
    }

    nex[k - 1] = nex[nex[k - 1]];
}

void insert(int k, int x) {
    val[idx] = x;

    nex[idx] = nex[k - 1];
    nex[k - 1] = idx;

    idx ++;
}

int main() {
    cin >> n;

    init();

    while (n--) {
        char opt;
        cin >> opt;

        if (opt == 'H') {
            int x;
            cin >> x;
            insert_to_head(x);
        } else if (opt == 'D') {
            int k;
            cin >> k;
            remove(k);
        } else {
            int k, x;
            cin >> k >> x;
            insert(k, x);
        }
    }
    for (int i = head; i != -1; i = nex[i]) cout << val[i] << " ";
    cout << endl;

    return 0;
}