class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<long long> ans(nums1.size(), 0);
        vector<vector<int>> arr; //{val, ind}

        for(int i=0;i<nums1.size();i++){
            arr.push_back({nums1[i], i});
        }

        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;

        ans[arr[0][1]] = 0;
        sum = nums2[arr[0][1]];
        pq.push(nums2[arr[0][1]]);
        for(int i=1;i<arr.size();i++){

            int val = arr[i][0];
            int ind = arr[i][1];

            if(val == arr[i-1][0]){
                ans[ind] = ans[arr[i-1][1]];
            }
            else{
                ans[ind] = sum;
            }
            sum += nums2[ind];
            pq.push(nums2[ind]);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
        }

        return ans;
    }
};