#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> mp;

    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(target - nums[i]))
                return vector<int>{i, mp[target - nums[i]]};
            else
                mp[nums[i]] = i;
        }
        return {};
    }
};
