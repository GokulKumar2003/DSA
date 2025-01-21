class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
         long long firstRobotMaxScore = 0, secondRobotMaxScore=LLONG_MAX;
        long long row1Sum=0, row2Sum=0;
        int n = grid[0].size();
        for(int i=0;i<n;i++){
            row1Sum += grid[0][i];
            row2Sum += grid[1][i];
        }

        //anyways it has to go down one step inorder to reach
        // the dest. but it can be any cell. so we calculate all possible ways;
        long long score=0;
        long long pref1=0, pref2=0;
        for(int col=0;col<grid[0].size();col++){
            pref1 += grid[0][col];
            secondRobotMaxScore = min(secondRobotMaxScore, max((row1Sum-pref1), pref2));
            pref2 += grid[1][col];
        }

        return secondRobotMaxScore;
    }
};