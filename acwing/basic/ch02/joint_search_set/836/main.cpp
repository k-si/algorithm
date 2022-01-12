#include<iostream>

using namespace std;

const int N = 100000 + 10;
int p[N];

int find(int x) {
    if (x == p[x]) return x;
    p[x] = find(p[x]);
    return p[x];
}

int main() {
    for (int i = 0; i < N; i ++) p[i] = i;

    int n, m;
    scanf("%d%d", &n, &m);

    while (m -- ) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);

        if (op[0] == 'M') {
            p[find(a)] = find(b);
        } else {
            if (find(a) == find(b)) printf("Yes\n");
            else printf("No\n");
        }
    }
}