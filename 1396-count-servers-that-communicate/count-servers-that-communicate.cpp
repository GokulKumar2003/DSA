class Solution {
public:
    bool checkRow(vector<int>& row, int r, int col){

        for(int c=0;c<row.size();c++){
            if(c != col && row[c] == 1){
                return true;
            }
        }
        return false;
    }
    bool checkCol(vector<vector<int>>& grid, int row, int c){

        for(int r=0;r<grid.size();r++){
            if(r != row && grid[r][c] == 1){
                return true;
            }
        }
        return false;
    }
    int countServers(vector<vector<int>>& grid) {
        
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    if(checkRow(grid[i], i, j) || checkCol(grid, i, j)){
                        cnt += 1;
                    }
                }
            }
        }
        return cnt;
    }
};