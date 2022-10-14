#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    int rem[100001] = {0};
    // unordered_map<int> dic;
    for (int i = 0; i < nums.size(); i++) {
      if (!rem[nums[i]])
        rem[nums[i]] = 1;
      else
        return nums[i];
    }
    return 0;
  }
};
int main() {
  vector<int> nums = {1, 2, 2, 3};
  Solution solution;
  int ans = solution.findRepeatNumber(nums);
  printf("%d\n", ans);
  return 0;
}
