/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start
class MapSum {
  private:
    unordered_map<string, int> mp;
    unordered_map<string, int> prefixmap;

  public:
    MapSum() {}

    void insert(string key, int val) {
        int delta = val;
        if (mp.count(key))
            delta -= mp[key];

        mp[key] = val;
        for (int i = 1; i <= key.size(); ++i) {
            prefixmap[key.substr(0, i)] += delta;
        }
    }

    int sum(string prefix) { return prefixmap[prefix]; }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end
