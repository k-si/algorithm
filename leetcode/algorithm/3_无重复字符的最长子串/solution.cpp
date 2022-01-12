#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> mp;

    int lengthOfLongestSubstring(string s) {
        int res = 0;

        for (int i = 0, j = 0; i < s.length(); i++) {
            mp[s[i]]++;
            while (mp[s[i]] > 1) {
                mp[s[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }

        return res;
    }
};