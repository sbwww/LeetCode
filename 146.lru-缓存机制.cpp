/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

struct MyListNode {
    int key, value;
    MyListNode *prev;
    MyListNode *next;
    MyListNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    MyListNode(int _key, int _value)
        : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
  private:
    unordered_map<int, MyListNode *> cache;
    MyListNode *head;
    MyListNode *tail;
    int size;
    int capacity;

  public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new MyListNode();
        tail = new MyListNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key))
            return -1;

        // 如果 key 存在，先通过哈希表定位，再移到头部
        MyListNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            MyListNode *node = new MyListNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // // 如果超出容量，删除双向链表的尾部节点
                MyListNode *removed = tail->prev;
                removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        } else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            MyListNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(MyListNode *node) { // LRU 添加在开头
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(MyListNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(MyListNode *node) { // 先删，再加到开头
        removeNode(node);
        addToHead(node);
    }

    void removeTail() { // LRU 移除在结尾
        removeNode(tail->prev);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
