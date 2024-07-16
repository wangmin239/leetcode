class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void unionSet(int index1, int index2) {
        parent[find(index2)] = find(index1);
    }

    int find(int index) {
        if (parent[index] != index) {
            parent[index] = find(parent[index]);
        }
        return parent[index];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emailToIndex;
        map<string, string> emailToName;
        int emailsCount = 0;
        for (auto& account : accounts) {
            string& name = account[0];
            int size = account.size();
            for (int i = 1; i < size; i++) {
                string& email = account[i];
                if (!emailToIndex.count(email)) {
                    emailToIndex[email] = emailsCount++;
                    emailToName[email] = name;
                }
            }
        }
        UnionFind uf(emailsCount);
        for (auto& account : accounts) {
            string& firstEmail = account[1];
            int firstIndex = emailToIndex[firstEmail];
            int size = account.size();
            for (int i = 2; i < size; i++) {
                string& nextEmail = account[i];
                int nextIndex = emailToIndex[nextEmail];
                uf.unionSet(firstIndex, nextIndex);
            }
        }
        map<int, vector<string>> indexToEmails;
        for (auto& [email, _] : emailToIndex) {
            int index = uf.find(emailToIndex[email]);
            vector<string>& account = indexToEmails[index];
            account.emplace_back(email);
            indexToEmails[index] = account;
        }
        vector<vector<string>> merged;
        for (auto& [_, emails] : indexToEmails) {
            sort(emails.begin(), emails.end());
            string& name = emailToName[emails[0]];
            vector<string> account;
            account.emplace_back(name);
            for (auto& email : emails) {
                account.emplace_back(email);
            }
            merged.emplace_back(account);
        }
        return merged;
    }
};



class Solution 
{
    private:
        // f记录每个人名的父辈是谁
        // isAppeared保存已经出现过的邮箱地址
        // father记录每个邮箱的父辈是谁
        vector<int> f;
        unordered_set<string> isAppeared;
        unordered_map<string, int> father;

    public:
        // 并查集的通用代码，find(x)查找父辈
        int find(int x)
        {
            return x == f[x] ? x : find(f[x]);
        }

        // 并查集的通用代码，merge(x, y)合并父辈
        void merge(int x, int y)
        {
            int xFather = find(x);
            int yFather = find(y);

            if(xFather != yFather) f[yFather] = xFather;
        }

        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
        {
            // 定义res作为最后的返回结果
            vector<vector<string>> res;

            // 初始化f，所有人名初始默认自身为父辈
            f = vector<int>(accounts.size());
            for(int i=0; i < f.size(); i++) f[i] = i;

            // 遍历每个人名下的每个邮箱，遍历结束后会得到更新后的父辈关系表f
            for(int i=0; i < accounts.size(); i++)
            {
                for(int j=1; j < accounts[i].size(); j++)
                {
                    // 判断该邮箱是否是第一次出现
                    //   1. 若是，将其加入isAppeared；因为人名会出现重复，改为记录第一次出现该邮箱的人名的位置
                    //   2. 若不是，说明邮箱已经被使用了，那么这两个人是同一个人，所以要改变当前人名的父辈关系，即合并
                    if(!isAppeared.count(accounts[i][j]))
                    {
                        isAppeared.insert(accounts[i][j]);
                        father[accounts[i][j]] = i;
                    }
                    else
                    {
                        merge(father[accounts[i][j]], i);
                    }
                }
            }

            // 遍历accounts中每个人名，寻找每个人名的父辈，并将该人名下所有邮箱保存到一起
            // 由于会存在重复邮箱，且要考虑邮箱顺序，所以使用set<string>来去重并内部自动排序
            unordered_map<int, set<string>> accMail;
            for(int i=0; i < accounts.size(); i++)
            {
                int t = find(i);
                int len = accounts[i].size();

                for(int j=1; j < len; j++) accMail[t].insert(accounts[i][j]);
            }

            // 遍历accMail，其中每一项为<人名位置， 该人名下所有的邮箱>
            // 将其转化为题目需要的返回格式
            for(auto acc: accMail)
            {
                vector<string> ans;

                ans.push_back(accounts[acc.first][0]);
                for(auto mail: acc.second) ans.push_back(mail);

                res.push_back(ans);
            }

            return res;
        }
};




class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<bool> isVisited(n, false);
        unordered_map<string, vector<int>> emails;
        
        /* record the index of the every email address */
        for (int i = 0; i < n; i++) {
            for (auto iter = accounts[i].begin() + 1; iter != accounts[i].end(); ++iter) {
                emails[*iter].push_back(i);
            }
        }
        
        vector<vector<string>> ans;
        unordered_set<string> usedEmails;
        auto dfs = [&](const vector<int>& ids, auto&& innerDfs) ->void {
            for (int id : ids) {
                if (isVisited[id] == true) {
                    continue;
                }
                isVisited[id] = true;
                for (auto iter = accounts[id].begin() + 1; iter != accounts[id].end(); ++iter) {
                   if (usedEmails.count(*iter) == 0) {
                       usedEmails.insert(*iter);
                       ans.back().push_back(*iter);
                       innerDfs(emails[*iter], innerDfs);
                    }
                }
            }

        };        
    
        /* who own the emails */
        for (auto& [email, ids] : emails) {

            if (usedEmails.count(email)) {
                continue;
            }
            
            string name(accounts[ids.front()].front());
            ans.push_back({name, email});
            usedEmails.insert(email);            
            dfs(emails[email], dfs);
        }
        /* sorted the emails */
        for (auto& vec : ans) {
            sort(vec.begin() + 1, vec.end());
        }
        
        
        return ans;
    }
};