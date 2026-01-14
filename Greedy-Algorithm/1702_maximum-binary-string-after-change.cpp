class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (binary[i] == '0') {
                while (j <= i || (j < n && binary[j] == '1')) {
                    j++;
                }
                if (j < n) {
                    binary[j] = '1';
                    binary[i] = '1';
                    binary[i + 1] = '0';
                }
            }
        }
        return binary;
    }
};


class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size(), i = binary.find('0');
        if (i == string::npos) {
            return binary;
        }
        int zeros = count(binary.begin(), binary.end(), '0');
        string s(n, '1');
        s[i + zeros - 1] = '0';
        return s;
    }
};





class Solution {
public:
    string maximumBinaryString(string binary) {
        int len = binary.length();
        
        for (int i = 0; i < len - 1; i++) {
            if (binary[i] == '0' && binary[i + 1] == '0') {
                binary[i] = '1';
                continue;
            }
            
            if (binary[i] == '1' && binary[i + 1] == '0') {
                binary[i] = '0';
                binary[i + 1] = '1';
            }
        }
        
        for (int i = len - 1; i > 0; i--) {
            if (binary[i] == '0' && binary[i - 1] == '1') {
                binary[i] = '1';
                binary[i - 1] = '0';
                continue;
            }
            
            if (binary[i] == '0' && binary[i - 1] == '0') {
                binary[i - 1] = '1';
            }
        }
        return binary;
    }
};


