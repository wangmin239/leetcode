class Solution {
public:
    int cnt;
    vector<vector<int>> triVec;
    int triangleNumber(vector<int>& nums) {
        vector<int> vec;
        dfs(nums, 0, vec);
        
        for (auto& triaVecElem : triVec) {
            if (isTriangle(triaVecElem) == true) {
                cnt++;
            }
        }
        return cnt;
    }
    
    void dfs(vector<int>& nums, int index, vector<int>& vec) {
        if (vec.size() == 3) {
            triVec.push_back(vec);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            vec.push_back(nums[i]);
            dfs(nums, i + 1, vec);
            vec.pop_back();
        }
    }
    
    bool isTriangle(vector<int>& vec) {
        sort(vec.begin(), vec.end());
        
        return vec[0] + vec[1] > vec[2];
    }
};



class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int left = j + 1, right = n - 1, k = j;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (nums[mid] < nums[i] + nums[j]) {
                        k = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                ans += k - j;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = i;
            for (int j = i + 1; j < n; ++j) {
                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
                    ++k;
                }
                ans += max(k - j, 0);
            }
        }
        return ans;
    }
};
