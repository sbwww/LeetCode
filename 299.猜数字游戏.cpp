/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
  public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int A = 0;
        int B = 0;
        vector<int> cnt(10, 0);
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++A;
            } else {
                ++cnt[secret[i] - '0'];
                --cnt[guess[i] - '0'];
            }
        }
        int tmp = 0;
        for (auto &i : cnt) {
            tmp += abs(i);
        }
        B = n - A - tmp / 2;

        return to_string(A) + "A" + to_string(B) + "B";
    }
};
// @lc code=end
