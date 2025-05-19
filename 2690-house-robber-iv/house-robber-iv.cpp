class Solution {
public:
    bool isPossible(vector<int>& nums, int val, int k){

        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= val){
                cnt++;
                i++;
            }
        }
       
        return cnt >= k;

    }
    int minCapability(vector<int>& nums, int k) {
        

        int low = 1, high = *max_element(nums.begin(), nums.end()), mid, ans = 0;

        while(low <= high){
            mid = low + (high - low)/2;

            if(isPossible(nums, mid , k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};