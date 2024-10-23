class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        vector<int> cnt(24);
        for (int hour : hours) {
            ans += cnt[(24 - hour % 24) % 24];
            cnt[hour % 24]++;
        }
        return ans;
    }
};



class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        int n = hours.size();
        int hoursInDay = 24;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((hours[i] + hours[j]) % hoursInDay == 0) {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};




class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        const int hoursInDay  = 24;
        unordered_map<int, int> match;
        
        for (int hour : hours) {
            int mod = hour % hoursInDay;
            int remain = mod == 0 ? 0 : hoursInDay - mod;
            
            if (match.count(remain)) {
                ans += match[remain];
            }
            ++match[mod];
        }
        
        return ans;
    }
};







class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        const int hoursInDay  = 24;
        unique_ptr<int[]>  uniq = make_unique<int[]>(hoursInDay);
        int* match = uniq.get();
        
        fill(match, match + hoursInDay, 0);
        for (int hour : hours) {
            ++match[hour % hoursInDay];
        }
        
        for (int left = 1, right = hoursInDay - 1; left < right; left++, right--) {
            ans += 1L * match[left] * match[right];
        }
        
        ans += 1L * match[0] * (match[0] - 1) / 2;
        ans += 1L * match[12] * (match[12] - 1) / 2;
        
        return ans;
    }
};