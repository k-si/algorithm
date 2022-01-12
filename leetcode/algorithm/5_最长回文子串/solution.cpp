#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    void center_expand(string s, int l, int r, int &max, int &left, int &right) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        l++;
        r--;
        if (r - l + 1 > max) {
            max = r - l + 1;
            left = l;
            right = r;
        }
    }

    string longestPalindrome(string s) {
        int max = 0, left = 0, right = 0;

        for (int i = 0; i < s.length(); i++) {
            center_expand(s, i, i, max, left, right);
            center_expand(s, i, i + 1, max, left, right);
        }
        return s.substr(left, max);
    }
};