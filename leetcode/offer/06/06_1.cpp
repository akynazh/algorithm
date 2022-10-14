#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  vector<int> reversePrint(ListNode* head) {
      if (!head) return {};
      vector<int> v = reversePrint(head->next);
      v.push_back(head->val);
      return v;
  }
};
int main() {
  ListNode* head = new ListNode(10);
  ListNode* tmp = head;
  head->next = new ListNode(11);
  head = head->next;
  head->next = new ListNode(14);
  Solution solution;
  vector<int> v = solution.reversePrint(tmp);
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  return 0;
}