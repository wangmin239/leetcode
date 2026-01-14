class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {     
        if (s1 == s2) {
            return true;
        }
        
        int len = s1.length();
        int left, right;
        
        for (left = 0; left < len; left++) {
            if (s1[left] != s2[left]) {
                break;
            }
        }
        
        for (right = len - 1; right > left; right--) {
            if (s1[right] != s2[right]) {
                break;
            }
        }
        
        swap(s1[left], s1[right]);
        
        return s1 == s2;
    }
};




class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int> diff;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                if (diff.size() >= 2) {
                    return false;
                }
                diff.emplace_back(i);
            }
        }
        if (diff.size() == 0) {
            return true;
        }
        if (diff.size() != 2) {
            return false;
        }
        return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
    }
};
