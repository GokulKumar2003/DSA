class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        // int num1Size = nums1.size(), num2Size = nums2.size();

        // map<int, int> m; //freq
        // for(int i=0;i<nums1.size();i++){
        //     m[nums1[i]] += num2Size%2;
        // }
        // for(int i=0;i<nums2.size();i++){
        //     m[nums2[i]] += num1Size%2;
        // }

        // int ans = 0;
        // for(auto it:m){
        //     if(it.second%2){
        //         ans ^= it.first;
        //     }
        // }
        // return ans;

        // optimized approach
        int num1Size = nums1.size(), num2Size = nums2.size();
        int xor1 = 0, xor2 = 0;
        if(num1Size % 2){
            for(int it : nums2){
                xor1 ^= it;
            }
        }

        if(num2Size % 2){
            for(int it : nums1){
                xor2 ^= it;
            }
        }

        return xor1 ^ xor2;

    }
};