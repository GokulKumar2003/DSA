class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            adj[i].push_back(i);
        }

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++){
            sort(adj[i].begin(), adj[i].end());
        }

        map<vector<int>, int> m;
        for(int i=0;i<adj.size();i++){
            m[adj[i]]++;
        }

        int ans=0;
        for(auto it:m){
            if(it.first.size() == it.second){
                ans++;
            }
        }

        return ans;
    }
};