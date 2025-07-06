class Solution {
public:
    void dfs(int node, vector<pair<int, int>> adj[], vector<int>& vis, int time){
        vis[node] = 1;

        for(auto it:adj[node]){
            if(vis[it.first] == 0 && it.second > time){
                dfs(it.first, adj, vis, time);
            }
            
        }
    }
    bool isPossible(int n, vector<pair<int, int>> adj[], int k, int mid){

        vector<int> vis(n, 0);
        int comp = 0;
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                comp++;
                dfs(i, adj, vis, mid);
            }
        }

        return comp >= k;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {

        vector<pair<int, int>> adj[n];
        int maxi = 0;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
            maxi = max(maxi, edges[i][2]);
        }
        
        int l = 0, r = maxi, mid, ans;

        while(l <= r){
            mid = l + (r - l)/2;

            if(isPossible(n, adj, k, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }

};