class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_set<char> uniqStr;
        int ans = 0;
        
        for (int left = 0, right = 0; right < len; ++right) {
            char curCh = s[right];
            
            while (left < right && uniqStr.count(curCh) > 0) {
                char prevCh = s[left++];
                uniqStr.erase(prevCh);
            }
            
            uniqStr.insert(curCh);
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};