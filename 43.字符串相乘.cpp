/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        if (num1 == "1")
            return num2;
        if (num2 == "1")
            return num1;

        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> ansNum(len1 + len2);

        int i, j;
        for (i = len1 - 1; i >= 0; --i) {
            int x = num1[i] - '0';
            for (j = len2 - 1; j >= 0; --j) {
                int y = num2[j] - '0';
                ansNum[i + j + 1] += x * y;
            }
        }
        for (i = len1 + len2 - 1; i > 0; --i) {
            ansNum[i - 1] += ansNum[i] / 10;
            ansNum[i] %= 10;
        }

        string ansString;
        int index = (ansNum[0] == 0 ? 1 : 0);
        int sumLen = len1 + len2;
        for (; index < sumLen; ++index)
            ansString.push_back(ansNum[index] + '0');

        return ansString;
    }
};
// @lc code=end
