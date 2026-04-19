class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        
        vector<vector<int>> grid(n, vector<int>(m, 0));
        priority_queue<vector<int>> pq;
        for(int i=0;i<sources.size();i++){
            grid[sources[i][0]][sources[i][1]] = sources[i][2];
            pq.push({sources[i][2], sources[i][0], sources[i][1]});
        }

        while(pq.size()){
            
            vector<vector<int>> nextCells;
            vector<int> rowDiff = {0, 0, -1, 1};
            vector<int> cellDiff = {-1, 1, 0, 0};
            while(pq.size()){
                vector<int> cellData = pq.top();
                for(int i=0;i<cellDiff.size();i++){
                    int nr = cellData[1] + rowDiff[i];
                    int nc = cellData[2] + cellDiff[i];
                    if(nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] == 0){
                        grid[nr][nc] = cellData[0];
                        nextCells.push_back({cellData[0], nr, nc});
                        
                    }
                    
                }
                pq.pop();                
            }
            for(int i=0;i<nextCells.size();i++){
                pq.push(nextCells[i]);
            }
        }

        return grid;

    }
};