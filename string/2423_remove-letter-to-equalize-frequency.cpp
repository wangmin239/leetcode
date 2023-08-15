class Solution {
public:
    bool equalFrequency(string word) {
        int len = word.length();
        
        char preCh = word[0];
        int cnt = 1;
        sort(word.begin(), word.end());
        int index = 0;
        vector<int> chCnt(26, 0);
        int nonZero = 1;
        for (int i = 1; i < len; i++) {
            if (word[i] == preCh) {
                ++cnt;remove-letter-to-equalize-frequency
            } else {
                chCnt[word[i] - 'a'] = cnt;
                cnt = 1;
                preCh = word[i];
                ++nonZero;
            }
            if (i == len - 1) {
                chCnt[word[i] - 'a'] = cnt;
            }
        }      
        
        int average = len / nonZero;
        for (int freq : chCnt) {
            if (freq != 0) {
                
    }
};