#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        vector<int> q;
        while (x > 0) {
            q.push_back(x % 10);
            x /= 10;
        }

        for (int i = 0, j = q.size() - 1; i < j; i ++, j -- ) {
            if (q[i] != q[j]) return false;
        }

        return true;
    }
};