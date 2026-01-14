/* Original Solution 1 */
class Solution {
public:
    bool doesAliceWin(string s) {
        const char vowels[] = {"aieou"};
        constexpr int num = sizeof(vowels) / sizeof(vowels[0]);
        auto isVowel = [vowels](char ch) {    
            for (size_t i = 0; i < num; i++) {
                if (ch == vowels[i]) {
                    return true;
                }
            }
            return false;
        };
        
        /* A string containing at least one vowel is helpful for Alice to win the game */
        for (char ch : s) {
            if (isVowel(ch) == true) {
                return true;
            }
        }
        
        return false;
    }
};

/* Official Solution 1 */
class Solution {
public:
    bool doesAliceWin(string s) {
        return ranges::any_of(s, [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        });
    }
};
