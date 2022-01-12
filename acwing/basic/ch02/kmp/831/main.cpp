#include<iostream>
#include<string>

using namespace std;

const int N = 1e5 + 10;

int n, m;
string p, s;
int match[N];

void build() {
    match[0] = -1;

    for (int i = 1; i < n; i ++) {
        int idx = match[i - 1];

        while (idx >= 0 && p[i] != p[idx + 1])
            idx = match[idx];
        if (p[i] == p[idx + 1])
            match[i] = idx + 1;
        else
            match[i] = -1;
    }
}



int main() {

    cin >> n >> p >> m >> s;

    build();

    int i = 0, j = 0;
    while (i < m) {
        while (i < m && j < n) {
            if (s[i] == p[j]) i++, j++;
            else if (j > 0) j = match[j - 1] + 1;
            else i++;
        }
        if (j == n) {
            cout << i - n << " ";
            j = match[j - 1] + 1;
        }
    }


    return 0;
}