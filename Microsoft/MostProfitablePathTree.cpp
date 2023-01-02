/*
problem: https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

SOLUTION:

*/

class Solution {
public:
    void dfs(int u, vector<int> &p, vector<int> &dp, int t=0) {
        if(u<0) return;
        dp[u]=t;
        dfs(p[u],p,dp,t+1);        
    }

    int dfs1(int u, int pv, vector<vector<int>> &ch, vector<int> &a, vector<int> &dp, int t=0) {
        int sf = -1e9;
        bool flg=0;
        for(auto i:ch[u]) {
            if(i==pv) continue;
            flg=1;
            sf=max(sf,dfs1(i,u,ch,a,dp,t+1));
            // cout<<u<<"->"<<i<<": "<<sf<<"\n";
        }
        if(!flg) sf=0;
        // cout<<u<<": "<<(dp[u]<=t?(dp[u]<t?0:a[u]/2):a[u])<<" "<<sf<<"\n";
        return (dp[u]<=t?(dp[u]<t?0:a[u]/2):a[u]) + sf;
    }
    
    void buildP(int u, vector<int> &p, vector<vector<int>> &ch, int pv=-1) {
        for(auto i:ch[u]) {
            if(i==pv) continue;
            p[i]=u;
            buildP(i,p,ch,u);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<int> p(n,-1);
        vector<vector<int>> ch(n);
        // construct adj list
        for(auto i:edges) {
            ch[i[0]].push_back(i[1]);
            ch[i[1]].push_back(i[0]);
        }
        // build parent arrat our of adj list
        buildP(0,p,ch);
        // dp[i] = time when bob reaches node i
        vector<int> dp(n,1e6);
        dfs(bob,p,dp);
        // dfs1(i) = max amount of alice from subtree rooted at i
        return dfs1(0,-1,ch,amount,dp);
    }
};
