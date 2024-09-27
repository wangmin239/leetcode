class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cnt(3, 0);
        int len = s.size();
        int ans = len;
        for (int i = 0; i < len; i++) {
            cnt[s[i] - 'a']++;
        }
        if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
            ans = min(ans, len);
        } else {
            return -1;
        }

        int l = 0;
        for (int r = 0; r < len; r++) {
            cnt[s[r] - 'a']--;
            while (l < r && (cnt[0] < k || cnt[1] < k || cnt[2] < k)) {
                cnt[s[l] - 'a']++;
                l++;
            }
            if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
                ans = min(ans, len - (r - l + 1));
            }
        }

        return ans;
    }
};




class Solution {
public:
    int takeCharacters(string s, int k) {
        int len = s.length();
        const int limit = 3;

        int total[limit] = {0, 0, 0};
        
        for (int i = 0; i < len; i++ ) {
            int id = s[i] - 'a';
            total[id]++;
        }
        
        for (int i = 0; i < limit; i++) {
            if (total[i] < k) {
                return -1;
            }
        }
        
        auto dfs = [&](int start, int end, int cntA, int cntB, int cntC, auto&& innerDfs) {
            if (cntA >= k && cntB >= k && cntC >= k) {
                return 0;
            }
            

            int preA = static_cast<int>(s[start] =='a');
            int preB = static_cast<int>(s[start] =='b');
            int preC = static_cast<int>(s[start] =='c');
            int sufA = static_cast<int>(s[end] =='a');
            int sufB = static_cast<int>(s[end] =='b');
            int sufC = static_cast<int>(s[end] =='c');
            
            return 1 + min(innerDfs(start + 1, end, cntA + preA, cntB + preB, cntC + preC, innerDfs), innerDfs(start, end - 1, cntA + sufA, cntB + sufB, cntC + sufC, innerDfs));
        }
        
        return dfs(0, len - 1, 0, 0, 0, dfs);
    }
};

