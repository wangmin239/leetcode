class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for (int val : nums) {
            freq[val]++;
        }
        
        auto cmp = [&](const auto a, const auto b) {
            if (freq[a] < freq[b]) {
                return true;
            }
            
            if (freq[a] == freq[b]) {
                return a > b;
            }
            return false;
        };
        
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }
        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            if (cnt[a] != cnt[b]) {
                return cnt[a] < cnt[b];
            }
            return a > b;
        });
        return nums;
    }
};
