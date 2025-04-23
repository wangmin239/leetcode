?* Original Solution */
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> digitSum;
        const int mod = 10;
        
        for (int i = 1; i <= n; i++) {
            int digit = i;
            int sum = 0;
            while (digit) {
                sum += digit % mod;
                digit /= mod;
            }
            
            ++digitSum[sum];
        }
        
        int maxSize = 0;
        int ans = 0;
        for (auto [_, cnt] : digitSum) {
            if (cnt > maxSize) {
                ans = 1;
                maxSize = cnt;
            } else if (cnt == maxSize) {
                ++ans;
            }     
        }
        

        
        return ans;
    }
};

/* Official Solution */
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> hashMap;
        int maxValue = 0;
        for (int i = 1; i <= n; ++i) {
            int key = 0, i0 = i;
            while (i0) {
                key += i0 % 10;
                i0 /= 10;
            }
            ++hashMap[key];
            maxValue = max(maxValue, hashMap[key]);
        }
        int count = 0;
        for (auto& kvpair: hashMap) {
            if (kvpair.second == maxValue) {
                ++count;
            }
        }
        return count;
    }
};
