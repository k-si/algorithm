#include<iostream>

using namespace std;

const int N = 100000 + 10;
int p[N], cnt[N];

int find(int x) {
    if (x == p[x]) return x;
    p[x] = find(p[x]);
    return p[x];
}

int main() {
    for (int i = 0; i < N; i ++) {
        p[i] = i;
        cnt[i] = 1;
    }

    int n, m;
    scanf("%d%d", &n, &m);

    while (m -- ) {
        string op;
        cin >> op;

        if (op == "C") {
            int a, b;
            scanf("%d%d", &a, &b);

            if (find(a) != find(b)) {
                cnt[find(b)] += cnt[find(a)];
                p[find(a)] = find(b);
            }
        } else if (op == "Q1"){
            int a, b;
            scanf("%d%d", &a, &b);

            if (find(a) == find(b)) printf("Yes\n");
            else printf("No\n");
        } else {
            int a;
            scanf("%d", &a);

            printf("%d\n", cnt[find(a)]);
        }
    }

    return 0;
}