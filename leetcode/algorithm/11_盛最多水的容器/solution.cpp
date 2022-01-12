#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, res = 0;

        res = max(res, (j - i) * min(height[i], height[j]));
        while (i < j) {
            if (height[i] <= height[j]) i ++;
            else j -- ;
            res = max(res, (j - i) * min(height[i], height[j]));
        }

        return res;
    }
};