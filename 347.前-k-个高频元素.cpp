/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
  public:
    struct cmp{
        bool operator()(pair<int, int> &m, pair<int, int> &n){
            return m.second < n.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> num_cnt;
        for (auto &i : nums)
            ++num_cnt[i];

        for (auto &[num, cnt] : num_cnt) {
            cout << num << " -> " << cnt << endl;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for (auto &[num, cnt] : num_cnt) {
            pq.emplace(num, cnt);
        }

        int cnt = 0;
        vector<int> ans;
        while (!pq.empty()) {
            if (cnt++ >= k)
                break;
            ans.emplace_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end
