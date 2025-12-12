/* Original Solution 1 */
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> userIds(numberOfUsers, 0);
        vector<int> onlineUser(numberOfUsers, 1);
        const int delay = 60;
        const int offset = 2;
        auto splitIds = [](auto&& ids) {
            int len = ids.length();
            vector<string> userIds;
            int i = 0;
            for (int j = 0; j < len; j++) {
                if (ids[j] == ' ') {
                    userIds.push_back(ids.substr(i, j - i));
                    i = j + 1;
                }
            }
            userIds.push_back(ids.substr(i, len - i));

            return userIds;
        };
        /* "Sort the sequence by timestamp in ascending order. For elements
         * with the same timestamp, sort them by their event priority
         */
        auto comp = [](const auto& lhs, const auto& rhs) {
            int lhsTime = stoi(lhs[1]);
            int rhsTime = stoi(rhs[1]);

            if (lhsTime < rhsTime) {
                return true;
            } else if (lhsTime == rhsTime) {
                return lhs.front() > rhs.front();
            }
            return false;
        };

        sort(events.begin(), events.end(), comp);

        for (const auto& event : events) {
            auto&& msgType = event[0];
            auto&& timeStamp = stoi(event[1]);
            auto&& users = splitIds(event[2]);

            if (msgType == "MESSAGE") {
                for (const auto& user : users) {
                    if (user == "ALL") {
                        for (int i = 0; i < numberOfUsers; i++) {
                            ++userIds[i];
                        }
                    } else if (user == "HERE") {
                        for (int i = 0; i < numberOfUsers; i++) {
                            if (onlineUser[i] <= timeStamp) {
                                ++userIds[i];
                            }
                        }
                    } else {
                        int i = stoi(user.substr(offset));
                        ++userIds[i];
                    }
                }
            } else {
                for (const auto& user : users) {
                    int id = stoi(user);
                    onlineUser[id] = timeStamp + delay;
                }
            }
        }

        return userIds;
    }
};





/* Official Solution 1 */
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> count(numberOfUsers);
        vector<int> next_online_time(numberOfUsers);
        sort(events.begin(), events.end(), [&](const vector<string> &lth, const vector<string> &rth) {
            int lth_timestamp = stoi(lth[1]);
            int rth_timestamp = stoi(rth[1]);
            if (lth_timestamp != rth_timestamp) {
                return lth_timestamp < rth_timestamp;
            }
            if (rth[0] == "OFFLINE") {
                return false;
            }
            return true;
        });
        
        for (auto&& event : events) {
            int cur_time = stoi(event[1]);
            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        count[i]++;
                    }
                } else if (event[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (next_online_time[i] <= cur_time) {
                            count[i]++;
                        }
                    }
                } else {
                    int idx = 0;
                    for (int i = 0; i < event[2].size(); i++) {
                        if (isdigit(event[2][i])) {
                            idx = idx * 10 + (event[2][i] - '0');
                        }
                        if (i + 1 == event[2].size() || event[2][i + 1] == ' ') {
                            count[idx]++;
                            idx = 0;
                        }
                    }
                }
            } else {
                int idx = stoi(event[2]);
                next_online_time[idx] = cur_time + 60;
            }
        }
        return count;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // 按照时间戳从小到大排序，时间戳相同的，离线事件排在前面
        ranges::sort(events, {}, [](auto& e) {
            return pair(stoi(e[1]), e[0][2]);
        });

        vector<int> ans(numberOfUsers);
        vector<int> online_t(numberOfUsers);
        for (auto& e : events) {
            int cur_t = stoi(e[1]); // 当前时间
            string& mention = e[2];
            if (e[0][0] == 'O') { // 离线
                online_t[stoi(mention)] = cur_t + 60; // 下次在线时间
            } else if (mention[0] == 'A') { // @所有人
                for (int& cnt : ans) {
                    cnt++;
                }
            } else if (mention[0] == 'H') { // @所有在线用户
                for (int i = 0; i < numberOfUsers; i++) {
                    if (online_t[i] <= cur_t) { // 在线
                        ans[i]++;
                    }
                }
            } else { // @id
                for (const auto& part : mention | ranges::views::split(' ')) {
                    string s(part.begin() + 2, part.end());
                    ans[stoi(s)]++;
                }
            }
        }
        return ans;
    }
};

/* Official Solution 3 */
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers);
        vector<tuple<int, int, int>> es; // (timestamp, type, id)
        int all = 0;
        for (auto& e : events) {
            int cur_t = stoi(e[1]); // 当前时间
            string mention = e[2];
            if (e[0][0] == 'O') { // 离线
                int i = stoi(mention);
                es.emplace_back(cur_t, 1, i);
                es.emplace_back(cur_t + 60, -1, i);
            } else if (mention[0] == 'A') { // @所有人
                all++;
            } else if (mention[0] == 'H') { // @所有在线用户
                all++;
                es.emplace_back(cur_t, 2, -1);
            } else { // @id
                for (const auto& part : mention | ranges::views::split(' ')) {
                    string s(part.begin() + 2, part.end());
                    ans[stoi(s)]++;
                }
            }
        }

        ranges::sort(es);

        int here = 0;
        for (auto& [_, type, id] : es) {
            if (type == 2) {
                here++;
            } else {
                // 注意 HERE 排在后面，还没有计入发生在此刻的 HERE 消息
                ans[id] += type * here; // type=1 是加，-1 是减
            }
        }

        for (int& cnt : ans) {
            cnt += all;
        }
        return ans;
    }
};
