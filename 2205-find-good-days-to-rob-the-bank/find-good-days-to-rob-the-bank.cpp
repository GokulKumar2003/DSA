class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        
        vector<int> ans;
        int n = security.size();
        vector<int> pref(n, 0), suff(n, 0);

        for(int i=1;i<n;i++){
            if(security[i] <= security[i-1]){
                pref[i] = pref[i-1] + 1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(security[i] <= security[i+1]){
                suff[i] = suff[i+1] + 1;
            }
        }

        for(int i=0;i<n;i++){
            cout << pref[i] << "  " << suff[i] << endl;
            if(pref[i] >= time && suff[i] >= time){
                ans.push_back(i);
            }
        }

        return ans;
    }
};