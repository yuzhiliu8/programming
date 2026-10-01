#include <bits/stdc++.h>
using namespace std;
/*

[1, 2, 4, 6]
prefix product array
[1, 2, 8, 24]

postfix product array
[48, 48, 24, 6]

END:
[48, 24, 12, 8]
*/

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> prefix(nums.size());
    prefix[0] = nums[0];
    vector<int> postfix(nums.size());
    postfix[nums.size() - 1] = nums[nums.size() - 1];

    for (int i = 1; i < nums.size(); ++i) {
      prefix[i] = prefix[i - 1] * nums[i];
    }

    for (int i = nums.size() - 2; i > -1; --i) {
      postfix[i] = postfix[i + 1] * nums[i];
    }

    vector<int> res(nums.size());

    res[0] = postfix[1];
    res[nums.size() - 1] = prefix[nums.size() - 2];

    for (int i = 1; i < nums.size() - 1; ++i) {
      res[i] = postfix[i + 1] * prefix[i - 1];
    }
    return res;
  }
};
