class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;   
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, m); i++) {
            pq.emplace(i, 0);
        }
        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top(); 
            pq.pop();
            ans.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n) {
                pq.emplace(x, y + 1);
            }
        }

        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        auto count = [&](int target){
            long long cnt = 0;
            int start = 0;
            int end = n - 1;
            while (start < m && end >= 0) {
                if (nums1[start] + nums2[end] > target) {
                    end--;
                } else {
                    cnt += end + 1;
                    start++;
                }
            }
            return cnt;
        };

        /*二分查找第 k 小的数对和的大小*/
        int left = nums1[0] + nums2[0];
        int right = nums1.back() + nums2.back();
        int pairSum = right;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (count(mid) < k) {
                left = mid + 1;
            } else {
                pairSum = mid;
                right = mid - 1;
            }
        }

        vector<vector<int>> ans;
        int pos = n - 1;
        /*找到小于目标值 pairSum 的数对*/
        for (int i = 0; i < m; i++) {
            while (pos >= 0 && nums1[i] + nums2[pos] >= pairSum) {
                pos--;
            }
            for (int j = 0; j <= pos && k > 0; j++, k--) {
                ans.push_back({nums1[i], nums2[j]});
            }
        }
        /*找到等于目标值 pairSum 的数对*/
        pos = n - 1;
        for (int i = 0; i < m && k > 0; i++) {
            while (pos >= 0 && nums1[i] + nums2[pos] > pairSum) {
                pos--;
            }
            for (int j = i; k > 0 && j >= 0 && nums1[j] + nums2[pos] == pairSum; j--, k--) {
                ans.push_back({nums1[i], nums2[pos]});
            }
        }
        return ans;
    }
};
