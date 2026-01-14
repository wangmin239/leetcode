class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i][0] == words[j][1] && words[i][1] == words[j][0]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_set<int> seen;
        for (int i = 0; i < n; ++i) {
            if (seen.count(words[i][1] * 100 + words[i][0])) {
                ++ans;
            }
            seen.insert(words[i][0] * 100 + words[i][1]);
        }
        return ans;
    }
};



class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> wordsMap;
        int pairCnt = 0;

        for (auto&& word : words) {
            string bak(word);
            ++wordsMap[word];
            reverse(word.begin(), word.end());
            if (bak != word) {
                ++wordsMap[word];
            }
        }
        
        for (auto& [_, cnt] : wordsMap) {
            pairCnt += cnt / 2;
        }
        
        return pairCnt/2;
    }
};


class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> wordsMap;
        int pairCnt = 0;

        for (auto&& word : words) {
            string bak(word);
            ++wordsMap[word];
            reverse(word.begin(), word.end());
            
            /* check if the word is pari */
            if (bak == word) {
                if (wordsMap[word] == 1) {
                    continue;
                }
                ++pairCnt;
                wordsMap[word] -= 2;
            }

            if (wordsMap.count(word) > 0 && wordsMap[word] > 0) {
                ++pairCnt;
                --wordsMap[word];
            }
        }
        
        return pairCnt;
    }
};