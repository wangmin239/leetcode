/* Original Solution 1*/
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> differences;
        
        for (int value : nums) {
            differences.insert(value);
        }
        
        int total = differences.size();
        int cnt = 0;
        
        unordered_map<int, int> cur;
        for (int left = 0, right = 0; right < n; right++) {
            int value = nums[right];
            ++cur[value];
            
            if (cur.size() != total) {
                continue;
            }

            
            while (left <= right && cur.size() == total) {
                cnt += n - right;
                value = nums[left++];
                --cur[value];
                if (cur[value] == 0) {
                    cur.erase(value);
                }
            }
        }
        
        return cnt;
    }
};



/* Original Solution 2*/
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxValue = *max_element(nums.begin(), nums.end());
        int size = sizeof(int) / sizeof(char) * 8; /* one integer value has 32 bits */
        int ids = maxValue / size + 1;
        unique_ptr<int[]> bits(new int [ids] {0});

        /* convert every number into bit */
        for (int value : nums) {
            int id = value / size;
            int mod = value % size;
            bits[id] |= 0x1 << mod;
        }

        /* Initialize the array used to store the frequence of every number */
        unique_ptr<int[]> freq(new int [maxValue + 1] {0});
        unique_ptr<int[]> digits(new int [ids] {0});
        int cnt = 0;
        auto isSame = [ids](const auto& originBits, const auto& curBits) {
            for (int i = 0; i < ids; i++) {
                if (originBits[i] != curBits[i]) {
                    return false;
                }
            }
            return true;
        };
        
        /* sliding window */
        for (int left = 0, right = 0; right < n; right++) {
            int value = nums[right];
            int id = value / size;
            int mod = value % size;

            freq[value]++;
            digits[id] |= 0x1 << mod;


            while (left <= right && isSame(bits, digits)) {
                cnt += n - right;
                value = nums[left++];
                --freq[value];
                if (freq[value] == 0) {
                    id = value / size;
                    mod = value % size;
                    digits[id] &= ~(0x1 << mod);
                }
            }
        }

        return cnt;
    }
};

/* Official Solution */
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> cnt;
        int n = nums.size();
        int right = 0;
        unordered_set<int> distinct(nums.begin(), nums.end());
        int distinct_count = distinct.size();
        
        for (int left = 0; left < n; left++) {
            if (left > 0) {
                int remove = nums[left - 1];
                cnt[remove]--;
                if (cnt[remove] == 0) {
                    cnt.erase(remove);
                }
            }
            while (right < n && cnt.size() < distinct_count) {
                int add = nums[right];
                cnt[add]++;
                right++;
            }
            if (cnt.size() == distinct_count) {
                res += (n - right + 1);
            }
        }
        return res;
    }
};
