class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, int node, int& minNumberOfReorientRoads, vector<int>& isVisited){

        isVisited[node] = 1;

        for(auto it : adj[node]){
            int adjNode = it.first;
            int flag = it.second;

            if(!isVisited[adjNode]){
                if(flag == 1){
                    minNumberOfReorientRoads++;
                }
                dfs(adj, adjNode, minNumberOfReorientRoads, isVisited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int, int>>> adj(n);

        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back({connections[i][1], 1});
            adj[connections[i][1]].push_back({connections[i][0], -1});
        }

        int minNumberOfReorientRoads = 0;
        vector<int> isVisited(n, 0);
        dfs(adj, 0, minNumberOfReorientRoads, isVisited);

        return minNumberOfReorientRoads;
    }
};