class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        
        vector<int> arr;
        for(int it:nums){
            arr.push_back(abs(it));
        }

        sort(arr.begin(), arr.end());
        long long i=0,j=0, ans = 0;
        while(j<arr.size()){

            while(i<arr.size() && arr[j]*2 >= arr[i]){
                i++;
            }
            ans += (i-j-1);
            j++;
        }

        return ans;
    }
};