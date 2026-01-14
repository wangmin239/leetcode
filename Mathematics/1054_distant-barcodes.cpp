class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int length = barcodes.size();
        if (length < 2) {
            return barcodes;
        }

        unordered_map<int, int> counts;
        int maxCount = 0;
        for (int b : barcodes) {
            maxCount = max(maxCount, ++counts[b]);
        }

        int evenIndex = 0, oddIndex = 1, halfLength = length / 2;
        vector<int> res(length);
        for (auto &[x, cx] : counts) {
            while (cx > 0 && cx <= halfLength && oddIndex < length) {
                res[oddIndex] = x;
                cx--;
                oddIndex += 2;
            }
            while (cx > 0) {
                res[evenIndex] = x;
                cx--;
                evenIndex += 2;
            }
        }
        return res;
    }
};



class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int len = barcodes.size();

        if (len < 3) {
            return barcodes;
        }
        
        unordered_map<int, int> barFreq;
        for (int barcode : barcodes) {
            ++barFreq[barcode];
        }
        
        int size = barFreq.size();
        vector<pair<int, int>> barCnt(size);
        int i = 0;
        for (auto [barcode, cnt] : barFreq) {
            barCnt[i++] = make_pair(barcode, cnt);
        }
        sort(barCnt.begin(), barCnt.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
        });
        int even = 0;
        int odd = 1;
        vector<int> ans(len, 0);
        i = 0;
        
        for (int even = 0; even < len; even += 2) {
            if (barCnt[i].second > 0) {
                ans[even] = barCnt[i].first;
            } else {
                ++i;
                ans[even] = barCnt[i].first;
            }
            barCnt[i].second--;
        }
        for (int odd = 1; odd < len; odd += 2) {
            if (barCnt[i].second > 0) {
                ans[odd] = barCnt[i].first;
            } else {
                ++i;
                ans[odd] = barCnt[i].first;
            }
            barCnt[i].second--;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> count;
        for (int b : barcodes) {
            count[b]++;
        }
        priority_queue<pair<int, int>> q;
        for (const auto &[x, cx] : count) {
            q.push({cx, x});
        }
        vector<int> res;
        while (q.size()) {
            auto [cx, x] = q.top();
            q.pop();
            if (res.empty() || res.back() != x) {
                res.push_back(x);
                if (cx > 1) {
                    q.push({cx - 1, x});
                }
            } else {
                if (q.size() < 1) return res;
                auto [cy, y] = q.top();
                q.pop();
                res.push_back(y);
                if (cy > 1)  {
                    q.push({cy - 1, y});
                }
                q.push({cx, x});
            }
        }
        return res;
    }
};
