class Solution {
public:
    vector<string> partitionString(string s) {
        
        set<string> st;
        string str;
        vector<string> ans;

        for(int i=0;i<s.length();i++){
            str += s[i];
            if(st.find(str) == st.end()){
                st.insert(str);
                ans.push_back(str);
                str = "";
            }
        }

        return ans;
    }
};