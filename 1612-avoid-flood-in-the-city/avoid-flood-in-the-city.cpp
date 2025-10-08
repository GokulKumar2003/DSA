class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        map<int, int> m;
        set<int> st;

        vector<int> ans(rains.size(), 1);

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
       
        return ans;      
    }
};