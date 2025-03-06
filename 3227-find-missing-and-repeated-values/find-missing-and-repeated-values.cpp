class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
                int n = grid.size(), a;
        long long sum = (n*n)*(n*n+1)/2, newSum=0;
        
        set<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s.find(grid[i][j]) == s.end()){
                    s.insert(grid[i][j]);
                    newSum += grid[i][j];
                }
                else{
                    a = grid[i][j];
                }
            }
        }
        int b = sum - newSum;
        return {a, b};

    }
};