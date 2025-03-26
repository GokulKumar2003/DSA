class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> arr;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(), arr.end());
        int mid = arr[arr.size()/2], ans=0;

        for(int it : arr){
            if(it%x != mid%x){
                return -1;
            }
            ans += abs(it-mid)/x;
        }

        return ans;
    }
};