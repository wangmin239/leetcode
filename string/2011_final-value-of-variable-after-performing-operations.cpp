/* Original Solution 1 */
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        auto check = [](const string& word, char op) {
            for (char ch : word) {
                if (ch == op) {
                    return 1;
                }
            }
            return 0;
        };
        
        for (const auto& word : operations) {
            ans += check(word, '+');
            ans -= check(word, '-');
        }
        
        return ans;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        auto isIncr = [](const string& word) {
            for (char ch : word) {
                if (ch == '+') {
                    return true;
                }
            }
            return false;
        };
        
        for (const auto& word : operations) {
            if (isIncr(word) == true) {
                ++ans;
            } else {
                --ans;
            }
        }
        
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto &op : operations) {
            if (op == "X++" || op == "++X") {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }
};