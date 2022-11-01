class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        
        int p1 = 0;
        int p2 = 0;
        int i = 0;
        int j = 0;
        while (p1 < size1 && p2 < size2) {
            if (word1[p1][i] != word2[p2][j]) {
                return false;
            }
            
            ++i;
            if (i == word1[p1].length()) {
                i = 0;
                ++p1;
            }
            
            ++j;
            if (j == word2[p2].length()) {
                j = 0;
                ++p2;
            }
        }
        
        return p1 == size1 && p2 == size2;
    }
};


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1;
        string str2;
        
        for (auto word : word1) {
            str1.append(word);
        }
        
        for (auto word : word2) {
            str2.append(word);
        }
        
        return str1 == str2;
    }
};