/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
class Solution {
  public:
    int numRescueBoats(vector<int> &people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());

        int left = 0;
        int right = n - 1;
        int cnt = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                ++left;
                --right;
            } else {
                --right;
            }
            ++cnt;
        }

        return cnt;
    }
};
// @lc code=end
