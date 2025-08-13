class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        
         unordered_map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            mp[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> dis(n,INT_MAX);
        dis[0]=0;
        set<pair<int, int>> st;
        st.insert({dis[0],0});
        while(st.size()){
            pair<int,int> topi = *(st.begin());
            st.erase(*st.begin());

            int currver = topi.second;
            int dist = topi.first;

            if (dist > dis[currver]) continue;

            for(int i=0;i<mp[currver].size();i++){
                if(dis[mp[currver][i].first] > dist + mp[currver][i].second){
                    if(disappear[mp[currver][i].first] > dist + mp[currver][i].second){
                        dis[mp[currver][i].first] = dist + mp[currver][i].second;
                        st.insert({dis[mp[currver][i].first],mp[currver][i].first});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX){
                dis[i]=-1;
            }
        } 
        return dis;
    }
};