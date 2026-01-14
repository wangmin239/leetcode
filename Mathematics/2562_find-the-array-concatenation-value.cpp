class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int left = 0;
        int right = nums.size() - 1;
        
        function<int(int, int)> join = [](int high, int low) {
            int bakVal = low;
            while (low != 0) {
                high *= 10;
                low /= 10;
            }
            return high + bakVal;
        };
        
        while (left < right) {
            ans += join(nums[left++], nums[right--]);
        }
        
        if (left == right) {
            ans += nums[left];
        }
        
        return ans;
    }
};


class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0, j = nums.size() - 1; i <= j; i++, j--) {
            if (i != j) {
                ans += stoi(to_string(nums[i]) + to_string(nums[j]));
            } else {
                ans += nums[i];
            }
        }
        return ans;
    }
};
