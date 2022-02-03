/*
 * @lc app=leetcode.cn id=1705 lang=cpp
 *
 * [1705] 吃苹果的最大数目
 */

// @lc code=start
typedef pair<int, int> PII;

class Solution {
  public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        int n = apples.size();
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        int i = 0;
        int ans = 0;
        while (i < n) {
            while (!pq.empty() && pq.top().first <= i)
                pq.pop();

            int rottenDay = i + days[i];
            int count = apples[i];
            if (count > 0)
                pq.emplace(rottenDay, count);

            if (!pq.empty()) {
                PII curr = pq.top();
                pq.pop();
                --curr.second;
                if (curr.second != 0)
                    pq.emplace(curr.first, curr.second);
                ++ans;
            }
            ++i;
        }
        while (!pq.empty()) {
            while (!pq.empty() && pq.top().first <= i)
                pq.pop();

            if (pq.empty())
                break;

            PII curr = pq.top();
            pq.pop();
            int num = min(curr.first - i, curr.second);
            ans += num;
            i += num;
        }
        return ans;
    }
};
// @lc code=end
