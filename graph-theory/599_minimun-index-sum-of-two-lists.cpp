class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> index;
        for (int i = 0; i < list1.size(); i++) {
            index[list1[i]] = i;
        }

        vector<string> ret;
        int indexSum = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            if (index.count(list2[i]) > 0) {
                int j = index[list2[i]];
                if (i + j < indexSum) {
                    ret.clear();
                    ret.push_back(list2[i]);
                    indexSum = i + j;
                } else if (i + j == indexSum) {
                    ret.push_back(list2[i]);
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> str1ind;
        for (int i = 0; i < list1.size(); ++i)
        {
            str1ind[list1[i]] = i;
        }
        unordered_map<int, vector<string>> sum2strs;
        int minSum = INT_MAX;
        for (int i = 0; i < list2.size(); ++i)
        {
            if (str1ind.count(list2[i]) > 0)
            {
                int curSum = i + str1ind[list2[i]];
                if (curSum < minSum)
                {
                    minSum = curSum;
                }
                sum2strs[curSum].push_back(list2[i]);

            }
        }

        return sum2strs[minSum];
    }
};