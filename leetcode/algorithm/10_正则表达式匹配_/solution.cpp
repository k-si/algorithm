#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

    bool isMatch(string s, string p) {
        int sl = s.size(), sp = p.size();

        // dp[i][j] = true : s第1个到第i个 可以和 p第1个到第j个 匹配
        bool dp[sl + 1][sp + 1];
        for (int i = 0; i <= sl; i++)
            for (int j = 0; j <= sp; j++)
                dp[i][j] = false;

        // base case
        // 1. sl = sp = 0
        dp[0][0] = true;
        // 2. sl = 0
        for (int i = 1; i <= sp; i++)
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        // 3. sp = 0

        for (int i = 1; i <= sl; i++) {
            for (int j = 1; j <= sp; j++) {
                // 1. p[j-1] = 字母
                // 1.1 s[i-1] != p[j-1]
                // if (s[i - 1] != p[i - 1]) dp[i][j] = false;

                // 1.2 s[i-1] == p[j-1]
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
                // 3. p[j - 1] = *
                else if (p[j - 1] == '*') {
                    // 3.1 s[i - 1] == p[i - 2] p[j-1]出现0次、n次
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    // 3.2 s[i - 1] != p[i - 2] p[j-1]出现0次
                    else dp[i][j] = dp[i][j - 2];
                }
            }
        }
        return dp[sl][sp];
    }
};