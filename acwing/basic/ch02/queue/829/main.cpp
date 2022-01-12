#include<iostream>

using namespace std;

const int N = 100010;

int q[N], hh = 0, tt = -1;

void push(int x) {
    q[++ tt] = x;
}

void pop() {
    hh++;
}

void query() {
    cout << q[hh] << endl;
}

void empty() {
    tt < hh ? cout << "YES" << endl : cout << "NO" << endl;
}

int main() {
    int n;
    cin >> n;

    while (n --) {
        string opt;
        cin >> opt;

        if (opt == "push") {
            int x;
            cin >> x;
            push(x);
        } else if (opt == "pop") {
            pop();
        } else if (opt == "query") {
            query();
        } else if (opt == "empty") {
            empty();
        }

    }

    return 0;
}