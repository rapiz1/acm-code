#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
// Definition for a Node.
class Node {
 public:
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

class Solution {
  Node* lastNode(Node* p) {
    while (p->next) p = p->next;
    return p;
  }

 public:
  Node* flatten(Node* head) {
    if (!head) return head;
    Node* ln = head;
    Node* savedNext = head->next;
    if (head->child) {
      auto child = flatten(head->child);
      head->next = child;
      head->next->prev = head;
      head->child = nullptr;
      ln = lastNode(child);
    }
    ln->next = flatten(savedNext);
    if (ln->next) ln->next->prev = ln;
    return head;
  }
};
// @lc code=end
