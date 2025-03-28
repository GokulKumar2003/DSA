class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, vector<int>& vis, int node, int& minScore){
        vis[node] = 1;

        for(auto it : adj[node]){
            minScore = min(minScore, it.second);
            if(vis[it.first] == 0){
                dfs(adj, vis, it.first, minScore);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int, int>>> adj(n+1);

        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        vector<int> vis(n+1, 0);
        int minScore = INT_MAX;
        dfs(adj, vis, 1, minScore);
        
        return minScore;
    }
};