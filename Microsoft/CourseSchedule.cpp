/*
https://leetcode.com/problems/course-schedule/description/

SOLUTION:

*/
class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, bool *vis, bool *stk) {
        stk[u]=1;
        for(auto i:adj[u]) {
            if(vis[i]) continue;
            if(stk[i] || !dfs(i,adj,vis,stk)) return 0;
        }
        stk[u]=0;
        vis[u]=1;
        return 1;
    }

    bool canFinish(int N, vector<vector<int>>& p) {
        vector<vector<int>> adj(N);
        for(auto i:p) {
            adj[i[0]].push_back(i[1]);
        }
        bool *vis = new bool[N]();
        for(int i=0;i<N;i++) {
            if(vis[i]) continue;
            bool *stk = new bool[N]();
            if(!dfs(i,adj,vis,stk)) return 0;
        }
        return 1;
    }
};
