class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, bool& flag, int r, int c){
        vis[r][c] = 1;
        int m = grid.size(), n = grid[0].size();
        vector<int> delRow = {0, 0, -1, 1};
        vector<int> delCol = {-1, 1, 0, 0};

        for(int i=0;i<delRow.size();i++){
            int nr = r + delRow[i];
            int nc = c + delCol[i];
            //cout << nr << " " << nc << endl;
            if(nr < 0 || nr >= m || nc < 0 || nc >= n){
                flag = false;
            }
            else if(vis[nr][nc] == 0 && grid[nr][nc] == 0){
                dfs(grid, vis, flag, nr, nc);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> vis(m ,vector<int>(n, 0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0 && vis[i][j] == 0){
                    bool flag = true;
                    dfs(grid, vis, flag, i, j);
                    if(flag){
                        ans++;
                    }
                }
            }
        }
        return ans;

    }
};