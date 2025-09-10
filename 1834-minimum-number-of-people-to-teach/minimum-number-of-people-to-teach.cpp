class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        set<int> uncommon;
        for(auto f : friendships){
            map<int, int> m;
            for(int it : languages[f[0] - 1]){
                m[it] = 1;
            }
            bool flag = true;
            for(int it : languages[f[1] - 1]){
                if(m[it]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                uncommon.insert(f[0] - 1);
                uncommon.insert(f[1] - 1);
            }
        }
        int maxi = 0;
        vector<int> cnt(n, 0);
        for(int it:uncommon){
            for(int lang : languages[it]){
                cnt[lang-1]++;
                maxi = max(maxi, cnt[lang-1]);
            }
        }

        return uncommon.size() - maxi;
    }
};