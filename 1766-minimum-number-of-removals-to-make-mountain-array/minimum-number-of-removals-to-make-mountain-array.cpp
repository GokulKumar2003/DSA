class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefLisCnt(n, 1), suffLisCnt(n, 1);

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    prefLisCnt[i] = max(prefLisCnt[i], prefLisCnt[j] + 1);
                }
            }
        }

        for(int i=nums.size()-2;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[i] > nums[j]){
                    suffLisCnt[i] = max(suffLisCnt[i], suffLisCnt[j] + 1);
                }
            }
        }
        for(auto it : prefLisCnt){
            cout << it << " ";
        }
        cout << endl;
        for(auto it : suffLisCnt){
            cout << it << " ";
        }
        cout << endl;
        int maxLen = 0;
        for(int i=0;i<prefLisCnt.size();i++){
            if(prefLisCnt[i] != 1 && suffLisCnt[i] != 1){
                maxLen = max(maxLen, prefLisCnt[i] + suffLisCnt[i] - 1);
            } 
        }

        return nums.size() - maxLen;
    }
};