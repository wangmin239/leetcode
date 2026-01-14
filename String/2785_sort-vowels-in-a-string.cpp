/* Original Solutin 1 */
class Solution {
public:
    string sortVowels(string s) {
        string vowels("aeiouAEIOU");
        string abstractVowel;
        vector<int> ids;

        for (size_t i = 0; i < s.length(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                abstractVowel.push_back(s[i]);
                ids.push_back(i);
            }
        }
        
        sort(abstractVowel.begin(), abstractVowel.end(), less<char>());
        
        int i = 0;
        for (char& ch : abstractVowel) {
            int index = ids[i++];
            s[index] = ch;
        }
        
        return s;
    }
};

/* Original Solutin 2 */
class Solution {
public:
    string sortVowels(string s) {
        string vowels("aeiouAEIOU");
        vector<int> vowelIds;
        map<char, int> vowelFreq;
        
        for (size_t i = 0; i < s.length(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                vowelIds.push_back(i);
                ++vowelFreq[s[i]];
            }
        }
        
        int i = 0;
        for (auto [ch, cnt] :vowelFreq) {
            while (cnt--) {
                int index = vowelIds[i++];
                s[index] = ch;
            }
        }
        
        return s;
    }
};




/* Original Solutin 3 */
class Solution {
public:
    string sortVowels(string s) {
        const int num = 10;
        char vowels[num + 1] = "AEIOUaeiou";
        int abstractVowel[num] = {0};
        vector<int> ids;

        auto find = [vowels, num](char ch) {
            for (int i = 0; i < num; i++) {
                if (ch == vowels[i]) {
                    return i;
                }
            }
            return -1;
        };
        /* get the count of every abstracted vowel character */
        for (size_t i = 0; i < s.length(); i++) {
            size_t pos = find(s[i]);
            if (pos != -1) {
                ++abstractVowel[pos];
                ids.push_back(i);
            }
        }
        

        /* restore the vowel characters */        
        for (int i = 0, id = 0; i < num; i++) {
            while (abstractVowel[i]--) {
                int index = ids[id++];
                s[index] = vowels[i];
            }
        }
        
        return s;
    }
};


/* Official Solution 1 */
class Solution {
public:
    string sortVowels(string s) {
        const int VOWEL_MASK = 0x208222;
        int cnt['u' + 1]{};
        for (char ch : s) {
            if (VOWEL_MASK >> (ch & 31) & 1) {
                cnt[ch]++;
            }
        }

        char j = 'A';
        for (char& ch : s) {
            if ((VOWEL_MASK >> (ch & 31) & 1) == 0) {
                continue;
            }
            // 找下一个出现次数大于 0 的元音字母
            while (cnt[j] == 0) {
                j = j == 'Z' ? 'a' : j + 1;
            }
            ch = j;
            cnt[j]--;
        }
        return s;
    }
};