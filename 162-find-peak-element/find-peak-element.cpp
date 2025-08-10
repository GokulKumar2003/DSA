class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int l = 0, r = nums.size()-1, mid;

        while(l<r){
            
            mid = l + (r-l)/2;
            if(mid + 1 < nums.size() && nums[mid] < nums[mid+1]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }

        return l;
    }
};