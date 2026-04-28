class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long a = 0, d = 0;
        int flag = 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] <= nums[i+1]){
                a += nums[i];
            }
            else{
                if(flag){
                    a += nums[i];
                    flag = 0;
                }
                d += nums[i];
            }
        }
        d += nums[nums.size()-1];

        if(a > d){
            return 0;
        }
        if(d > a){
            return 1;
        }
        return -1;
    }
};