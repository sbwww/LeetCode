/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> data_s;
    stack<int> min_s;
    MinStack() {

    }
    
    void push(int x) {
        data_s.push(x);
        if(min_s.empty()){
            min_s.push(x);
            return;
        }
        if(x<min_s.top())
            min_s.push(x);
        else
            min_s.push(min_s.top());
    }
    
    void pop() {
        min_s.pop();
        data_s.pop();
    }
    
    int top() {
        return data_s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

