class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int max_sum = INT_MIN, min_sum = INT_MAX, sum = 0;

        // finding max sum
        for(int it:nums){
            sum += it;

            if(sum > max_sum){
                max_sum = sum;
            }

            if(sum < 0){
                sum = 0;
            }
        }

        sum = 0;
        //finding min sum
        for(int it:nums){
            sum += it;

            if(sum < min_sum){
                min_sum = sum;
            }

            if(sum > 0){
                sum = 0;
            }
        }

        return max(max_sum, abs(min_sum));
    }
};