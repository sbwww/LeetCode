/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后K个零
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// 1000000000
class Solution {
  public:
    int find(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n;
            n /= 5;
        }
        return ans;
    }

    int preimageSizeFZF(int K) {
        if (K == 0)
            return 5;
        int left = floor(K / 5.0 * 4.0);
        int right = ceil(K / 6.0 * 5.0);
        int mid;
        while (left <= right) {
            if (left == mid) {
                if (find(left) == K)
                    return 5;
                else
                    return 0;
            }
            mid = (left + right) / 2;
            int tmp = find(mid);
            if (tmp == K) {
                return 5;
            }
            if (tmp > K) {
                right = mid - 1;
            }
            if (tmp < K) {
                left = mid + 1;
            }
        }
        return 0;
    }
};
// @lc code=end
