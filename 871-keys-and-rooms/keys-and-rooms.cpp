class Solution {
public:
    void dfs(int room, vector<int> adj[], vector<int>& isVisited){
        isVisited[room] = 1;

        for(int it : adj[room]){
            if(!isVisited[it]){
                dfs(it, adj, isVisited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int numberOfRooms = rooms.size(); // in constraints
        vector<int> isVisited(numberOfRooms, 0); /* 0 -> not visited, 1 -> visited */
        vector<int> adj[numberOfRooms];

        /* creating adj matrix */
        for(int room=0; room<rooms.size();room++){
            for(int key : rooms[room]){
                adj[room].push_back(key);
            }
        }
        /* performing DFS from room 0 since it is already opened */
        dfs(0, adj, isVisited);

        for(int it : isVisited){
            if(it == 0){
                return false;
            }
        }

        return true;
    }
};