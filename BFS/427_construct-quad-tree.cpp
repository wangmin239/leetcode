/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    using pii = pair<int, int>;
    Node* construct(vector<vector<int>>& grid) {
        return dfs(make_pair(0, 0), grid.size(), grid);
    }
    
    bool isSame = true;
    Node* dfs(const pii& point, int len, vector<vector<int>>& grid) {
        int x = point.first;
        int y = point.second;
        int val = grid[x][y];
        
        if (len == 1) {
            return new Node(val, true);
        }
        
        bool isSame = true;
        for (int row = 0; row < len; row++) {
            for (int col = 0; col < len; col++) {
                int rowIndex = x + row;
                int colIndex = y + col;
              
                if (val != grid[rowIndex][colIndex]) {
                    isSame = false;
                    goto DIFF;
                }
            }
        }
           
        if (isSame == true) {
            return new Node(val, true);
        }
DIFF: 
        len >>= 1;
        auto topLeft = dfs(make_pair(x, y), len, grid);
        auto topRight = dfs(make_pair(x, y + len), len, grid);
        auto bottomLeft = dfs(make_pair(x + len, y), len, grid);
        auto bottomRight = dfs(make_pair(x + len, y + len), len, grid);
        return new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);    
    }
};



class Solution {
public:
    Node *construct(vector<vector<int>> &grid) {
        function<Node*(int, int, int, int)> dfs = [&](int r0, int c0, int r1, int c1) {
            for (int i = r0; i < r1; ++i) {
                for (int j = c0; j < c1; ++j) {
                    if (grid[i][j] != grid[r0][c0]) { // 不是叶节点
                        return new Node(
                                true,
                                false,
                                dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
                                dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
                                dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
                                dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1)
                        );
                    }
                }
            }
            // 是叶节点
            return new Node(grid[r0][c0], true);
        };
        return dfs(0, 0, grid.size(), grid.size());
    }
};


class Solution {
public:
    Node *construct(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<int>> pre(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        auto getSum = [&](int r0, int c0, int r1, int c1) {
            return pre[r1][c1] - pre[r1][c0] - pre[r0][c1] + pre[r0][c0];
        };

        function<Node *(int, int, int, int)> dfs = [&](int r0, int c0, int r1, int c1) {
            int total = getSum(r0, c0, r1, c1);
            if (total == 0) {
                return new Node(false, true);
            }
            if (total == (r1 - r0) * (c1 - c0)) {
                return new Node(true, true);
            }
            return new Node(
                    true,
                    false,
                    dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
                    dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
                    dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
                    dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1)
            );
        };

        return dfs(0, 0, n, n);
    }
};
