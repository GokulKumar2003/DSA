class Solution {
public:
    void dfs(int start, int node, vector<vector<int>>& adj, vector<vector<int>>& ans, vector<int>& vis){

        vis[node] = 1;
        for(int it:adj[node]){
            if(!vis[it]){
                ans[start].push_back(it);
                dfs(start, it, adj, ans, vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> ans(n);
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++){
            vector<int> vis(n, 0);
            dfs(i, i, adj, ans, vis);
        }

        for(int i=0;i<n;i++){
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};