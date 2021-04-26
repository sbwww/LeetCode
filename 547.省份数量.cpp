/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
    vector<int> parent;

  public:
    int _find(int i) {
        if (parent[i] != i)
            parent[i] = _find(parent[i]);
        return parent[i];
    }

    void _union(int i, int j) { parent[_find(i)] = _find(j); }

    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        parent = vector<int>(n, 0);

        for (int i = 0; i < n; ++i)
            parent[i] = i;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (isConnected[i][j])
                    _union(i, j);

        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (parent[i] == i)
                ++cnt;

        return cnt;
    }
};
// @lc code=end
