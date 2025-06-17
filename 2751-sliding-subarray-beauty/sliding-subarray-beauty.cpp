class Solution {
public:
    int getXthSmallestNumber(vector<int>& freq, int x){

        for(int i=0;i<freq.size();i++){
            x -= freq[i];
            if(x <= 0){
                if(i < 50){
                    return i - 50;
                }
                return 0;
            }
        }

        return 0;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        vector<int> freq(101, 0);
        int i = 0, j = 0;
        vector<int> ans;
        while(j < nums.size()){
            freq[nums[j] + 50]++;

            if(j - i + 1 >= k){
                ans.push_back(getXthSmallestNumber(freq, x));
                freq[nums[i] + 50]--;
                i++;
            }
            j++;
        }

        return ans;
    }
};