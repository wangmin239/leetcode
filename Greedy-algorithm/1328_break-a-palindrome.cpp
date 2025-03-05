/* Original Solution */
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.length();
        if (len == 1) {
            return string();
        }
        
        for (int i = 0; i < len / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        

        palindrome[len - 1] = 'b';
        return palindrome;
    }
};

/* Official Solution */
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) {
            return "";
        }
        for (int i = 0; i * 2 + 1 < n; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome.back()++;
        return palindrome;
    }
};
