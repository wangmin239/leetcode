class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int n = nums1.size(), m = nums2.size();
        // 假设有最大子序列中有s个元素来自nums1，对所有可能的s值遍历
        for (int s=max(0, k-m); s<=min(k, n); s++){
            vector<int> temp;
            int i = 0, j = 0;
            // nums1中长度为s的最大子序列
            vector<int> temp1 = maxKsequence(nums1, s);
            // nums2中长度为k-s的最大子序列
            vector<int> temp2 = maxKsequence(nums2, k-s);
            // 对两个子序列进行归并
            // lexicographical_compare：比较两个序列的字典序大小
            auto iter1 = temp1.begin(), iter2 = temp2.begin();
            while (iter1 != temp1.end() || iter2 != temp2.end()){
                temp.push_back(lexicographical_compare(iter1, temp1.end(), iter2, temp2.end()) ? *iter2++ : *iter1++);
            }
            // 如果归并后的最大子序列大于目前已找到的最大子序列，则更新解
            res = lexicographical_compare(res.begin(), res.end(), temp.begin(), temp.end()) ? temp : res;
        }
        return res;
    }

    // 求数组v的长度为k的最大子序列
    vector<int> maxKsequence(vector<int> v, int k){
        int n = v.size();
        if (n <= k)
            return v;
        vector<int> res;
        int pop = n-k;
        for (int i=0; i<n; i++){
            while(!res.empty() && v[i]>res.back() && pop-->0)
                res.pop_back();
            res.push_back(v[i]);
        }
        res.resize(k);
        return res;
    }
};

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> maxSubsequence(k, 0);
        int start = max(0, k - n), end = min(k, m);
        for (int i = start; i <= end; i++) {
            vector<int> subsequence1(MaxSubsequence(nums1, i));
            vector<int> subsequence2(MaxSubsequence(nums2, k - i));
            vector<int> curMaxSubsequence(merge(subsequence1, subsequence2));
            if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0) {
                maxSubsequence.swap(curMaxSubsequence);
            }
        }
        return maxSubsequence;
    }

    vector<int> MaxSubsequence(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> stack(k, 0);
        int top = -1;
        int remain = length - k;
        for (int i = 0; i < length; i++) {
            int num = nums[i];
            while (top >= 0 && stack[top] < num && remain > 0) {
                top--;
                remain--;
            }
            if (top < k - 1) {
                stack[++top] = num;
            } else {
                remain--;
            }
        }
        return stack;
    }

    vector<int> merge(vector<int>& subsequence1, vector<int>& subsequence2) {
        int x = subsequence1.size(), y = subsequence2.size();
        if (x == 0) {
            return subsequence2;
        }
        if (y == 0) {
            return subsequence1;
        }
        int mergeLength = x + y;
        vector<int> merged(mergeLength);
        int index1 = 0, index2 = 0;
        for (int i = 0; i < mergeLength; i++) {
            if (compare(subsequence1, index1, subsequence2, index2) > 0) {
                merged[i] = subsequence1[index1++];
            } else {
                merged[i] = subsequence2[index2++];
            }
        }
        return merged;
    }

    int compare(vector<int>& subsequence1, int index1, vector<int>& subsequence2, int index2) {
        int x = subsequence1.size(), y = subsequence2.size();
        while (index1 < x && index2 < y) {
            int difference = subsequence1[index1] - subsequence2[index2];
            if (difference != 0) {
                return difference;
            }
            index1++;
            index2++;
        }
        return (x - index1) - (y - index2);
    }
};
