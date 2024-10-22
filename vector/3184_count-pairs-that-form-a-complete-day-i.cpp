class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        const int hoursInDay = 24;
        int ans = 0;
        int len = hours.size();

        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if ((hours[i] + hours[j]) % hoursInDay == 0) {
                    ++ans;
                }
            }
        }
        
        return ans ;
    }
};



class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        const int hoursInDay = 24;
        unordered_map<int, int> matchHour;
        int ans = 0;

        for (int hour : hours) {
            int mod = hour % hoursInDay;
            int match = mod == 0 ? 0 : hoursInDay - mod;
            
            if (matchHour.count(match)) {
                ans += matchHour[match];
            }
            ++matchHour[mod];
        }
        
        return ans ;
    }
};





class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
       const int hoursInDay = 24;
       unique_ptr<int[]> uniq = make_unique<int[]>(hoursInDay);
       int* ptr = uniq.get();
       
       fill(ptr, ptr + hoursInDay, 0);
       for (int hour : hours) {
           ++ptr[hour % hoursInDay];
       }
       
       int ans = 0;
       for (int left = 1, right = hoursInDay - 1; left < right; left++, right--) {
           ans += ptr[left] * ptr[right];
       }
       
       ans += ptr[0] * (ptr[0] - 1) / 2;
       ans += ptr[12] * (ptr[12] - 1) / 2;
       
       return ans;
    }
};