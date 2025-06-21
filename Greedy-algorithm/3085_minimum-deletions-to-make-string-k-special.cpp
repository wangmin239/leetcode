class Solution {
public:
    int minimumDeletions(string word, int k) {
        const int limit = 26;
        int chArr[limit] = {0};
        
        for (char ch : word) {
            int index = ch - 'a';
            ++chArr[index];
        }
        
        sort(chArr, chArr + limit);
        
        int minDelete = word.length();
        int nonZero = 0;
        while (chArr[nonZero] == 0) {
            ++nonZero;
        }
        
        
        for (int i = nonZero; i < limit; i++) {
            int level = chArr[i];
            int curSum = 0;
            for (int j= nonZero; j < limit; j++) {
                if (chArr[j] < level) {
                    curSum += chArr[h];
                } else if (chArr[j] > level + k) {
                    curSum += chArr[j] - level - k;
                }
            }
            minDelete = min(minDelete, curSum)
        }
        
        return minDelete;
    }
};