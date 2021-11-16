/*
 * @lc app=leetcode.cn id=284 lang=cpp
 *
 * [284] 顶端迭代器
 */

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {

    int nextElement;
    bool flag;

  public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        flag = Iterator::hasNext();
        if (flag)
            nextElement = Iterator::next();
    }

    int peek() { return nextElement; }

    int next() {
        int ret = nextElement;
        flag = Iterator::hasNext();
        if (flag)
            nextElement = Iterator::next();

        return ret;
    }

    bool hasNext() const { return flag; }
};
// @lc code=end
