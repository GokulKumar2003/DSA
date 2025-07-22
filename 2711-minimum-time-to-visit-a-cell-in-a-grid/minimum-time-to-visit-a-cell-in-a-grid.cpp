class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1){
            return -1;
        }

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        
        vector<int> delRow = {-1, 1, 0, 0};
        vector<int> delCol = {0, 0, -1, 1};
        while(pq.size()){
            vector<int> arr = pq.top();
            int d = arr[0];
            int r = arr[1];
            int c = arr[2];
            pq.pop();

            for(int i=0;i<delRow.size();i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if(nr >=0 && nr < n && nc >= 0 && nc < m){
                    if(d >= grid[nr][nc]){
                        if(1 + d < dis[nr][nc]){
                            dis[nr][nc] = 1 + d;
                            pq.push({1+d, nr, nc});
                        }
                    }
                    else{
                        int diff = grid[nr][nc] - d;
                        int temp = d;
                        if(diff%2==0){
                            temp = grid[nr][nc] + 1;
                        }
                        else{
                           temp = grid[nr][nc];
                        }

                        if(temp < dis[nr][nc]){
                            dis[nr][nc] = temp;
                            pq.push({temp, nr, nc});
                        }
                    }
                }
            }

        }

        for(auto r:dis){
            for(auto c:r){
                cout << c << " ";
            }
            cout << endl;
        }
        return dis[n-1][m-1];
    }
};