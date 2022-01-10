class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.length();
        long first = 0;
        long second = 0;
        long sum = 0;
        bool isAdditive = false;
        int nextPos = 0;
        int digitWidth;
        int firstStart = 0;
        
        while (firstStart < (len - 1) / 2) {
            for (int i = firstStart; i < (len - 1) / 2; i++) {
                first = stol(num.substr(0, i + 1));
                if (to_string(first).length() < i + 1) {
                    continue;
                }
                int start = i + 1;
                
                
                for (int j = start; j < len - i; j++) {
                    second = stol(num.substr(start, j - start + 1));
                    if (to_string(second).length() < j - start + 1) {
                        continue;
                    }

                    long curSum = first + second;             
                    digitWidth = to_string(curSum).length();
                    if (j + digitWidth <= len) {
                        sum = stol(num.substr(j + 1, digitWidth));
                        if (curSum == sum) {
                            isAdditive = true;
                            nextPos = j + 1 + digitWidth;
                            firstStart = i;
                            break;
                        }
                    }


                }
                
                if (isAdditive == true) {
                    break;
                }
            }
            
            if (isAdditive == false) {
                firstStart++;
                continue;
            }
            
            while (nextPos < len) {
                int start = nextPos;
                if (isValid(start, num) == false) {
                    return false;
                }
                
                long curSum = second + sum;
                digitWidth = max(digitWidth, static_cast<int>(to_string(curSum).length()));
                
                if (nextPos + digitWidth <= len) {
                    second = sum;
                    sum = stol(num.substr(nextPos, digitWidth));
                }
                
                if (curSum == sum) {
                    isAdditive = true;
                    nextPos += digitWidth;
                    if (nextPos == len) {
                        return true;
                    }
                } else {
                    firstStart++;
                    break;
                }
            }

                
        }
        return false;
    }
    
    inline bool isValid(int start, const string& num) {
        return num[start] == '0' ? false : true;
    }
};




class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int secondStart = 1; secondStart < n - 1; ++secondStart) {
            if (num[0] == '0' && secondStart != 1) {
                break;
            }
            for (int secondEnd = secondStart; secondEnd < n - 1; ++secondEnd) {
                if (num[secondStart] == '0' && secondStart != secondEnd) {
                    break;
                }
                if (valid(secondStart, secondEnd, num)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool valid(int secondStart, int secondEnd, string num) {
        int n = num.size();
        int firstStart = 0, firstEnd = secondStart - 1;
        while (secondEnd <= n - 1) {
            string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
            int thirdStart = secondEnd + 1;
            int thirdEnd = secondEnd + third.size();
            if (thirdEnd >= n || !(num.substr(thirdStart, thirdEnd - thirdStart + 1) == third)) {
                break;
            }
            if (thirdEnd == n - 1) {
                return true;
            }
            firstStart = secondStart;
            firstEnd = secondEnd;
            secondStart = thirdStart;
            secondEnd = thirdEnd;
        }
        return false;
    }

    string stringAdd(string s, int firstStart, int firstEnd, int secondStart, int secondEnd) {
        string third;
        int carry = 0, cur = 0;
        while (firstEnd >= firstStart || secondEnd >= secondStart || carry != 0) {
            cur = carry;
            if (firstEnd >= firstStart) {
                cur += s[firstEnd] - '0';
                --firstEnd;
            }
            if (secondEnd >= secondStart) {
                cur += s[secondEnd] - '0';
                --secondEnd;
            }
            carry = cur / 10;
            cur %= 10;
            third.push_back(cur + '0');
        }
        reverse(third.begin(), third.end());
        return third;
    }
};
