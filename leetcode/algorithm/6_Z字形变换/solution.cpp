#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

const int N = 1000 + 10;

class Solution {
public:

    string convert(string s, int numRows) {
        char q[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                q[i][j] = ' ';

        string res = "";

        int i = 0, row = 0, col = 0;
        while (i < s.size()) {
            while (i < s.size() && row < numRows) {
                q[row][col] = s[i];
                i++;
                row++;
            }
            row -= numRows > 1 ? 2 : 1; // 特殊注意numRows为1的情况
            col++;
            while (i < s.size() && row >= 1) {
                q[row][col] = s[i];
                i++;
                row--;
                col++;
            }
        }

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < N; j++) {
                q[i][j] == ' ' ? res += "" : res += q[i][j];
            }
        }

        return res;
    }
};