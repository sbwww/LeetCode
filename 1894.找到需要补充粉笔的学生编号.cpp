/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */

// @lc code=start
class Solution {
  public:
    int chalkReplacer(vector<int> &chalk, int k) {
        int n = chalk.size();

        if (chalk[0] > k)
            return 0;

        for (int i = 1; i < n; ++i) {
            chalk[i] += chalk[i - 1];
            if (chalk[i] > k)
                return i;
        }

        k %= chalk.back();

        return upper_bound(chalk.begin(), chalk.end(), k) - chalk.begin();
    }
};
// @lc code=end
