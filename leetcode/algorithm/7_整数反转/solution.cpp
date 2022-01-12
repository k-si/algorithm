#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool b = x < 0;
        vector<int> q;
        long long int res = 0;

        x = abs(x);
        while (x > 0) {
            q.push_back(x % 10);
            x /= 10;
        }
        int i = 0;
        while (i < q.size() && q[i] == 0) i ++ ; // 去除前缀0
        while (i < q.size()) {
            res *= 10;
            res += q[i];
            i ++ ;
        }
        res *= b ? -1 : 1;
        if (res > INT32_MAX || res < INT32_MIN) return 0;

        return res;
    }
};