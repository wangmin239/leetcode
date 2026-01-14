class Solution {
public:
    int pow_mod(int x, int y, int mod) {
        int res = 1;
        while (y) {
            if (y & 1) {
                res = res * x % mod;
            }

            x = x * x % mod;
            y >>= 1;
        }   
    return res;
    }
    
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        
        for (int i = 0; i < variables.size(); i++) {
            auto &v = variables[i];
            if (pow_mod(pow_mod(v[0], v[1], 10), v[2], v[3]) == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};





class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        int n = variables.size();
        
        int calcMod = [](int num, int pow, int divid) {
            int mod = num % divid;
            while (--pow) {
                mod *= num % divid;
                mod %= divid;
            }
            
            return mod;
        };
        
        for (int i = 0; i < n; i++) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            
            
            int mod = calcMod(a, b, 10);
            mod = calcMod(mod, c, m);
            
            if (mod == target) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};