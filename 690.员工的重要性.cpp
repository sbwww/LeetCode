/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    int MAXN = 2000 + 1;

    vector<int> parent = vector<int>(MAXN+1, 0);
    vector<int> val = vector<int>(MAXN+1, 0);

  public:
    int _find(int i) {
        if (parent[i] != i)
            parent[i] = _find(parent[i]);
        return parent[i];
    }

    void _union(int i, int j) { parent[_find(j)] = _find(i); }

    int getImportance(vector<Employee *> employees, int id) {
        int n = employees.size();
        int ans = 0;

        for (int i = 0; i < MAXN; ++i) {
            parent[i] = i;
        }

        for (auto empl : employees) {
            val[empl->id] = empl->importance;
            for (auto sub_id : empl->subordinates) {
                if (sub_id != id) {
                    _union(empl->id, sub_id);
                }
            }
        }

        for (int i = 1; i < MAXN; ++i) {
            if (_find(i) == id)
                ans += val[i];
        }
        return ans;
    }
};
// @lc code=end
