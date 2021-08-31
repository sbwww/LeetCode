/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */

// @lc code=start
struct node {
    int row;
    int cnt;
    node(int r, int c) : row(r), cnt(c) {}
    friend bool operator<(const node &a, const node &b) {
        if (a.cnt == b.cnt)
            return a.row > b.row;
        return a.cnt > b.cnt;
    }
};

class Solution {
  public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        priority_queue<node> pq;
        vector<int> ans;
        int row = mat.size();
        for (int i = 0; i < row; ++i) {
            int cnt = 0;
            for (auto &j : mat[i]) {
                if (j == 0)
                    break;
                ++cnt;
            }
            pq.emplace(node(i, cnt));
        }

        int cnt = 0;
        while (!pq.empty()) {
            ans.emplace_back(pq.top().row);
            pq.pop();
            if (++cnt == k)
                break;
        }
        return ans;
    }
};
// @lc code=end
