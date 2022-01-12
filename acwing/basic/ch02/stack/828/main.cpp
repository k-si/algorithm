#include<iostream>

using namespace std;

const int N = 100010;

int stk[N], tt = -1;

void push(int x) {
    stk[++tt] = x;
}

void pop() {
    tt--;
}

void query() {
    cout << stk[tt] << endl;;
}

void empty() {
    tt == -1 ? cout << "YES" << endl : cout << "NO" << endl;
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
        } else if (opt == "empty") {
            empty();
        } else if (opt == "query") {
            query();
        }
    }

    return 0;
}