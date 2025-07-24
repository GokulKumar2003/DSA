class Solution {
public:
    int findCommonPrefLen(string s1, string s2){

        int i=0,j=0;

        while(i<s1.length() && j<s2.length()){
            if(s1[i] != s2[j]){
                return i;
            }
            i++;
            j++;
        }

        if(i==j){
            return i;
        }
        return 0;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        
        int n = words.size();
        vector<int> ans(n, 0);
        
        int prefMaxi = 0;
        for(int i=0;i<words.size();i++){
            ans[i] = prefMaxi;
            if(i>0 && i+1<n){
                ans[i] = max(ans[i] , findCommonPrefLen(words[i-1], words[i+1]));
            }
            if(i>0){
                prefMaxi = max(prefMaxi, findCommonPrefLen(words[i-1], words[i]));
            }  
        }
        
        int suffMaxi = 0;
        for(int i=n-1;i>=0;i--){
            ans[i] = max(ans[i], suffMaxi);
            if(i<n-1){
                suffMaxi = max(suffMaxi, findCommonPrefLen(words[i], words[i+1]));
            }
        }

        return ans;
    }
};