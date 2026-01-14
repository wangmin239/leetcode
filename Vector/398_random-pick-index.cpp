class Solution {
public:
    unordered_map<int, vector<int>> dataBase;
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            dataBase[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        auto vec = dataBase[target];
        int size = vec.size();
        return vec[rand() % size];
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

 
class Solution {
    unordered_map<int, vector<int>> pos;
public:
    Solution(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto &indices = pos[target];
        return indices[rand() % indices.size()];
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
 
 class Solution {
    vector<int> &nums;
public:
    Solution(vector<int> &nums) : nums(nums) {}

    int pick(int target) {
        int ans;
        for (int i = 0, cnt = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++cnt; // 第 cnt 次遇到 target
                if (rand() % cnt == 0) {
                    ans = i;
                }
            }
        }
        return ans;
    }
};
