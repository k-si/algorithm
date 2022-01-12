#include<iostream>
#include<cstring>

using namespace std;

const int N = 100003, null = 0x3f3f3f3f;
int h[N];

void insert(int x) {
    int k = ((x % N) + N) % N;
    while(h[k] != null) {
        k ++;
        if (k == N) k = 0;
    }
    h[k] = x;
}

void find(int x) {
    int k = ((x % N) + N) % N;
    while (h[k] != null) {
        if (h[k] == x) {
            cout << "Yes" << endl;
            return;
        } else {
            k ++;
        }
        if (k == N) k = 0;
    }
    cout << "No" << endl;
}

int main() {

    // 初始化h[N]为比10^9大的数，表示该位置没被命中过
    // 关于0x3f的用法详见：https://www.cnblogs.com/handsomecui/p/4723949.html
    memset(h, 0x3f, sizeof h);

    int n;
    scanf("%d", &n);

    while (n -- ) {
        char op[2]; int x;
        scanf("%s%d", op, &x);
        if (op[0] == 'I') {
            insert(x);
        } else {
            find(x);
        }
    }

    return 0;
}