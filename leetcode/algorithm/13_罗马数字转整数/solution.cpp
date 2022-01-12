#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0, i = 0, j = 1;

        while (i < s.size()) {
            if (j < s.size() && mp[s[i]] < mp[s[j]]) {
                res += mp[s[j]] - mp[s[i]];
                i += 2, j += 2;
            } else {
                res += mp[s[i]];
                i ++, j ++;
            }
        }

        return res;
    }
};