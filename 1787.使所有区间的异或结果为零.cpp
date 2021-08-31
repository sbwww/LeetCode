/*
 * @lc app=leetcode.cn id=1787 lang=cpp
 *
 * [1787] 使所有区间的异或结果为零
 */

// @lc code=start
class Solution {
  private:
    // x [0, 2^10)
    const int MAXX = 1 << 10;
    const int INFTY = INT_MAX / 2;

  public:
    int minChanges(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> f(MAXX, INFTY);
        f[0] = 0;

        for (int i = 0; i < k; ++i) {
            unordered_map<int, int> cnt;
            int size = 0;
            for (int j = i; j < n; j += k) {
                ++cnt[nums[j]];
                ++size;
            }

            int t2min = *min_element(f.begin(), f.end());

            vector<int> g(MAXX, t2min);

            for (int mask = 0; mask < MAXX; ++mask)
                // t1 则需要枚举 x 才能求出
                for (auto [x, countx] : cnt)
                    g[mask] = min(g[mask], f[mask ^ x] - countx);

            for (auto &i : g)
                i += size;

            f = move(g); // cast
        }

        return f[0];
    }
};
// @lc code=end
