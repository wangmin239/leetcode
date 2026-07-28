/* Original Solution 1 */
class Solution {
public:
    string smallestPalindrome(string s) {
        const int chNum = 26;
        int len = s.length();
        int chArr[chNum] = {0};

        for (char ch : s) {
            ++chArr[ch - 'a'];
        }

        int left = 0;
        int right = len - 1;
        string palindromeStr(len, 'a');

        for (int id = 0; id < chNum; id++) {
            if (chArr[id] & 0x1) {
                palindromeStr[len / 2] = 'a' + id;
                --chArr[id];
            }

            while (chArr[id]) {
                palindromeStr[left++] = 'a' + id;
                palindromeStr[right--] = 'a' + id;
                chArr[id] -= 2;
            }
        }

        return palindromeStr;
    }
};



/* Original Solution 2 */
class Solution {
public:
    string smallestPalindrome(string s) {
        const int chNum = 26;
        int len = s.length();
        int chArr[chNum] = {0};

        for (char ch : s) {
            ++chArr[ch - 'a'];
        }

        int left = 0;
        string palindromeStr(len, 'a');

        for (int id = 0; id < chNum; id++) {
            if (chArr[id] & 0x1) {
                palindromeStr[len / 2] = 'a' + id;
                --chArr[id];
            }

            chArr[id] /= 2;
            while (chArr[id]) {
                palindromeStr[left++] = 'a' + id;
                --chArr[id];
            }
        }

        int right = left;
        if (len & 0x1) {
            right = len / 2 + 1;
        }

        while (left) {
            palindromeStr[right++] = palindromeStr[--left];
        }

        return palindromeStr;
    }
};

/* Official Solution 1 */
class Solution {
public:
    string smallestPalindrome(string s) {
        int len = s.length();
        int partition = len / 2;

        sort(s.begin(), s.begin() + partition);

        for (int i = 0; i < partition; ++i) {
            s[len - 1 - i] = s[i];
        }

        return s;
    }
};


/* Official Solution 2 */
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int bucket[26] = {0};

        for (int i = 0; i < n / 2; i++) {
            bucket[s[i] - 'a']++;
        }

        int left = 0;
        int right = n - 1;

        for (int i = 0; i < 26; i++) {
            while (bucket[i] > 0) {
                char c = i + 'a';
                s[left++] = c;
                s[right--] = c;
                bucket[i]--;
            }
        }

        return s;
    }
};
