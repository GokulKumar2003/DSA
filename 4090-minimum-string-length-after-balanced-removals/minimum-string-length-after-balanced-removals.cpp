class Solution {
public:
    int minLengthAfterRemovals(string s) {
        
        // int a = 0, b = 0;
        // for(char c:s){
        //     if(c == 'a'){
        //         a++;
        //     }
        //     else{
        //         b++;
        //     }
        // }

        // return abs(a-b);
        stack<char> st;
        for(char c:s){
            if(st.size()==0){
                st.push(c);
            }
            else if(st.top() != c){
                st.pop();
            }
            else{
                st.push(c);
            }
        }

        return st.size();
    }
};