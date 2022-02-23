class Solution {
public:
    string reverseOnlyLetters(string s) {
        int len = s.length();
        
        for (int i = 0;  i < len; ) {
            if (!isalpha(s[i])) {
                i++;
                continue;
            }
            
            if (!isalpha(s[len - 1])) {
                len--;
                continue;
            }
            
            swap(s[i], s[len - 1]);
            i++;
            len--;

        }
               
        return s;
    }
};

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (true) {
            while (left < right && !isalpha(s[left])) { // 判断左边是否扫描到字母
                left++;
            }
            while (right > left && !isalpha(s[right])) { // 判断右边是否扫描到字母
                right--;
            }
            if (left >= right) {
                break;
            }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};
