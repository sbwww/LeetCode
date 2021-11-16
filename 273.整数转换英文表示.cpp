/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution {
  public:
    vector<string> word_0s = {"Zero", "One", "Two",   "Three", "Four",
                              "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> word_10s = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                               "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                               "Eighteen", "Nineteen"};
    vector<string> word_10x = {"",      "Ten",   "Twenty",  "Thirty", "Forty",
                               "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> word_1000x = {"", "Thousand", "Million", "Billion"};
    int Thousand = 1000;
    int Million = Thousand * 1000;
    int Billion = Million * 1000;

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        string ans;

        int curNum = num / Billion;
        if (curNum != 0) {
            num %= Billion;
            string curr;
            recursion(curr, curNum);
            curr = curr + "Billion ";
            ans = ans + curr;
        }
        curNum = num / Million;
        if (curNum != 0) {
            num %= Million;
            string curr;
            recursion(curr, curNum);
            curr = curr + "Million ";
            ans = ans + curr;
        }
        curNum = num / Thousand;
        if (curNum != 0) {
            num %= Thousand;
            string curr;
            recursion(curr, curNum);
            curr = curr + "Thousand ";
            ans = ans + curr;
        }
        curNum = num / 1;
        if (curNum != 0) {
            num %= 1;
            string curr;
            recursion(curr, curNum);
            curr = curr + "";
            ans = ans + curr;
        }

        if (ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }

    void recursion(string &curr, int num) {
        if (num == 0) {
            return;
        } else if (num < 10) {
            curr = curr + word_0s[num] + " ";
        } else if (num < 20) {
            curr = curr + word_10s[num - 10] + " ";
        } else if (num < 100) {
            curr = curr + word_10x[num / 10] + " ";
            recursion(curr, num % 10);
        } else {
            curr = curr + word_0s[num / 100] + " Hundred ";
            recursion(curr, num % 100);
        }
    }
};
// @lc code=end
