#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int idx = 0;
        string res = "";

        while (idx < strs[0].size()) {
            char tmp = strs[0][idx];
            for (int i = 0; i < strs.size(); i++) {
                if (idx > strs[i].size() - 1) return res;
                if (tmp != strs[i][idx]) return res;
            }
            res += strs[0][idx];
            idx++;
        }

        return res;
    }
};