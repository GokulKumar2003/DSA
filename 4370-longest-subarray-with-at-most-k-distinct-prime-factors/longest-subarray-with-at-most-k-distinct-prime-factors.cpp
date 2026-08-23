class Solution {
public:
    bool isPrime(int num){
        if(num <= 1){
            return false;
        }

        for(int i=2;i<=sqrt(num);i++){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
    int longestSubarray(vector<int>& nums, int k) {
        
        int maxi = *max_element(nums.begin(), nums.end());
        vector<set<int>> seive(maxi+1);
        for(int i=0;i<=maxi;i++){
            if(isPrime(i)){
                for(int j=i;j<seive.size();j += i){
                    seive[j].insert(i);
                }
            }
        }

        int i=0,j=0;
        map<int, int> m;
        int ans = 0;
        while(j<nums.size()){
            for(auto itr : seive[nums[j]]){
                m[itr]++;
            }
            while(i<=j && m.size()>k){
                for(auto itr : seive[nums[i]]){
                    m[itr]--;
                    if(m[itr] == 0){
                        m.erase(itr);
                    }
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;

    }
};