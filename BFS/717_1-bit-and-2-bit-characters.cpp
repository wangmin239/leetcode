/* Original Solution 1 */
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        
        while (i < n - 1) {
            if (bits[i] == 1) {
                i += 2;
            } else {
                ++i;
            }
        }
        
        if (i < n && bits[i] == 0) {
            return true;
        }
        return false;
    }
};


/* Original Solution 2 */
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        function<bool(int)> dfs = [&](int index) {
          if (index == n) {
              return false;
          }
          
          if (index == n - 1 && bits[index] == 0) {
            return true;
          }
          
          if (bits[index] == 1) {
              return dfs(index + 2);
          } 
          
          return dfs(index + 1);
        };
        
        return dfs(0);
    }
};

/* Official Solution 1 */
class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        int n = bits.size(), i = 0;
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
    }
};

/* Official Solution 2 */
class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        int n = bits.size(), i = n - 2;
        while (i >= 0 and bits[i]) {
            --i;
        }
        return (n - i) % 2 == 0;
    }
};

