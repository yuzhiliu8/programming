#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;  // num, freq
        int max_freq = 0;
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
            if (freq[nums[i]] > max_freq) {
                max_freq = freq[nums[i]];
            }
        }

        vector<vector<int>> vec(max_freq + 1);
        for (auto& pair : freq) {
            vec[pair.second].push_back(pair.first);
        }

        vector<int> out;
        int num = 0;
        for (int i = max_freq; i > -1; --i) {
            vector<int> freq_list = vec[i];
            for (int j = 0; j < freq_list.size(); ++j) {
                out.push_back(freq_list[j]);
                ++num;
                if (num == k) {
                    return out;
                }
            }
        }
        return out;
    }
};
