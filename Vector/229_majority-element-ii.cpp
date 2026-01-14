class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        int level = len / 3;
        int cnt = 0;
        int baseVal = nums.front();
        vector<int> ans;

        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len; i++) {
            if (baseVal == nums[i]) {
                cnt++;
                continue;
            }
            
            if (cnt > level) {
                   ans.push_back(baseVal);
            }
            
            baseVal = nums[i];
            cnt = 1;
        }
        
        if (baseVal == nums.back() && cnt > level) {
            ans.push_back(baseVal);
        }
        
        return ans;
    }
};


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        int level = len / 3;
        unordered_map<int, int> dataMap;
        vector<int> ans;
        
        for (int val : nums) {
            dataMap[val]++;
        }
        
        for (auto [val, cnt] : dataMap) {
            if (cnt > level) {
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};




class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int element1 = 0;
        int element2 = 0;
        int vote1 = 0;
        int vote2 = 0;

        for (auto & num : nums) {
            if (vote1 > 0 && num == element1) { //如果该元素为第一个元素，则计数加1
                vote1++;
            } else if (vote2 > 0 && num == element2) { //如果该元素为第二个元素，则计数加1
                vote2++;
            } else if (vote1 == 0) { // 选择第一个元素
                element1 = num;
                vote1++;
            } else if (vote2 == 0) { // 选择第二个元素
                element2 = num;
                vote2++;
            } else { //如果三个元素均不相同，则相互抵消1次
                vote1--;
                vote2--;
            }
        }

        int cnt1 = 0;
        int cnt2 = 0;
        for (auto & num : nums) {
            if (vote1 > 0 && num == element1) {
                cnt1++;
            }
            if (vote2 > 0 && num == element2) {
                cnt2++;
            }
        }
        // 检测元素出现的次数是否满足要求
        if (vote1 > 0 && cnt1 > nums.size() / 3) {
            ans.push_back(element1);
        }
        if (vote2 > 0 && cnt2 > nums.size() / 3) {
            ans.push_back(element2);
        }

        return ans;
    }
};
