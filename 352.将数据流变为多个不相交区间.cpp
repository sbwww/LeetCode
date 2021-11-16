/*
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 */

// @lc code=start
class SummaryRanges {
  public:
    map<int, int> intervals;
    SummaryRanges() {}

    void addNum(int val) {
        // 找到 l1 最小的且满足 l1 > val 的区间 interval_1 = [l1, r1]
        // 如果不存在这样的区间，interval_1 为尾迭代器
        auto interval_1 = intervals.upper_bound(val);
        // 找到 l0 最大的且满足 l0 <= val 的区间 interval_0 = [l0, r0]
        // 在有序集合中，interval_0 就是 interval_1 的前一个区间
        // 如果不存在这样的区间，interval_0 为尾迭代器
        auto interval_0 = intervals.end();
        if (interval_1 != intervals.begin())
            interval_0 = prev(interval_1);

        if (interval_0 != intervals.end() && interval_0->first <= val &&
            val <= interval_0->second) {
            // 情况一
            return;
        } else {
            bool left_aside = (interval_0 != intervals.end() &&
                               interval_0->second + 1 == val);
            bool right_aside =
                (interval_1 != intervals.end() && interval_1->first - 1 == val);
            if (left_aside && right_aside) {
                // 情况四
                int left = interval_0->first;
                int right = interval_1->second;
                intervals.erase(interval_0);
                intervals.erase(interval_1);
                intervals.emplace(left, right);
            } else if (left_aside) {
                // 情况二
                ++interval_0->second;
            } else if (right_aside) {
                // 情况三
                int right = interval_1->second;
                intervals.erase(interval_1);
                intervals.emplace(val, right);
            } else {
                // 情况五
                intervals.emplace(val, val);
            }
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (const auto &[left, right] : intervals)
            ans.push_back({left, right});

        return ans;
    }
};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end
