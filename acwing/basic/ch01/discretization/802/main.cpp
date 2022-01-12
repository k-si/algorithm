#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 3 * (1e5 + 10);

int n, m;

vector<int> used; // 所有会用到的下标
vector<pair<int, int>> add; // 记录添加操作
vector<pair<int, int>> query; // 记录查询操作

int a[N], s[N];

// 找到x在used的中的位置
int find(int x) {
    int l = 0, r = used.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (used[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1; // 下标+1，方便求前缀和
}


int main() {
    cin >> n >> m;

    // 读入所有的下标
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        used.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        used.push_back(l);
        used.push_back(r);
    }

    // 将所有用到的下标排序、去重
    sort(used.begin(), used.end());
    used.erase(unique(used.begin(), used.end()), used.end());

    // 已经将下标离散化成功，开始模拟add
    for (auto item : add) {
        int idx = find(item.first);
        a[idx] += item.second;
    }

    // 构造前缀和
    for (int i = 1; i <= used.size(); i++) s[i] += s[i - 1] + a[i];

    // 求前缀和
    for (auto item : query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}