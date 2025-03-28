class Solution {
public:
    void dfs(int node, vector<int>& isVisited, vector<vector<int>>& adj, map<int, int>& pathNodes, int& longestCycleLength, int nodeNumber){
        
        isVisited[node] = 1;
        pathNodes[node] = nodeNumber;

        for(int it:adj[node]){
            if(!isVisited[it]){
                dfs(it, isVisited, adj, pathNodes, longestCycleLength, nodeNumber+1);
            }
            else{
                if(pathNodes.find(it) != pathNodes.end()){
                    int prevNum = pathNodes[it];
                    longestCycleLength = max(nodeNumber - prevNum + 1,
                                                longestCycleLength);
                }
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        
        int longestCycleLength = -1;
        int n = edges.size();
        vector<vector<int>> adj(n);

        for(int i=0; i < edges.size(); i++){
            if(edges[i] != -1){
                adj[i].push_back(edges[i]);
            }
        }

        vector<int> isVisited(n, 0);

        for(int node = 0; node < n; node++){
            map<int, int> pathNodes;
            int nodeNumber = 0;
            if(!isVisited[node]){
                dfs(node, isVisited, adj, pathNodes, longestCycleLength, 0);
            }
        }

        return longestCycleLength;
    }
};