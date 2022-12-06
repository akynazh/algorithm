#include <bits/stdc++.h>
using namespace std;
class Solution {};
class CQueue {
   private:
    stack<int> ins;
    stack<int> outs;

   public:
    CQueue() {}

    void appendTail(int value) { ins.push(value); }

    int deleteHead() {
        int t = -1;
        if (outs.empty())
            while (!ins.empty()) {
                outs.push(ins.top());
                ins.pop();
            }
        if (!outs.empty()) {
            t = outs.top();
            outs.pop();
        }
        return t;
    }
};
int main() {
    Solution solution;

    return 0;
}