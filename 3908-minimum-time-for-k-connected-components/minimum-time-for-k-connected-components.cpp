class Solution {
public:
    // void dfs(int node, vector<vector<vector<int>>>& adj, vector<int>& vis, int time){
    //     vis[node] = 1;

    //     for(auto it:adj[node]){
    //         if(vis[it[0]] == 0 && it[1] > time){
    //             dfs(it[0], adj, vis, time);
    //         }
            
    //     }
    // }
    // bool isPossible(int n, vector<vector<vector<int>>>& adj, int k, int mid){

    //     vector<int> vis(n, 0);
    //     int comp = 0;
    //     for(int i=0;i<n;i++){
    //         if(vis[i] == 0){
    //             comp++;
    //             dfs(i, adj, vis, mid);
    //         }
    //     }

    //     return comp >= k;
    // }
    // int minTime(int n, vector<vector<int>>& edges, int k) {

    //     vector<vector<vector<int>>> adj(n);
    //     int maxi = 0;
    //     for(int i=0;i<edges.size();i++){
    //         adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    //         adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    //         maxi = max(maxi, edges[i][2]);
    //     }
        
    //     int l = 0, r = maxi, mid, ans;

    //     while(l <= r){
    //         mid = l + (r - l)/2;

    //         if(isPossible(n, adj, k, mid)){
    //             ans = mid;
    //             r = mid - 1;
    //         }
    //         else{
    //             l = mid + 1;
    //         }
    //     }

    //     return ans;
    // }

     void dfs(vector<pair<int,int>> adj[], int n , int k , int mid, int src, vector<int>&vis){
        vis[src] = 1;
        for(auto &i : adj[src]){
            if(!vis[i.first] && i.second > mid){
                dfs(adj,n,k,mid,i.first,vis);
            }
        }
    }
    bool isKConnectedComponents(vector<pair<int,int>> adj[], int n , int k , int mid){
        vector<int> vis(n, 0);
        int cntCmp = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                cntCmp++;
                dfs(adj,n,k,mid,i, vis);
            }
        }
        return cntCmp >= k;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        vector<pair<int,int>> adj[n];
        int maxTime = 0;
        for(auto &i : edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
            maxTime = max(maxTime, i[2]);
        }
        int minTime = INT_MAX;
        int l = 0 , r = maxTime + 1;
        while(l <= r){
            int mid = (l + r) / 2;
            bool check = isKConnectedComponents(adj, n , k , mid);
            if(check){
                minTime = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return minTime;
    }
};