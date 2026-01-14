class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int cnt = 0;
            for (int num: nums) {
                if ((num >> i) & 1) {
                    ++cnt;
                }
            }
            if (cnt >= k) {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        const int size = 32;
        int cntArr[size] = {0};
        
        auto getCnt = [](int val, int* cntArr) {
            for (int i = 0; i < size; i++) {
                if (val & (0x1 << i)) {
                    ++cntArr[i];
                }
            }
        };
        
        for (int num : nums) {
            getCnt(num, cntArr);
        }
        
        int kor = 0;
        
        for (int i = 0; i < size; i++) {
            if (cntArr[i] >= k) {
                kor |= 0x1 << i;
            }
        }
        return kor;
    }
};