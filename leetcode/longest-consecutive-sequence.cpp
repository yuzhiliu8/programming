#include <bits/stdc++.h>

using namespace std;
/*
given length of logest consecutive sequence of elements

given int x;
if x + 1 exists, then x is not the end of some sequence
go to x = x + 1 until x + 1 doesn't exist

likewise, traverse the bottom end as well, go to x = x - 1 until x - 1 doesn't
exist then, you know your final consecutive sequence for those.

keep track of all seen elements in a set to reduce re-checking
*/

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> elements(nums.begin(), nums.end());
    unordered_set<int> seen;

    int max_seq = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int cur_seq = 1;
      int x = nums[i];
      if (seen.contains(x)) {
        continue;
      }
      seen.insert(x);

      int upper = x + 1;
      while (elements.contains(upper)) {
        ++cur_seq;
        seen.insert(upper);
        ++upper;
      }

      int lower = x - 1;
      while (elements.contains(lower)) {
        ++cur_seq;
        seen.insert(lower);
        --lower;
      }

      if (cur_seq > max_seq) {
        max_seq = cur_seq;
      }
    }
    return max_seq;
  }
};
