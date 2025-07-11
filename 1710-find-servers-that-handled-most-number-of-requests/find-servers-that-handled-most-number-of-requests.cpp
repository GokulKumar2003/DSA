class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        int maxCnt = 0, busy = -1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<int> st;
        map<int, int> m;

        for(int i=0;i<k;i++){
            st.insert(i);
        }

        for(int i=0;i<arrival.size();i++){

            while(pq.size() && pq.top().first <= arrival[i]){
                int server = pq.top().second;
                pq.pop();
                st.insert(server);
            }

            int server = -1;
            if(st.find((i%k)) != st.end()){
                server = i%k;
                st.erase(server);
                pq.push({arrival[i] + load[i], server});
            }
            else{
                int req = i%k;
                if(st.size()){
                    if(st.lower_bound(req) != st.end()){
                        server = *st.lower_bound(req);
                    }
                    else{
                        server = *st.begin();
                    }
                    st.erase(server);
                    pq.push({arrival[i] + load[i], server});
                }
            }
            if(server != -1){
                m[server]++;
                if(m[server] > maxCnt){
                    maxCnt = m[server];
                }
            }
        }

        vector<int> ans;
        for(auto it:m){
            if(it.second == maxCnt){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};