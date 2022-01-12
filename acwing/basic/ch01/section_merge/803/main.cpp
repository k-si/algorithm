#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n;
vector<PII> sec;

void section_merge(vector<PII> &sec) {
    vector<PII> res;

    sort(sec.begin(), sec.end());

    int l = -2e9, r = -2e9;

    for (int i = 0; i < sec.size(); i++) {
        if (sec[i].first <= r) {
            r = max(sec[i].second, r);
        } else {
            res.push_back({l, r});
            l = sec[i].first, r = sec[i].second;
        }
    }

    if (l != -2e9) sec.push_back({l, r});

    sec = res;
}

int main() {
    cin >> n;

    while (n--) {
        int l, r;
        cin >> l >> r;
        sec.push_back({l, r});
    }

    section_merge(sec);

    cout << sec.size() << endl;

    return 0;
}