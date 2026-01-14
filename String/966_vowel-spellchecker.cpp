//* Original Solution 1 */
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, vector<int>> wordIds;
        vector<string> ans;
        unordered_map<string, int> memo;
        int size = wordlist.size();
        auto isVowel = [](const char ch) {
            char vowel[] = {"aeiou"};
            for (size_t i = 0; i < sizeof(vowel) / sizeof(char) - 1; i++) {
                if (ch == vowel[i]) {
                    return true;
                }
            }
            return false;
        };
        
        /* convert to lower string */
        for (int i = 0; i < size; i++) {
            string word(wordlist[i]);
            for (char& ch : word) {
                ch = tolower(ch);
            }
            wordIds[word].push_back(i);
        }
        
        
        for (const string& query : queries) {
            if (memo.count(query) != 0) {
                ans.push_back(wordlist[memo[query]]);
                continue;
            }
            
            string lowStr(query);
            /* case 1, spell upper or lower */
            for (char& ch : lowStr) {
                ch = tolower(ch);
            }
            
            if (wordIds.count(lowStr) != 0) {
                auto ids = wordIds[lowStr];
                int minId = ids.front();
                for (int id : ids) {
                    if (query == wordlist[id]) {
                        minId = id;
                        break;
                    }
                }
                ans.push_back(wordlist[minId]);
                memo[query] = minId;
                continue;
            }
            /* case 2, spell error */
            int len = query.length();
            int minId = INT_MAX;
            
            for (const auto [word, ids] : wordIds) {
                if (len != word.length()) {
                    continue;
                }
                int i;
                for (i = 0; i < len; i++) {
                    if (lowStr[i] != word[i]) {
                        if (isVowel(lowStr[i]) == false || isVowel(word[i]) == false) {
                            break;
                        }
                    }
                }
                
                if (i == len) {
                    minId = min(minId, ids.front());
                }
            }
            if (minId != INT_MAX) {
                memo[query] = minId;
            }
            ans.push_back(minId == INT_MAX ? "" : wordlist[minId]);
            
        }
        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (string word : wordlist) {
            words_perfect.insert(word);
            string wordlow;
            for (char c : word) {
                wordlow += tolower(c);
            }
            if (!words_cap.count(wordlow)) {
                words_cap[wordlow] = word;
            }
            string wordlowDV = devowel(wordlow);
            if (!words_vow.count(wordlowDV)) {
                words_vow[wordlowDV] = word;
            }
        }

        vector<string> ans;
        for (string query : queries) {
            ans.push_back(solve(query));
        }
        return ans;
    }

private:
    unordered_set<string> words_perfect;
    unordered_map<string, string> words_cap;
    unordered_map<string, string> words_vow;

    string devowel(string word) {
        string ans;
        for (char c : word) {
            ans += isVowel(c) ? '*' : c;
        }
        return ans;
    }

    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string solve(string query) {
        if (words_perfect.count(query)) {
            return query;
        }

        string queryL;
        for (char c : query) {
            queryL += tolower(c);
        }
        if (words_cap.count(queryL)) {
            return words_cap[queryL];
        }

        string queryLV = devowel(queryL);
        if (words_vow.count(queryLV)) {
            return words_vow[queryLV];
        }

        return "";
    }
};
