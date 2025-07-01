/* Original Solution 1 */
class Solution {
public:
    int possibleStringCount(string word) {
        int len = word.length();
        int groups = 0;
        int ans = 0;
        
        for (int left = 0, right = 1; right < len; right++) {
            while (right < len && word[right] == word[left]){
                ++right;
            }
            
            int cnt = right - left;
            if (cnt > 1) {
                ++groups;
                ans += cnt;
            }
            left = right;
        }
        
        return ans - groups + 1;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size(), ans = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i - 1] == word[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
