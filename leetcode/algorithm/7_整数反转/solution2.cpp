#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long res = 0;

        for (int i = 0; x != 0; i++) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        if (res > INT32_MAX | res < INT32_MIN) return 0;

        return res;
    }
};
