class Solution {
public:
    long long calculateScore(string s) {
        
        long long score = 0;
        map<int, vector<int>> m;
        for(int i=0;i<s.length();i++){
            int mirror = 25 - (s[i] - 'a');
            if(m.find(mirror) != m.end() && m[mirror].size() > 0){
                score += i - m[mirror].back();
                m[mirror].pop_back();
                
            }
            else{
                m[s[i] - 'a'].push_back(i);
            }
        }
        return score;
    }
};