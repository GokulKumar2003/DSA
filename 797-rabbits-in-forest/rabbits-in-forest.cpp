class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> m;

        for(int i=0;i<answers.size();i++){
            m[answers[i]]++;
        }

        int ans = 0;

        for(auto it=m.begin();it!=m.end();it++){
            if(it->first==0){
                ans += it->second;
            }
            else{
                ans += ((it->second)/(it->first+1)) * (it->first+1);
                if(it->second%(it->first + 1)){
                    ans += (it->first + 1);
                }
            }
            
        }

        return ans;
    }
};