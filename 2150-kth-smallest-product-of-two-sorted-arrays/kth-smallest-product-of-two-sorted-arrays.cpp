class Solution {
public:
    long long find(vector<int>& nums2, long long num1, long long p){
        int n2 = nums2.size();
        int left = 0, right = nums2.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(num1 >= 0 && nums2[mid]*num1 <= p ||
                num1 < 0 && nums2[mid]*num1 > p){
                    left = mid + 1;
            }
            else{
                right = mid - 1;
            }     
        }
        if(num1 >= 0){
            return left;
        }
        else{
            return nums2.size() - left;
        }
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        
        int n1 = nums1.size();
        long long left = -1e10, right = 1e10;
        while(left <= right){
            long long mid = left + (right - left)/2;
            long long c = 0;
            for(int it : nums1){
                c += find(nums2, it, mid);
            }
            if(c < k){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return left;
    }
};