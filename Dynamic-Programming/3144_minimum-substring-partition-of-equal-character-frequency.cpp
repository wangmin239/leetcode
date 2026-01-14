class Solution {
public:
    static constexpr int inf = 0x3f3f3f3f;
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> d(n + 1, inf);
        unordered_map<char, int> occ_cnt;
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            int max_cnt = 0;
            occ_cnt.clear();
            for (int j = i; j >= 1; j--) {
                occ_cnt[s[j - 1]]++;
                max_cnt = max(max_cnt, occ_cnt[s[j - 1]]);
                if (max_cnt * occ_cnt.size() == (i - j + 1) && d[j - 1] != inf) {
                    d[i] = min(d[i], d[j - 1] + 1);
                }
            }
        }
        return d[n];
    }
};



class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int len = s.length();  
        auto checkBalance = [](int arr[], const int len) {
            int i, cnt;
            for (i = 0; i < len; i++) {
                if (arr[i] != 0) {
                    cnt = arr[i];
                    break;
                }
            }
            
            while (++i < len) {
                if (arr[i] != 0 && arr[i] != cnt) {
                    return false;
                }
            }
            
            return true;
        };
        
        function<int(int, int, const string&)> dfs = [&](int start, int end, const string& str) {
            if (start > end) {
                return 0;
            }
            
            const int limit = 26;
            int arr[limit] = {0};
            int minCnt = end - start + 1;
            
            for (int i = start; i <= end; i++) {
                ++arr[str[i] - 'a'];
            }
            
            int i = end;
            while (i >= start) {
                if (checkBalance(arr, limit) == true) {
                    minCnt = min(minCnt, 1 + dfs(i + 1, end, str));
                }
                --arr[str[i] - 'a'];
                --i;
            }
            
            return minCnt;
        };
        

        
        return dfs(0, len - 1, s);
    }
};