class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        /* obstacles removed so far, row, col */
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        /* 2d vector to store the min no of obstacles that has to be removed to reach {r, c} */
        vector<vector<int>> minObs(m, vector<int>(n, INT_MAX));

        minObs[0][0] = 0;
        pq.push({0, 0, 0});
        vector<int> delRow = {-1, 1, 0, 0};
        vector<int> delCol = {0, 0, -1, 1};
        while(pq.size()){
            vector<int> data = pq.top();
            pq.pop();
            int r = data[1];
            int c = data[2];
            int obs = data[0];

            if(grid[r][c] == 1){
                obs++;
            }

            for(int i=0;i<delRow.size();i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && minObs[nr][nc] > obs){
                    minObs[nr][nc] = obs;
                    pq.push({obs, nr, nc});
                }
            }
        }

        return minObs[m-1][n-1];
    }
};