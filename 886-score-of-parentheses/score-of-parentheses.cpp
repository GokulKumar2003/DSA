class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int score = 0;
        stack<int> st;

        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(score);
                score = 0;
            }
            else{
                score = st.top() + max(1, 2*score);
                st.pop();
            }
        }

        return score;
    }
};