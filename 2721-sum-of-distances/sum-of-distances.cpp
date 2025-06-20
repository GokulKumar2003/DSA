class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        
        map<int, vector<int>> m; // ele -> {idx}

        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }

        vector<long long> arr(nums.size(), 0);

        for(auto it : m){
            vector<int> indices = it.second;

            long long suffSum = 0;
            for(int idx : indices){
                suffSum += idx;
            }
            long long prefSum = 0;
            for(int i=0;i<indices.size();i++){
                suffSum -= indices[i];
                arr[indices[i]] = ((long long)i*(long long)indices[i] - prefSum) + (suffSum - ((long long)indices.size()-i-1)*(long long)indices[i]);
                prefSum += indices[i]; 
            }
        }

        return arr;
    }
};