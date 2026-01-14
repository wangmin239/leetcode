
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        if (len1 < len2) {
            return 0LL;
        }
        
        const int chars = 26;
        int  wordCh[chars] = {0};

        
        for (char ch : word2) {
            ++wordCh[ch - 'a'];
        }

        int num = count_if(wordCh, wordCh + chars, [](int c) {return c > 0;});
        
        
        auto update = [&num, &wordCh](int id, int incr) {
            wordCh[id] += incr;
            if (incr == -1 && wordCh[id] == 0) {
                --num;
            } else if (incr == 1 && wordCh[id] == 1) {
                ++num;
            }
        };
        
        long long cnt = 0;
        for (int left = 0, right = 0; right < len1; right++) {
            update(word1[right] - 'a', -1);
            while (num == 0) {
                cnt += len1 - right;
                update(word1[left++] - 'a', 1);
            }      
        }

        return cnt;
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

