class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int cnt=0;
        for(int i=0;i<words.size();i++){
            int p1=0,p2=0;
            while(p1 < words[i].length() && p2 < pref.length() && words[i][p1] == pref[p2]){
                p1 += 1;
                p2 += 1;
            }
            if(p2 == pref.length()){
                cnt += 1;
            }
        }
        return cnt;
    }
};