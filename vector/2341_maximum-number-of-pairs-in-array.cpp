class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        const int size = 102;
        unique_ptr<int[]> uPtr(new int [size]);
        
        auto arr = uPtr.get();
        
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
        
        for (int val : nums) {
            arr[val + 1]++;
        }
        
        int pairCnt = 0;
        int remain = 0;
        for (int i = 1; i < size; i++) {
            int val = arr[i];
            
            remain += val % 2;
            if (val > 1) {
                pairCnt += val / 2;
            }
        }
        
        return {pairCnt, remain};
    }
};



class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for (int val : nums) {
            freq[val]++;
        }
        int remain = 0;
        int pairCnt = 0;
        for (auto [_, cnt] : freq) {
            remain += cnt % 2;
            if (cnt > 1) {
                pairCnt += cnt / 2;
            }
        }
        
        return {pairCnt, remain};
    }
};



class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        const int size = 102;
        array<int, size> arr {{0}};
        
        for (int val : nums) {
            arr[val + 1]++;
        }
        
        int pairCnt = 0;
        int remain = 0;
        for (int i = 1; i < size; i++) {
            int val = arr[i];
            
            remain += val % 2;
            if (val > 1) {
                pairCnt += val / 2;
            }
        }
        
        return {pairCnt, remain};
    }
};