/* Original Solution 1 */
class Solution {
public:
    int maxFreqSum(string s) {
        const int num = 26;
        string vowels("aeiou");
        int chArr[num] = {0};
        
        for (char ch : s) {
            int index = ch - 'a';
            ++chArr[index];
        }
        
        int vowelCnt = 0;
        int consonantCnt = 0;
        
        for (int i = 0; i < num; i++) {
            int freq = chArr[i];
            char ch = 'a' + i;
            
            if (vowels.find(ch) == string::npos) {
                consonantCnt = max(consonantCnt, freq);
            } else {
                vowelCnt = max(vowelCnt, freq);
            }
        }
        
        return  vowelCnt + consonantCnt;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maxFreqSum(string s) {
        const int VOWEL_MASK = 0x104111;
        int cnt[26]{};
        int max_cnt[2]{};
        for (char ch : s) {
            ch -= 'a';
            int bit = VOWEL_MASK >> ch & 1;
            cnt[ch]++;
            max_cnt[bit] = max(max_cnt[bit], cnt[ch]);
        }
        return max_cnt[0] + max_cnt[1];
    }
};
