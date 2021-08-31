/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
  public:
    int compress(vector<char> &chars) {
        int n = chars.size();
        int write = 0;
        int left = 0;
        for (int read = 0; read < n; ++read) {
            if (read == n - 1 ||
                chars[read] != chars[read + 1]) { // 判断 到达结尾 或 出现不同
                chars[write++] = chars[read];
                int num = read - left + 1; // 长度
                if (num > 1) {
                    int anchor = write;
                    while (num > 0) {
                        chars[write++] = num % 10 + '0';
                        num /= 10;
                    }
                    reverse(&chars[anchor], &chars[write]);
                }
                left = read + 1;
            }
        }
        return write;
    }
};
// @lc code=end
