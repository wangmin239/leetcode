/* Original Solution 1 */
class Solution {
public:
    bool isValid(string word) {
        int len = word.length();
        auto isvowel = [](const char& ch) {
            char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            for (char vowel : vowels) {
                if (ch == vowel) {
                    return true;
                }
            }
            return false;
        };
        
        /* The length of the word is less than 3 */
        if (len < 3) {
            return false;
        }
        
        int vowelCnt = 0;
        int consonant = 0;
        
        for (char ch : word) {
            /* In the case that the string contains some special characters */
            if (!isalnum(ch)) {
                return false;
            }
            
            if (isalpha(ch)) {
                if (isvowel(ch)) {
                    vowelCnt++;
                } else {
                    consonant++;
                }
            }
        }
        
        return vowelCnt > 0 && consonant > 0;
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        bool has_vowel = false;
        bool has_consonant = false;
        for (auto c : word) {
            if (isalpha(c)) {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return has_vowel && has_consonant;
    }
};
