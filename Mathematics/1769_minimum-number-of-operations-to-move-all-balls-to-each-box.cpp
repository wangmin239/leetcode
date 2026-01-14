class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left = boxes[0] - '0', right = 0, operations = 0;
        int n = boxes.size();
        for (int i = 1; i < n; i++) {
            if (boxes[i] == '1') {
                right++;
                operations += i;
            }
        }
        vector<int> res(n);
        res[0] = operations;
        for (int i = 1; i < n; i++) {
            operations += left - right;
            if (boxes[i] == '1') {
                left++;
                right--;
            }
            res[i] = operations;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int sm = 0;
            for (int j = 0; j < n; j++) {
                if (boxes[j] == '1') {
                    sm += abs(j - i);
                }
            }
            res[i] = sm;
        }
        return res;
    }
};




class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.length();
        vector<int> oneIds;
        for (int i = 0; i < len; i++) {
            if (boxes[i] == '1') {
                oneIds.push_back(i);
            }
        }
        
        vector<int> steps(len, 0);
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < oneIds.size(); j++) {
               steps[i] += abs(oneIds[j] - i);
            }

        }
        return steps;
    }
};