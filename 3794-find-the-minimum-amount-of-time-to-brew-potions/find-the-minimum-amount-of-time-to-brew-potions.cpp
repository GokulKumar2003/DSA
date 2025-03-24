class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {

        int n = skill.size(), m = mana.size();

        vector<long long> time(n+1);

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                time[i+1] = max(time[i+1], time[i]) + skill[i]*mana[j];
            }

            for(int i=n-1;i>0;i--){
                time[i] = time[i+1] - skill[i]*mana[j];
            }
        }

        return time.back();
    }
};