
/* Original Solution */
class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int len = word.length();
        int ans = 0;


        /* Check if the five vowel characters are in the substring,
         *  then get the total number of the five vowel characters.
         */
        auto checkVowel = [](char chArr[], int& cntVowel) {
            char vowel[] = {'a', 'e', 'i', 'o', 'u'};
            bool isValid = true;
            cntVowel = 0;
            
            for (char ch : vowel) {
                int index = static_cast<int>(ch - 'a');
                cntVowel += chArr[index];
                if (chArr[index] == 0) {
                    isValid = false;
                }
            }
            return isValid;
        };

        auto getNum = [&](const int pos, const int k) {
            int cnt = 0;
            const int num = 26;
            char chArr[num] = {0};
            int cntVowel;

            for (int left = pos, right = pos; right < len; right++) {
                ++chArr[static_cast<int>(word[right] - 'a')];
                if (checkVowel(chArr, cntVowel)) {
                    /* The length of the substring subtracts the total number
                     * of the vowel characters.
                     */
                    int consonant = right - left + 1 - cntVowel;
                    if (consonant > k) {
                        break;
                    }
                    if (consonant == k) {
                        ++cnt;
                    }
                }
            }
            return cnt;
        };
        /**/
        const int vowelNum = 5;
        for (int pos = 0; pos < len - vowel - k + 1; pos++) {
            ans += getNum(pos, k);
        }
        return ans;
    }
};

/* Official Solution */
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        auto count = [&](int m) -> long long {
            int n = word.size(), consonants = 0;
            long long res = 0;
            map<char, int> occur;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n && (consonants < m || occur.size() < vowels.size())) {
                    if (vowels.count(word[j])) {
                        occur[word[j]]++;
                    } else {
                        consonants++;
                    }
                    j++;
                }
                if (consonants >= m && occur.size() == vowels.size()) {
                    res += n - j + 1;
                }
                if (vowels.count(word[i])) {
                    occur[word[i]]--;
                    if (occur[word[i]] == 0) {
                        occur.erase(word[i]);
                    }
                } else {
                    consonants--;
                }
            }
            return res;
        };
        return count(k) - count(k + 1);
    }
};

