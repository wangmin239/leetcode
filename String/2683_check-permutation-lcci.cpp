class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        return s1 == s2;
    }
};


class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        const int size = 26;
        int lowCh[size] = {0};
        int upperCh[size] = {0};
        int len1 = s1.length();
        int len2 = s2.length();
        
        if (len1 != len2) {
            return false;
        }
        
        for (int i = 0; i < len1; i++) {
            if (islower(s1[i])) {
                lowCh[s1[i] - 'a']++;
            } else {
                upperCh[s1[i] - 'A']++;
            }
            
            if (islower(s2[i])) {
                lowCh[s2[i] - 'a']--;
            } else {
                upperCh[s2[i] - 'A']--;
            }
        }
        
        for (int i = 0; i < size; i++) {
            if (lowCh[i] != 0) {
                return false;
            }
            
            if (upperCh[i] != 0) {
                return false;
            }
        }
        return true;
    }
};