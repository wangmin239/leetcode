class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs.front().length();
        int delCnt = 0;
        
        for (int col = 0; col < cols; col++) {
            for (int row = 1; row < rows; row++) {
                if (strs[row - 1][col] > strs[row][col]) {
                    delCnt++;
                    break;
                }
            }
        }
        
        return delCnt;
    }
};



class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int rows = strs.size();
        int cols = strs.front().length();
        vector<int> decreaseCnt(cols, 0);
        auto comp = [&](const string& lhs, const string& rhs) {
            for (int i = 0; i < cols; i++) {
                if (lhs[i] > rhs[i]) {
                    decreaseCnt[i] |= 1;
                }
            }
        };
        
        for (int i = 1; i < rows; i++) {
            comp(strs[i - 1], strs[i]);
        }
        

        
        return accumulate(decreaseCnt.begin(), decreaseCnt.end(), 0);
    }
};





class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs.front().length();
        vector<int> decreaseCnt(cols, 0);
        auto comp = [&](const string& lhs, const string& rhs) {
            for (int i = 0; i < cols; i++) {
                if (decreaseCnt[i] == 1) {
                    continue;
                }
                if (lhs[i] > rhs[i]) {
                    decreaseCnt[i] |= 1;
                }
            }
        };
        
        for (int i = 1; i < rows; i++) {
            comp(strs[i - 1], strs[i]);
        }
        

        
        return accumulate(decreaseCnt.begin(), decreaseCnt.end(), 0);
    }
};






