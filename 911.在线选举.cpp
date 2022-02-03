/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

// @lc code=start
class TopVotedCandidate {
  public:
    vector<int> tops;
    vector<int> times;

    TopVotedCandidate(vector<int> &persons, vector<int> &times) {
        unordered_map<int, int> voteCounts;
        voteCounts[-1] = -1;
        int top = -1;
        for (auto &p : persons) {
            ++voteCounts[p];
            if (voteCounts[p] >= voteCounts[top])
                top = p;

            tops.emplace_back(top);
        }
        this->times = times;
    }

    int q(int t) {
        int pos =
            upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return tops[pos];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end
