/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 */

// @lc code=start
class Solution {
  public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        map<int, int> cnt;
        for (auto &i : hand)
            ++cnt[i];

        int cnt_size = cnt.size();
        while (cnt_size > 0) {
            int start = cnt.begin()->first;
            for (int i = 0; i < groupSize; ++i) {
                int idx = start + i;
                if (cnt[idx] == 0)
                    return false;
                if (--cnt[idx] == 0) {
                    cnt.erase(idx);
                    --cnt_size;
                }
            }
        }

        return true;
    }
};
// @lc code=end
