class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        vector<int> ans(heights.size(), 0);
        stack<int> st;

        for(int i=heights.size()-1;i>=0;i--){
            while(st.size() && heights[i] > heights[st.top()]){
                ans[i]++;
                st.pop();
            }
            if(st.size()){
                ans[i]++;
            }
            st.push(i);
        }
        return ans;
    }
};