class Solution {
public:
    string removeSubstring(string s, int k) {
        
        stack<int> st;

        for(char c:s){
            if(c == '('){
                if(st.size() == 0 || st.top() < 0){
                    st.push(1);
                }
                else if(st.top() > 0){
                    int cnt = st.top();
                    st.pop();
                    st.push(cnt+1);
                }
            }
            else if(c == ')'){
                if(st.size() == 0 || st.top() > 0){
                    st.push(-1);
                }
                else if(st.top() < 0){
                    int cnt = st.top();
                    st.pop();
                    st.push(cnt - 1);
                }

                if(st.size() >= 2){
                    if(st.top() < 0){
                        int cnt1 = st.top();
                        st.pop();
                        int cnt2 = st.top();
                        st.pop();

                        if(abs(cnt1) >= k && cnt2 >= k){
                            if(cnt2-k){
                                st.push(cnt2-k);
                            }
                            if(cnt1+k){
                                st.push(cnt1+k);
                            }
                        }
                        else{
                            st.push(cnt2);
                            st.push(cnt1);
                        }
                        
                    }
                }
            }
        }

        string ans = "";
        while(st.size()){
            int cnt = st.top();
            if(cnt>0){
                while(cnt--){
                    ans += '(';
                }
            }
            else if(cnt < 0){
                cnt = abs(cnt);
                while(cnt--){
                    ans += ')';
                }
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};