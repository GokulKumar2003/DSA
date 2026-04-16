class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
        vector<int> arr = nums;
        for(int it:nums){
            arr.push_back(it);
        }
        vector<vector<int>> data(nums.size()*2, vector<int>(2, -1));
        map<int, int> leftInd;
        for(int i=0;i<arr.size();i++){
            if(leftInd.find(arr[i]) != leftInd.end()){
                data[i][0] = leftInd[arr[i]];
            }
            leftInd[arr[i]] = i;
        }
        
        map<int, int> rightInd;
        for(int i=arr.size()-1;i>=0;i--){
            if(rightInd.find(arr[i]) != rightInd.end()){
                data[i][1] = rightInd[arr[i]];
            }
            rightInd[arr[i]] = i;
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            //int newInd = queries[i] + nums.size();
            // if(data[newInd][0] != -1 && data[newInd][1] != -1){
            //     ans.push_back(min((int)abs(data[newInd][0] - newInd), (int)abs(data[newInd][1] - newInd)));
            // }
            // else if(data[newInd][0] != -1){
            //     ans.push_back(abs(data[newInd][0] - newInd));
            // }
            // else{
            //     ans.push_back(abs(data[newInd][1] - newInd));
            // }

            int ind = queries[i];
            int val = abs(data[ind][1] - ind);
            ind += nums.size();
            val = min(val, abs(ind - data[ind][0]));
            if(val == nums.size()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(val);
            }

        }
        return ans;
    }
};