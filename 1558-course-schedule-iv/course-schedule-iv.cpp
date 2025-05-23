class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis, int start, vector<vector<int>>& isReachable){
        vis[node] = 1;
    
        for(int it:adj[node]){
            if(vis[it] == 0){
                isReachable[start][it] = 1;
                dfs(adj, it, vis, start, isReachable);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> isReachable(numCourses, vector<int>(numCourses, 0));

        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses;i++){
            vector<int> vis(numCourses, 0);
            dfs(adj, i, vis, i, isReachable);
        }
        
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            if(isReachable[queries[i][0]][queries[i][1]] == 1){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};