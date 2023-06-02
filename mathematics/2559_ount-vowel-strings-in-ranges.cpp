class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int prefixSums[n + 1];
        memset(prefixSums, 0, sizeof(prefixSums));
        for (int i = 0; i < n; i++) {
            int value = isVowelString(words[i]) ? 1 : 0;
            prefixSums[i + 1] = prefixSums[i] + value;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0], end = queries[i][1];
            ans[i] = prefixSums[end + 1] - prefixSums[start];
        }
        return ans;
    }

    bool isVowelString(const string &word) {
        return isVowelLetter(word[0]) && isVowelLetter(word.back());
    }

    bool isVowelLetter(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};




class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        function<bool(const string)> isVowelStr =[](const string& word) {
            auto isVowel =[](const char ch) {
                const string vowels("aeiou");
                for (char vowel : vowels) {
                    if (ch == vowel) {
                        return true;
                    }
                }
                return false;
            }
            return isVowel(word.front()) && isVowel(word.back());
        };

        int n = words.size();
        vector<int> vowelStr(n, 0);
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (isVowelStr(words[i])) {
                vowelStr[len++] = i;
            }
        }
        
        int m = queries.size();
        vector<int> ans(m, 0);
        int i = 0;
        for (const auto& query : queries) {
            ans[i++] = getNum(query, vowelStr, len);
        }
        return ans;
    }
    
    int getNum(const vector<int>& query, const vector<int>& vowelStr, int len) {
      auto left = lower_bound(vowelStr.begin(), vowelStr.begin() + len, query.front());
      auto right = upper_bound(vowelStr.begin(), vowelStr.begin() + len, query.back());
      return right - left;
    }
};
