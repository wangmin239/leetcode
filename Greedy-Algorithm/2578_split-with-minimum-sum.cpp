class Solution {
public:
    int splitNum(int num) {
        string stnum = to_string(num);
        sort(stnum.begin(), stnum.end());
        int num1 = 0, num2 = 0;
        for (int i = 0; i < stnum.size(); ++i) {
            if (i % 2 == 0) {
                num1 = num1 * 10 + (stnum[i] - '0');
            }
            else {
                num2 = num2 * 10 + (stnum[i] - '0');
            }
        }
        return num1 + num2;
    }
};




class Solution {
public:
    int splitNum(int num) {
        vector<int> seq;
        
        while (num != 0) {
            seq.push_back(num % 10);
            num /= 10;
        }
        
        sort(seq.begin(), seq.end(), less<int>());
        
        int num1 = 0;
        int num2 = 0;
        
        for (size_t i = 0; i < seq.size(); i += 2) {
            num1 = num1 * 10 + seq[i];
        }
        
        for (size_t i = 1; i < seq.size(); i += 2) {
            num2 = num2 * 10 + seq[i];
        }
        return num1 + num2;
    }
};