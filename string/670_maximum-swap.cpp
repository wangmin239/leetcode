class Solution {
public:
    int maximumSwap(int num) {
        string originStr = to_string(num);
        string maxStr(originStr);
        
        sort(maxStr.begin(), maxStr.end(), greater<char>());
        
        int len = originStr.length();
        for (int i = 0; i < len; i++) {
            if (originStr[i] != maxStr[i]) {
                int index;
                for (int j = i; j < len; j++) {
                    if (originStr[j] == maxStr[i]) {
                        index = j;
                    }
                }
                swap(originStr[i], originStr[index]);
                break;
            }
        }
        
        return stoi(originStr);
    }
    
    
};

class Solution {
public:
    int maximumSwap(int num) {
        string charArray = to_string(num);
        int n = charArray.size();
        int maxIdx = n - 1;
        int idx1 = -1, idx2 = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (charArray[i] > charArray[maxIdx]) {
                maxIdx = i;
            } else if (charArray[i] < charArray[maxIdx]) {
                idx1 = i;
                idx2 = maxIdx;
            }
        }
        if (idx1 >= 0) {
            swap(charArray[idx1], charArray[idx2]);
            return stoi(charArray);
        } else {
            return num;
        }
    }
};

class Solution {
public:
    int maximumSwap(int num) {
        string charArray = to_string(num);
        int n = charArray.size();
        int maxNum = num;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(charArray[i], charArray[j]);
                maxNum = max(maxNum, stoi(charArray));
                swap(charArray[i], charArray[j]);
            }
        }
        return maxNum;
    }
};
