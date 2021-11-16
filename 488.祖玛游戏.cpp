/*
 * @lc app=leetcode.cn id=488 lang=cpp
 *
 * [488] 祖玛游戏
 */

// @lc code=start
class Solution {
  public:
    const int INF = 0x3f3f3f3f;
    string hand;
    int hand_len;
    unordered_map<string, int> mp;
    int findMinStep(string board, string hand) {
        this->hand = hand;
        this->hand_len = hand.length();
        int ans = dfs(board, 1 << hand_len);
        return ans == INF ? -1 : ans;
    }

    int dfs(string board, int cur) {
        if (board.size() == 0)
            return 0;
        if (mp.find(board) != mp.end())
            return mp[board];
        int ans = INF;
        int n = board.size();
        for (int i = 0; i < hand_len; ++i) {
            if (((cur >> i) & 1) == 1)
                continue;
            int next = (1 << i) | cur;
            for (int j = 0; j <= n; ++j) {
                bool flag = false;
                if (j > 0 && j < n && board[j] == board[j - 1] &&
                    board[j - 1] != hand[i])
                    flag = true;
                if (j < n && board[j] == hand[i])
                    flag = true;
                if (!flag)
                    continue;
                string s = board.substr(0, j) + hand.substr(i, i + 1);
                cout << board.substr(0, j) << " " << hand.substr(i, i + 1)
                     << " " << s << endl;
                if (j != n)
                    s += board.substr(j);
                int k = j;
                while (0 <= k && k < s.size()) {
                    char c = s[k];
                    int left = k;
                    int right = k;
                    while (left >= 0 && s[left] == c)
                        --left;
                    while (right < s.size() && s[right] == c)
                        ++right;
                    if (right - left - 1 >= 3) {
                        s.erase(left + 1, right);
                        k = 1 >= 0 ? 1 : right;
                    } else {
                        break;
                    }
                }
                ans = min(ans, dfs(s, next) + 1);
            }
        }
        mp[board] = ans;
        return ans;
    }
};
/*
""WWRRBBWW"\n"WRBRW""
*/
// @lc code=end
