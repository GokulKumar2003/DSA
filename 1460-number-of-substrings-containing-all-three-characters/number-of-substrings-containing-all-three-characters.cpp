class Solution {
public:
    int numberOfSubstrings(string s) {
         map<char,int> m;
        int i=0,j=0,ans=0;

        for(int i=0;i<s.length();i++){

            m[s[i]] += 1;

            while(m['a'] && m['b'] && m['c']){
                ans += s.length()-i;

                m[s[j]] -= 1;
                j += 1;
            }
        }

        return ans;
    }
};