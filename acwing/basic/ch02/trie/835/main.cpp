#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N][26], cnt[N], idx;
char str[N];

void insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if (!a[p][u]) a[p][u] = ++idx;
        p = a[p][u];
    }
    cnt[p]++;
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i ++ ) {
        int u = str[i] - 'a';
        if (!a[p][u]) return 0;
        p  = a[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    cin >> n;

    while (n --) {
        char op[2];
        scanf("%s%s", op, str);

        if (op[0] == 'I') {
            insert(str);
        } else {
            printf("%d\n", query(str));
        }
    }


    return 0;
}