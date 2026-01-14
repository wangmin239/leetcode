class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        if (len1 < len2) {
            return 0LL;
        }
        
        const int chars = 26;
        vector<int> wordCh(chars, 0);
        long long cnt = 0;
        
        for (char ch : word2) {
            ++wordCh[ch - 'a'];
        }
        
        
        auto isMatch = [](vector<int>& diffCh) {
            for (int val : diffCh) {
                if (val > 0) {
                    return false;
                }
            }
            
            return true;
        };
        
        vector<int> diffCh(wordCh); 

        /* double pointer notes one sliping window */
        for (int left = 0, right = 0; right < len1; right++) {
            --diffCh[word1[right] - 'a'];
            while (isMatch(diffCh) == true) {
                cnt += len1 - right;

                
                int index = word1[left++] - 'a';
                if (wordCh[index] > 0) {
                    ++diffCh[index];
                }
            }      
        }

        return cnt;
    }
};




class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> count(26, 0);
        for (auto c : word2) {
            count[c - 'a']++;
        }

        int n = word1.size();
        vector<vector<int>> pre_count(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; i++) {
            pre_count[i].assign(pre_count[i - 1].begin(), pre_count[i - 1].end());
            pre_count[i][word1[i - 1] - 'a']++;
        }

        auto get = [&](int l, int r) {
            int border = l;
            while (l < r) {
                int m = l + r >> 1;
                bool f = true;
                for (int i = 0; i < 26; i++) {
                    if (pre_count[m][i] - pre_count[border - 1][i] < count[i]) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            return l;
        };

        long long res = 0;
        for (int l = 1; l <= n; l++) {
            int r = get(l, n + 1);
            res += n - r + 1;
        }
        return res;
    }
};



class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> diff(26, 0);
        for (auto c : word2) {
            diff[c - 'a']--;
        }

        long long res = 0;
        int cnt = count_if(diff.begin(), diff.end(), [](int c) { return c < 0; });
        auto update = [&](int c, int add) {
            diff[c] += add;
            if (add == 1 && diff[c] == 0) {
                // 表明 diff[c] 由 -1 变为 0
                cnt--;
            } else if (add == -1 && diff[c] == -1) {
                // 表明 diff[c] 由 0 变为 -1
                cnt++;
            }
        };

        for (int l = 0, r = 0; l < word1.size(); l++) {
            while (r < word1.size() && cnt > 0) {
                update(word1[r] - 'a', 1);
                r++;
            }
            if (cnt == 0) {
                res += word1.size() - r + 1;
            }
            update(word1[l] - 'a', -1);
        }
        return res;
    }
};
