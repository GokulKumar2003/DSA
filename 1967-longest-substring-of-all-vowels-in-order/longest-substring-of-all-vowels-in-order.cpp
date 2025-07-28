class Solution {
public:
    int longestBeautifulSubstring(string word) {
        
        int i=0,j=1, ans = 0;
        set<char> st;
        st.insert(word[0]);
        while(j<word.length()){
            if(word[j] < word[j-1]){
                st.clear();
                st.insert(word[j]);
                i=j;
            }
            else{
                st.insert(word[j]);
            }
           
            if(st.size() == 5){
                ans = max(ans, j-i+1);
            }
            j++;
        }
        if(st.size() == 5){
            ans = max(ans, j-i);
        }
        
        return ans;
    }
};