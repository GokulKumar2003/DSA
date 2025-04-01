class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node, int& mini, int& quietPerson, vector<int>& quiet){
        vis[node] = 1;

        for(int it:adj[node]){
            if(!vis[it]){
                if(quiet[it] < mini){
                    mini = quiet[it];
                    quietPerson = it;
                }
                dfs(adj, vis, it, mini, quietPerson, quiet);
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n = quiet.size();
        vector<int> ans(n);
        vector<vector<int>> adj(n);

        for(int i=0;i<richer.size();i++){
            adj[richer[i][1]].push_back(richer[i][0]);
        }

        for(int i=0;i<n;i++){
            int mini = quiet[i], quietPerson = i;
            vector<int> vis(n);
            dfs(adj, vis, i, mini, quietPerson, quiet);
            ans[i] = quietPerson;
        }

        return ans;
    }
};