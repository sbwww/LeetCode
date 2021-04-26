/*
 * @lc app=leetcode.cn id=1814 lang=cpp
 *
 * [1814] 统计一个数组中好对子的数目
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    map<int, int> m;
    int MOD = 1e9 + 7;
    int rev(int num) {
        int tmp = num;
        int ans = 0;
        while (tmp) {
            ans = ans * 10 + tmp % 10;
            tmp /= 10;
        }
        return ans;
    }
    int C(unsigned long long n) {
        return ((unsigned long long)n * (unsigned long long)(n - 1) /
                (unsigned long long)2) %
               (unsigned long long)MOD;
    }
    int countNicePairs(vector<int> &nums) {
        cout << nums.size() << endl;
        int ans = 0;
        for (auto num : nums) {
            int diff = num - rev(num);
            if (m.count(diff) == 0) {
                m[diff] = 1;
            } else {
                m[diff] += 1;
            }
        }
        for (auto i : m) {
            cout << i.first << " " << i.second << endl;
            ans = (ans + C(i.second)) % MOD;
        }
        return (int)(ans % MOD);
    }
};
// @lc code=end
