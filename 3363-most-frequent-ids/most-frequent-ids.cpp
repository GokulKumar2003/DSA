class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        
        map<int, long long> m;
        set<pair<long long, int>> s;

        vector<long long> ans;

        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = freq[i];
                s.insert({-1*freq[i], nums[i]});
            }
            else{
                s.erase({-1*m[nums[i]], nums[i]});
                m[nums[i]] += freq[i];
                s.insert({-1*m[nums[i]], nums[i]});
            }
            pair<long long, int> p = *s.begin();
            ans.push_back(-1*p.first);
        }

        return ans;
    }
};