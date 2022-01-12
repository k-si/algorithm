#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // 去除前导空格
        int i = 0;
        while (s[i] == ' ') i ++ ;
        if (i > s.size() - 1) return 0;

        // 判断正负号,false为负数，true为正数
        bool b = true;
        if (s[i] == '-') {
            b = false;
            i ++ ;
        }
        else if (s[i] == '+') {
            b = true;
            i ++ ;
        }

        // 去除前导0
        while (i < s.size()) {
            // 不属于数字直接返回0，不是0直接break
            if (s[i] < '0' || s[i] > '9') return 0;
            if (s[i] == '0') i ++ ;
            else break;
        }

        // 读取剩余字符，直到字符末尾，或者遇到非数字字符
        vector<int> q;
        while (i < s.size()) {
            if (s[i] < '0' || s[i] > '9') break;
            q.push_back(s[i] - '0');
            i ++ ;
        }

        // 整数大小范围判断，防止出现比long long还大的数
        if (q.size() > 10) return b ? INT32_MAX : INT32_MIN;

        // 遍历vector生成整数
        long long res = 0;
        for (int j = 0; j < q.size(); j ++ ) {
            res *= 10;
            res += q[j];
        }
        res *= b ? 1 : -1;

        // 对结果大小范围判断
        if (res > INT32_MAX) return INT32_MAX;
        if (res < INT32_MIN) return INT32_MIN;

        return res;
    }
};