class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> isVisited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j] == 1){
                    q.push({{i, j}, 0});
                    isVisited[i][j] = 1;
                }
            }
        }

        vector<int> delRow = {0, 0, -1, 1};
        vector<int> delCol = {-1, 1, 0, 0};
        while(q.size()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int h = q.front().second;
            q.pop();

            ans[r][c] = h;

            for(int i=0;i<delRow.size();i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && isVisited[nr][nc] == 0){
                    isVisited[nr][nc] = 1;
                    q.push({{nr, nc}, h+1});
                }
            }
        }

        return ans;
    }
};