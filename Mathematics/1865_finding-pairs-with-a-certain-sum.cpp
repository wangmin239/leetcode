/* Original Solution 1 */
class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)  {
        auto initMaps = [](const vector<int>& nums, unordered_map<int, vector<int>>& digits) {
            for (size_t i = 0; i < nums.size(); i++) {
                digits[nums[i]].push_back(i);
            }
        };
            

        initMaps(nums1, digitIndex1);
        initMaps(nums2, digitIndex2);
        _nums2 = nums2;
    }
    
    void add(int index, int val) {
        int originVal = _nums2[index];
        auto& indexs = digitIndex2[originVal];
        int updateVal = originVal + val;
        
        digitIndex2[updateVal].push_back(index);
        _nums2[index] = updateVal;

        if (indexs.size() == 1) {
            digitIndex2.erase(originVal);
            return;
        }
        for (auto iter = indexs.begin(); iter != indexs.end(); ++iter) {
            if (*iter == index) {
                indexs.erase(iter);
                break;
            }
        }
        return;
    }
    
    int count(int tot) {
        size_t pairs = 0;
        for (auto [val, indexs] : digitIndex1) {
            int remain = tot - val;
            if (digitIndex2.count(remain) != 0) {
                pairs += indexs.size() * digitIndex2[remain].size();
            }
        }
        return static_cast<int>(pairs);
    }

private:
    unordered_map<int, vector<int>> digitIndex1, digitIndex2;
    vector<int> _nums2;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
 
 
/* Official Solution 1 */ 
class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num: nums2) {
            ++cnt[num];
        }
    }
    
    void add(int index, int val) {
        --cnt[nums2[index]];
        nums2[index] += val;
        ++cnt[nums2[index]];
    }
    
    int count(int tot) {
        int ans = 0;
        for (int num: nums1) {
            int rest = tot - num;
            if (cnt.count(rest)) {
                ans += cnt[rest];
            }
        }
        return ans;
    }
};
