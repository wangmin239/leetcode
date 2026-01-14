class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        // 计算完以后的答案需要翻转过来
        reverse(ans.begin(), ans.end());
        return ans;
    }
};




class Solution {
public:
    string addStrings(string num1, string num2) {
       int len1 = num1.length();
       int len2 = num2.length();
       int carry = 0;
       string ans;
       while (len1 != 0 || len2 != 0) {
           int val = 0;
           
           if (len1 != 0) {
             val = static_cast<int>(num1[len1 - 1] - '0');
             --len1;
           }
           
           if (len2 != 0) {
             val += static_cast<int>(num2[len2 - 1] - '0');
             --len2;
           }
           val += carry;
           carry = val / 10;
           val %= 10;
           ans.push_back(static_cast<char>('0' + val));
       }
       if (carry != 0) {
           ans.push_back('1');
       }
       reverse(ans.begin(), ans.end());
       return ans;
    }
};