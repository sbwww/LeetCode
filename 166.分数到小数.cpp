/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
    using ll = long long;

  public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        ll n = numerator;
        ll d = denominator;

        if (n == 0)
            return "0";

        // 整数
        // 负数？
        if ((n >= 0) ^ (d >= 0) == 1)
            ans += "-";

        ll a = n / d;
        if (a < 0)
            a *= -1;
        ans += to_string(a);

        if (n < 0)
            n *= -1;
        if (d < 0)
            d *= -1;

        // 小数
        n %= d;
        if (n == 0) {
            // 无小数
            return ans;
        }
        ans += ".";
        // 连除
        // 哈希表记录是否有数组第二次出现
        unordered_map<int, int> st;
        string t;
        int index = 0;
        while (n && !st.count(n)) {
            st[n] = index++;
            n *= 10;
            t.push_back((char)(n / d + '0'));
            n %= d;
        }
        if (n != 0) {
            // 说明出现了循环，此时对循环部分 [st[n], index] 加括号
            ans += t.substr(0, st[n]) + "(" + t.substr(st[n]) + ")";
        } else {
            ans += t;
        }
        return ans;
    }
};
// @lc code=end
