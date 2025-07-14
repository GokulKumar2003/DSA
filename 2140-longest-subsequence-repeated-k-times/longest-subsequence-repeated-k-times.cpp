class Solution {
public:
    bool isValid(string s1, string s2, int k){

        int ind1 = 0, ind2 = 0, cnt = 0;
        while(ind1 < s1.length()){
            if(s1[ind1] == s2[ind2]){
                ind1++;
                ind2++;
            }
            else{
                ind1++;
            }
            if(ind2 == s2.length()){
                cnt++;
                ind2=0;
            }
        }
        
        return cnt >= k;
    }
    
    string longestSubsequenceRepeatedK(string s, int k) {
        
        /* first generate a subseq and check if it comes k-1 times in the rem string */
        string str = "", ans = "";
        queue<string> q;
        q.push("");
        while(q.size()){
            string pref = q.front();
            q.pop();
            for(char c='a';c<='z';c++){
                string new_pref = pref + c;
                if(isValid(s, new_pref, k)){
                    ans = new_pref;
                    q.push(new_pref);
                }
            }
        }

        return ans;
    }
};