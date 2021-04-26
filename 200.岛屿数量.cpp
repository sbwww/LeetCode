/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
template <class T> class UnionFind {
  private:
    vector<int> parent;
    vector<int> rank;
    int count;

  public:
    UnionFind(vector<vector<T>> &grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                } else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);

        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty])
                swap(rootx, rooty);

            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty])
                rank[rootx] += 1;

            --count;
        }
    }

    int getCount() const { return count; }
};

class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        int row = grid.size();
        if (!row)
            return 0;
        int col = grid[0].size();

        UnionFind<char> uf(grid);
        int num_islands = 0;
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r - 1][c] == '1')
                        uf.unite(r * col + c, (r - 1) * col + c);
                    if (r + 1 < row && grid[r + 1][c] == '1')
                        uf.unite(r * col + c, (r + 1) * col + c);
                    if (c - 1 >= 0 && grid[r][c - 1] == '1')
                        uf.unite(r * col + c, r * col + c - 1);
                    if (c + 1 < col && grid[r][c + 1] == '1')
                        uf.unite(r * col + c, r * col + c + 1);
                }
            }
        }
        return uf.getCount();
    }
};
// @lc code=end
