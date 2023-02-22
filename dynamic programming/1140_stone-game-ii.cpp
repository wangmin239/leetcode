class Solution {
public:
    int count=0;
    int max_count=0;
    vector<vector<int>> used;
    vector<int> pre;
    int stoneGameII(vector<int>& piles) {
         int n=piles.size();
        used=vector<vector<int>>(2*n,vector<int>(2*n,0));
        pre.resize(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+piles[i];
        }
        int res=dfs(piles,0,1);
        // 假设alice总得分为a, bob总得分为b, 那么res=a-b, pre[len]=a+b, 我们求的是a, 因此a=(pre[n] + res) / 2
        return (pre[n]+res)/2;
    }

    int dfs(vector<int>& piles, int k, int M){
        if(used[k][M]!=0){
            return used[k][M];
        }
        int n=piles.size();
        if(n-k<=2*M){
            used[k][M]=pre[n]-pre[k];
            return used[k][M];
        }
                
        int X=1;
        int res=INT_MIN;
        for(int i=k+1;(i-k<=2*M&&i<n);i++){
            int choose_left=pre[i]-pre[k];
            res=max(res,choose_left-dfs(piles,i,max(M,X)));
            X++;
        }
        used[k][M]=res;
        return used[k][M];
    }
};
