class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        const int alphabetSize = 26;
        int licenseArr[alphabetSize] = {0};
        int wordArr[alphabetSize] = {0};
        int minLen = INT_MAX;
        int id, index = 0;
        
        getChArr(licenseArr, licensePlate);
        
        for (const string& str: words) {
            getChArr(wordArr, str);
            if (compChArr(licenseArr, wordArr) == true) {
                int curLen = str.length();
                if (curLen < minLen) {
                    minLen = curLen;
                    id = index;
                }
            }
            index++;
            clearChArr(wordArr);
        }
        
        return word[id];    
    }
    
    
    inline void getChArr(int chArr[26], const string& str) {
        for (char ch : str) {
            if (isalpha(ch)) {
                ch = tolower(ch);
                chArr[ch - 'a']++;
            }
        }
        
        return;
    }
    
    inline bool compChArr(int licenseArr[26], int wordArr[26]) {
        for (int i = 0; i < 26; i++) {
            if (licenseArr[i] > wordArr[i]) {
                return false;
            }
        }
        return true;
    }
    
    inline void clearChArr(int chArr[26]) {
        for (int i = 0; i < 26; i++) {
            chArr[i] = 0;
        }
    }
};



class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        const int alphabetSize = 26;
        int licenseArr[alphabetSize] = {0};
        int wordArr[alphabetSize] = {0};
        int minLen = INT_MAX;
        string shortestStr;
        
        getChArr(licenseArr, licensePlate);
        
        for (const string& str: words) {
            getChArr(wordArr, str);
            if (compChArr(licenseArr, wordArr) == true) {
                int curLen = str.length();
                if (curLen < minLen) {
                    minLen = curLen;
                    shortestStr = move(str);
                }
            }
            clearChArr(wordArr);
        }
        
        return shortestStr;    
    }
    
    
    inline void getChArr(int chArr[26], const string& str) {
        for (char ch : str) {
            if (isalpha(ch)) {
                ch = tolower(ch);
                chArr[ch - 'a']++;
            }
        }
        
        return;
    }
    
    inline bool compChArr(int licenseArr[26], int wordArr[26]) {
        for (int i = 0; i < 26; i++) {
            if (licenseArr[i] > wordArr[i]) {
                return false;
            }
        }
        return true;
    }
    
    inline void clearChArr(int chArr[26]) {
        for (int i = 0; i < 26; i++) {
            chArr[i] = 0;
        }
    }
};





class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        array<int, 26> cnt{};
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                ++cnt[tolower(ch) - 'a'];
            }
        }
        int idx = -1;
        for (int i = 0; i < words.size(); ++i) {
            array<int, 26> c{};
            for (char ch : words[i]) {
                ++c[ch - 'a'];
            }
            bool ok = true;
            for (int j = 0; j < 26; ++j) {
                if (c[j] < cnt[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok && (idx < 0 || words[i].length() < words[idx].length())) {
                idx = i;
            }
        }
        return words[idx];
    }
};
