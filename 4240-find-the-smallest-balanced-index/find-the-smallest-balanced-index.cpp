class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        
        int mod = 1e9+7;
        unsigned long long prod = 1;
        unsigned long long sum = 0;
        for(int it:nums){
            // prod = (unsigned long long)(it)*prod;
            sum = sum + (unsigned long long)it;
        }

        
        for(int i=nums.size()-1;i>=0;i--){
            sum -= nums[i];
            if(sum%mod == prod){
                return i;
            }
            prod = prod*(unsigned long long)(nums[i])%mod;
        }
        return -1;
    }
};