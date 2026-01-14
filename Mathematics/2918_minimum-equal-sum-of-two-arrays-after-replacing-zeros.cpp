class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        int zeroCnt1 = 0;
        int zeroCnt2 = 0;
        
        for (int num : nums1) {
            if (num == 0) {
                zeroCnt1++;
            }
        }
        
        for (int num : nums2) {
            if (num == 0) {
                zeroCnt2++;
            }
        }
        
        
        
        if (zeroCnt1 == 0 && zeroCnt2 == 0) {
            if (sum1 == sum2) {
                return sum1;
            }
            return -1;
        }
        
        if (zeroCnt1 == 0) {
            if (sum1 < sum2 + zeroCnt2) {
                return -1;
            }
            return sum1;
        }

        if (zeroCnt2 == 0) {
            if (sum2 < sum1 + zeroCnt1) {
                return -1;
            }
            return sum2;
        }
        
        
        return max(sum1 + zeroCnt1, sum2 + zeroCnt2);
            
    }
};


class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;
        for (int i : nums1) {
            sum1 += i;
            if (i == 0) {
                sum1++;
                zero1++;
            }
        }
        for (int i : nums2) {
            sum2 += i;
            if (i == 0) {
                sum2++;
                zero2++;
            }
        }
        if (!zero1 && sum2 > sum1 || !zero2 && sum1 > sum2) {
            return -1;
        }
        return max(sum1, sum2);
    }
};
