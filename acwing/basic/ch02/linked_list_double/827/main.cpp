#include<iostream>
#include<string>

using namespace std;

const int N = 100010;

int val[N], pre[N], nex[N], idx;

void init() {
    idx = 2;
    nex[0] = 1;
    pre[1] = 0;
}

// 在下标为k的节点的后面插入节点
void insert(int k, int x) {
    val[idx] = x;
    pre[idx] = k;
    nex[idx] = nex[k];
    pre[nex[k]] = idx;
    nex[k] = idx;
    idx ++;
}

// 删除下标为k的节点的后面的节点
void remove(int k) {
    pre[nex[k]] = pre[k];
    nex[pre[k]] = nex[k];
}


int main() {
    int n;
    cin >> n;

    init();

    while (n --) {
        string opt;
        cin >> opt;

        if (opt == "L") {
            int x;
            cin >> x;

            insert(0, x);
        } else if (opt == "R") {
            int x;
            cin >> x;

            insert(pre[1], x);
        } else if (opt == "D") {
            int k;
            cin >> k;

            remove(k + 1);
        } else if (opt == "IR") {
            int k, x;
            cin >> k >> x;

            insert(k + 1, x);
        } else if (opt == "IL") {
            int k, x;
            cin >> k >> x;

            insert(pre[k + 1], x);
        }
    }


    for (int i = nex[0]; i != 1; i = nex[i]) cout << val[i] << " ";

    return 0;
}