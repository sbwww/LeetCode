/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
  public:
    struct cmp {
        bool operator()(const pair<string, int> a, const pair<string, int> b) {
            return a.second == b.second ? a.first < b.first
                                        : a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> cnt;
        for (auto word : words)
            ++cnt[word];

        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;

        for (auto i : cnt) {
            pq.emplace(i);
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end
