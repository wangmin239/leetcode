class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [&](const vector<int> &t1, const vector<int> &t2) -> bool {
            return t1[1] < t2[1];
        });
        vector<int> run(tasks[n - 1][1] + 1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];
            duration -= accumulate(run.begin() + start, run.begin() + end + 1, 0);
            res += max(duration, 0);
            for (int j = end; j >= 0 && duration > 0; j--) {
                if (run[j] == 0) {
                    duration--;
                    run[j] = 1;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int res = 0;
        for (int i = 1; ; i++) {
            bool finished = true, run = false;
            for (auto &task : tasks) {
                if (task[2] > 0 && task[1] - i + 1 == task[2]) {
                    run = true;
                }
                if (i <= task[1]) {
                    finished = false;
                }
            }
            if (finished) {
                break;
            }

            if (run) {
                for (auto &task : tasks) {
                    if (i >= task[0] && i <= task[1] && task[2] > 0) {
                        task[2]--;
                    }
                }
                res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](const vector<int> &t1, const vector<int> &t2) -> bool {
            return t1[1] < t2[1];
        });
        vector<vector<int>> st;
        st.push_back({-1, -1, 0});
        for (auto &task : tasks) {
            int start = task[0], end = task[1], duration = task[2];
            int k = lower_bound(st.begin(), st.end(), start, [&](const vector<int> &seg, int x) -> bool {
                return seg[0] < x;
            }) - st.begin();
            duration -= st.back()[2] - st[k - 1][2];
            if (start <= st[k - 1][1]) {
                duration -= st[k - 1][1] - start + 1;
            }
            if (duration <= 0) {
                continue;
            }
            while (end - st.back()[1] <= duration) {
                duration += st.back()[1] - st.back()[0] + 1;
                st.pop_back();
            }
            st.push_back({end - duration + 1, end, st.back()[2] + duration});
        }
        return st.back()[2];
    }
};
