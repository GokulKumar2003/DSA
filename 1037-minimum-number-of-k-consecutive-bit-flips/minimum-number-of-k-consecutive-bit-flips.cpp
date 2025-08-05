class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        // brute force

        // int cnt = 0;

        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] == 0){
        //         if(i+k > nums.size()){
        //             return -1;
        //         }
        //         cnt++;
        //         for(int j=i;j<i+k;j++){
        //             if(nums[j] == 0){
        //                 nums[j] = 1;
        //             }
        //             else{
        //                 nums[j] = 0;
        //             }
        //         }
        //     }
        // }

        // return cnt;


        int current_flips = 0, ans = 0;
        int i=0,j=0;
        while(j<nums.size()){
            
            if(j>=k){
                if(nums[i] == 2){
                    current_flips--;
                }
                i++;
            }

            if((current_flips%2 == 0 && nums[j] == 0) || (current_flips%2 == 1 && nums[j] == 1)){
                if(j+k > nums.size()){
                    return -1;
                }
                nums[j] = 2;
                current_flips++;
                ans++;
            }

            j++;
        }
        return ans;
    }
};