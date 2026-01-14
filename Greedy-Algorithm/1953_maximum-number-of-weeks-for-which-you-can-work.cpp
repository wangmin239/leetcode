class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        // 耗时最长工作所需周数
        long long longest = *max_element(milestones.begin(), milestones.end());
        // 其余工作共计所需周数
        long long rest = accumulate(milestones.begin(), milestones.end(), 0LL) - longest;
        if (longest > rest + 1){
            // 此时无法完成所耗时最长的工作
            return rest * 2 + 1;
        }
        else {
            // 此时可以完成所有工作
            return longest + rest;
        }
    }
};




class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long weeks = 0;
        long long preWeeks = 0;
        int n = milestones.size();

        sort(milestones.begin(), milestones.end(), greater<int>());
        int cur = milestones.front();
        int id = 0;

        for (int i = 1; i < n; i++) {
            preWeeks = weeks;
            if (cur <= milestones[i]) {
                weeks += 2 * cur;
                cur = milestones[i] - cur;
                id = i;
            } else {
                cur -= milestones[i];
                weeks += 2 * milestones[i];
            }

        }
        if (cur == 0) {
            return weeks;
        }
        
        if (id == 0) {
            return weeks + 1;
        }
        
        
        return weeks + min(cur, (preWeeks + 1)/2);
    }
};