/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 */

// @lc code=start
class Solution {
  public:
    int n;
    int target;
    string num;
    vector<string> ans;

    void dfs(string &expr, int i, long res, long mul) {
        if (i == n) {
            if (res == target)
                ans.emplace_back(expr);
            return;
        }

        int signIndex = expr.size();
        if (i > 0)
            expr.push_back(0);

        long val = 0;
        // 枚举截取的数字长度（取多少位），注意数字可以是单个 0
        // 但不能有前导零！
        for (int j = i; j < n && (j == i || num[i] != '0'); ++j) {
            val = val * 10 + num[j] - '0';
            expr.push_back(num[j]);
            if (i == 0) { // 表达式开头不能添加符号
                dfs(expr, j + 1, val, val);
            } else { // 枚举符号
                expr[signIndex] = '+';
                dfs(expr, j + 1, res + val, val);
                expr[signIndex] = '-';
                dfs(expr, j + 1, res - val, -val);
                expr[signIndex] = '*';
                dfs(expr, j + 1, res - mul + mul * val, mul * val);
            }
        }
        expr.resize(signIndex);
    }

    vector<string> addOperators(string num, int target) {
        this->num = num;
        this->target = target;
        this->n = num.length();

        string expr = "";
        dfs(expr, 0, 0, 0);
        return ans;
    }
};
// @lc code=end
