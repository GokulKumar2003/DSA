class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c,queue<pair<int, int>>& q){

        int n = grid.size();
        vis[r][c] = 1;
        q.push({r, c});

        vector<int> delRow = {0, 0, -1, 1};
        vector<int> delCol = {-1, 1, 0, 0};
        for(int i=0;i<delRow.size();i++){
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 1){
                dfs(grid, vis, nr, nc, q);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dfs(grid, vis, i, j, q);
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        int bridgeLength = 0;
        vector<int> delRow = {0, 0, -1, 1};
        vector<int> delCol = {-1, 1, 0, 0};
        while(!q.empty()){
            int s = q.size();
            cout << s << endl;
            while(s--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i=0;i<delRow.size();i++){
                    int nr = r + delRow[i];
                    int nc = c + delCol[i];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                        if(vis[nr][nc] == 0 && grid[nr][nc] == 1){
                            return bridgeLength;
                        }
                        else if(vis[nr][nc] == 0){
                            vis[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            bridgeLength++;
        }

        return bridgeLength;
    }
};