class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].emplace_back(i);
        }
        int ans = 0;
        for (auto &[_, vec] : pos) {
            /* 缩小窗口，直到不同元素数量小于等于 k */
            for (int i = 0, j = 0; i < vec.size(); i++) {
                while (vec[i] - vec[j] - (i - j) > k) {
                    j++;
                }
                ans = max(ans, i - j + 1);
            }
        }
        return ans;
    }
};



class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> numFreq;
        int n = nums.size();
        int ans = 0;
        /* statistic the frequence */
        for (int i = 0; i < n; i++) {
            numFreq[nums[i]].push_back(i);
        }
        
        /* compare the longest length of every nums */
        for (const auto& [_, seq] : numFreq) {
            if (seq.size() <= ans) {
                continue;
            }
            
            int length = getLen(seq, k);
            ans = max(ans, length);
        }
        
        return ans;
    }
    
    int getLen(const vector<int>& seq, const int k) {
        int len = 0;
        int n = seq.size();
        
        for (int i = 0; i < n; i++) {
            int deleteCnt = 0;
            int j;
            for (j = i + 1; j < n; j++) {
                deleteCnt += seq[j] - seq[j - 1] - 1;
                if (deleteCnt > k) {
                    break;
                }
            }
            len = max(len, j - i);  
        }
        return len;
    }
};




class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int deleteCnt = 0;
            int equalCnt = 1;
            int value = nums[i];
            for (int j = i + 1; j < n; j++) {
                /* check if the value is equal the given value. */
                if (value != nums[j]) {
                    ++deleteCnt;
                } else {
                    ++equalCnt;
                }

                if (deleteCnt > k) {
                    break;
                }
            }
            ans = max(ans, equalCnt);
        }
        
        return ans;
    }
};