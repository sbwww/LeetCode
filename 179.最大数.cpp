/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
// 比较拼接后的大小
// 4, 45 应当拼接为 454
int cmp(int x, int y) {
    if (x < 1)
        return 0;
    if (y < 1)
        return 1;
    int x_len = log10(x) + 1;
    int y_len = log10(y) + 1;
    return x * pow(10, y_len) + y > y * pow(10, x_len) + x;
}
class Solution {
  public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0)
            return "0";
        string ans = "";
        for (auto i : nums)
            ans += to_string(i);

        return ans;
    }
};
// @lc code=end
