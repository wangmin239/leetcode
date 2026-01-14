class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (auto aster : asteroids) {
            bool alive = true;
            while (alive && aster < 0 && !st.empty() && st.back() > 0) {
                alive = st.back() < -aster; // aster 是否存在
                if (st.back() <= -aster) {  // 栈顶行星爆炸
                    st.pop_back();
                }
            }
            if (alive) {
                st.push_back(aster);
            }
        }
        return st;
    }
};




class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        
        for (const auto& val : asteroids) {
            if (ans.empty() == true) {
                ans.push_back(val);
                continue;
            }
            
            auto last = ans.back();
            if (val * last > 0) {
                ans.push_back(val);
                continue;
            }
            
            if (last < 0 && val > 0) {
                ans.push_back(val);
                continue;
            }
            

            
            while (val * last < 0) {
                if (abs(val) > abs(last)) {
                    ans.pop_back();
                    if (ans.empty() == true) {
                        ans.push_back(val);
                        break;
                    } else {
                        last = ans.back();
                        if (val * last > 0) {
                            ans.push_back(val);
                            break;
                        }
                    }
                } else if (abs(val) == abs(last)) {
                    ans.pop_back();
                    break;
                } else {
                    break;
                }
            }
            
        }
        
        return ans;
    }
};