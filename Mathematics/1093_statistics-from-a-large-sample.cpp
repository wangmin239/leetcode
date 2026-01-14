class Solution {
public:    
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size();
        int total = accumulate(count.begin(), count.end(), 0);
        double mean = 0.0;
        double median = 0.0;
        int minnum = 256;
        int maxnum = 0;
        int mode = 0;

        int left = (total + 1) / 2;
        int right = (total + 2) / 2;
        int cnt = 0;
        int maxfreq = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long)count[i] * i;
            if (count[i] > maxfreq) {
                maxfreq = count[i];
                mode = i;
            }
            if (count[i] > 0) {
                if (minnum == 256) {
                    minnum = i;
                }
                maxnum = i;
            }
            if (cnt < right && cnt + count[i] >= right) {
                median += i;
            }
            if (cnt < left && cnt + count[i] >= left) {
                median += i;
            }
            cnt += count[i];
        }
        mean = (double) sum / total;
        median = median / 2.0;
        return {(double)minnum, (double)maxnum, mean, median, (double)mode};
    }
};


class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans(5, 0.0);
        int n = count.size();
        /* Get minimum */
        for (int i = 0; i < n; i++) {
            if (count[i] != 0) {
                ans[0] = static_cast<double>(i);
                break;
            }
        }
        
        /* Get Maximum */
        for (int i = n - 1; i >= 0; i--) {
            if (count[i] != 0) {
                ans[1] = static_cast<double>(i);
                break;
            }
        }
        
        /* Get Maximum */
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += count[i];
        }
        
        for (int i = 0; i < n; i++) {
            ans[2] += static_cast<double>(count[i])/sum * i;
        }
        
        
        
        auto maxIter = max_element(count.begin(), count.end());
        ans[4] = maxIter - count.begin();
        
        int mid = sum / 2;
        int midSum = 0;
        int i;
        for (i = 0; i < n; i++) {
            midSum += count[i];
            if (midSum >= mid) {
                break;
            }
        }
        
        if (sum % 2) {
            if (midSum > mid) {
                ans[3] = static_cast<double>(i);
            } else {
                for (; i < n; i++) {
                    if (count[i] != 0) {
                        ans[3] = static_cast<double>(i);
                    }
                }
            }
        } else {
            if (midSum > mid) {
                ans[3] = static_cast<double>(i);
            } else {
                for (int j = i + 1; j < n; j++) {
                    if (count[j] != 0) {
                        ans[3] = static_cast<double>(j + i)/2;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};