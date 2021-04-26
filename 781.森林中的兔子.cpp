/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
class Solution {
  public:
    int numRabbits(vector<int> &answers) {
        if (answers.size() == 0)
            return 0;

        unordered_map<int, int> cnt;
        for (int num : answers)
            ++cnt[num];

        int ans = 0;
        for (auto item : cnt)
            ans += (item.second + item.first) / (item.first + 1) *
                   (item.first + 1);

        return ans;
    }
};
// @lc code=end
