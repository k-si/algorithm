#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

typedef pair<string, int> PSI;

class Solution {
public:
    string intToRoman(int num) {
        string res = "";

        vector<PSI> v{
            {"I", 1},
            {"IV", 4},
            {"V", 5},
            {"IX", 9},
            {"X", 10},
            {"XL", 40},
            {"L", 50},
            {"XC", 90},
            {"C", 100},
            {"CD", 400},
            {"D", 500},
            {"CM", 900},
            {"M", 1000}
        };

        for (int i = v.size() - 1; i >= 0; i -- ) {
            int r = num / v[i].second;
            while (r -- ) res += v[i].first;
            num = num % v[i].second;
        }

        return res;
    }
};