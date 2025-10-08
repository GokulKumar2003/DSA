class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        map<int, int> m;
        set<int> st;

        vector<int> ans = rains;

        for(int i=0;i<rains.size();i++){
            if(rains[i]){
                ans[i] = -1;
                if(m.find(rains[i]) == m.end()){
                    m[rains[i]] = i;
                }
                else{
                    int ind = m[rains[i]];
                    auto it = st.lower_bound(ind);
                    if(it == st.end()){
                        return {};
                    }
                    ans[*it] = rains[i];
                    m[rains[i]] = i;
                    st.erase(*it);
                }
            }
            else{
                st.insert(i);
            }
            
        }
       
       for(int i=0;i<ans.size();i++){
        if(ans[i] == 0){
            ans[i] = 1;
        }
       }
        return ans;      
    }
};