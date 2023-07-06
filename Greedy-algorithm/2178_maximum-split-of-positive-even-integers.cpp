class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum % 2 > 0) {
            return res;
        }
        for (int i = 2; i <= finalSum; i += 2) {
            res.push_back(i);
            finalSum -= i;
        }
        res.back() += finalSum;
        return res;
    }
};




class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;

        if (finalSum % 2) {
            return ans;
        }

        long long k = 1;
        while (finalSum > 0) {
            long long val = 2 * k;

            finalSum -= val;
            ans.push_back(val);
            if (finalSum / 2 <= k) {
                ans.pop_back();
                ans.push_back(finalSum + val);
                finalSum = 0;
            }
            ++k;
        }
        return ans;
    }
};



class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;

        if (finalSum % 2) {
            return ans;
        }
        unordered_map<long long, long long> seen;
        long long k = 1;
        while (finalSum > 0) {
            long long val = 2 * k;
            ++seen[val];
            finalSum -= val;
            ans.push_back(val);
            if (seen.count(finalSum) != 0) {
                ans.pop_back();
                ans.push_back(finalSum + val);
                finalSum = 0;
            }
            ++k;
        }
        return ans;
    }
};