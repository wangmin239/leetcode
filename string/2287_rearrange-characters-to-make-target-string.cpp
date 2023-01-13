class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> sCounts, targetCounts;
        int n = s.size(), m = target.size();
        for (int i = 0; i < m; i++) {
            targetCounts[target[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (targetCounts.count(s[i])) {
                sCounts[s[i]]++;
            }
        }
        int ans = INT_MAX;
        for (auto &[c, count] : targetCounts) {
            int totalCount = sCounts[c];
            ans = min(ans, totalCount / count);
            if (ans == 0) {
                return 0;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        const int chCnt = 26;
        array<int, chCnt) sPtr;
        array<int, chCnt) tPtr;
        
        auto getCnt = [](const string &str, int *ptr) {
            for (char ch : str) {
                int index = static_cast<int>(ch - 'a');
                ptr[index]++;
            }
        };
        getCnt(s, sPtr);
        getCnt(target, tPtr);
        int ans = 0;
        while (true) {
            for (int i = 0; i < chCnt; i++) {
                if (tPtr[i] == 0) {
                    continue;
                }
                if (tPtr[i] > sPtr[i]) {
                    return ans;
                } else {
                    sPtr[i] -= tPtr[i];
                }
            }
            ans++;
        }
        return ans;
    }
    
};



class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        const int chCnt = 26;
        unique_ptr<int []> sPtr(new int [chCnt]);
        unique_ptr<int []> tPtr(new int [chCnt]);
        
        auto getCnt = [&](const string &str, int *ptr) {
            for (int i = 0; i < chCnt; i++) {
                ptr[i] = 0;
            }
            
            for (char ch : str) {
                int index = static_cast<int>(ch - 'a');
                ptr[index]++;
            }
        };
        getCnt(s, sPtr.get());
        getCnt(target, tPtr.get());

        int ans = INT_MAX;
        for (int i = 0; i < chCnt; i++) {
            if (tPtr[i] == 0) {
                continue;
            }
            ans = min(ans, sPtr[i] / tPtr[i]);
            if (ans == 0) {
                return ans;
            }
        }

        return ans;
    }
    
};