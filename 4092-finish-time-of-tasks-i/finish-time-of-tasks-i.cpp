class Solution {
public:
    long long find(vector<int> adj[], int node, vector<int>& baseTime){
        if(adj[node].size() == 0){
            return baseTime[node];
        }

        long long mini = LLONG_MAX, maxi = 0;
        for(auto it : adj[node]){
            long long time = find(adj, it, baseTime);
            mini = min(mini, time);
            maxi = max(maxi, time);
        }

        long long ownTime = (maxi - mini) + baseTime[node];
        long long finishTime = ownTime + maxi;

        return finishTime;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        
        vector<int> adj[n];

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        return find(adj, 0, baseTime);
    }
};