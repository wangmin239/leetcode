/* Official Solution 1 */
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        priority_queue<int> heap;
        vector<int> deltaArray(nums.size() + 1, 0);
        int operations = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            operations += deltaArray[i];
            while (j < queries.size() && queries[j][0] == i) {
                heap.push(queries[j][1]);
                ++j;
            }
            while (operations < nums[i] && !heap.empty() && heap.top() >= i) {
                operations += 1;
                deltaArray[heap.top() + 1] -= 1;
                heap.pop();
            }
            if (operations < nums[i]) {
                return -1;
            }
        }
        return heap.size();
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> preSum(n + 1);
        priority_queue<int> pq;
        int curSum = 0;
        
        /* sort the queries by the index */
        sort(queries.begin(), queries.end(), [](auto& lhs, auto& rhs) {
            return lhs.front() < rhs.front();
        });
        
        for (int i = 0, j = 0; i < n; i++) {
            curSum += preSum[i];
            /* the greater range of each query is put in the front of the priority queue */
            while (j < queries.size() && queries[j].front() == i) {
                pq.push(queries[j].back());
                j++;
            }
            
            /* check the current sum is greater than the current nums[i] */
            while (pq.empty() == false && curSum < nums[i] && pq.top() >= i) {
                curSum += 1;
                preSum[pq.top() + 1] -= 1;
                pq.pop();
            }
            
            if (curSum < nums[i]) {
                return -1;
            }
        }
        
        return static_cast<int>(pq.size());
    }


};

