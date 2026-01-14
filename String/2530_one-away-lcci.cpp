
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int firstStrLen = first.length();
        int secondStrLen = second.length();
        
        if (abs(firstStrLen - secondStrLen) > 1) {
            return false;
        }
        
        if (first == second) {
            return true;
        }
        
        /* the length is equal */
        if (firstStrLen == secondStrLen){
            return isOneDiff(first, second);
        }

        if (firstStrLen < secondStrLen) {
            return compareStr(first, second, 0, 0);
        }
        
        return compareStr(second, first, 0, 0);

    }
    
    bool compareStr(const string& shortStr, const string& longStr, int&& shortIndex, int&& longIndex) {
        auto getDiffIndex = [&](const auto& lhs, const auto& rhs) {
            for (; shortIndex < lhs.length(); shortIndex++, longIndex++) {
                if (lhs[shortIndex] != rhs[longIndex]) {
                    break;
                }
            }
        };
        

        getDiffIndex(shortStr, longStr);
        ++longIndex;
        getDiffIndex(shortStr, longStr);        

            
        return shortIndex == shortStr.length();
       
    }
    
    bool isOneDiff(const string& lhs, const string& rhs) {
        int count = 0;
        
        for (int i = 0; i < lhs.length(); i++) {
            if (lhs[i] != rhs[i]) {
                count++;
            }
        }
        
        return count == 1;      
    }
    
    
};


class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.size(), n = second.size();
        if (n - m == 1) {
            return oneInsert(first, second);
        } else if (m - n == 1) {
            return oneInsert(second, first);
        } else if (m == n) {
            bool foundDifference = false;
            for (int i = 0; i < m; i++) {
                if (first[i] != second[i]) {
                    if (!foundDifference) {
                        foundDifference = true;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool oneInsert(string shorter, string longer) {
        int length1 = shorter.size(), length2 = longer.size();
        int index1 = 0, index2 = 0;
        while (index1 < length1 && index2 < length2) {
            if (shorter[index1] == longer[index2]) {
                index1++;
            }
            index2++;
            if (index2 - index1 > 1) {
                return false;
            }
        }
        return true;
    }
};
