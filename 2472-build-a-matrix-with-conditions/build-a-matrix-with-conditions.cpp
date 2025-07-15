class Solution {
public:
    // void dfs(int node, vector<int>& vis, vector<int> adj[], vector<int>& order){
    //     vis[node] = 1;

    //     for(int it:adj[node]){
    //         if(vis[it] == 0){
    //             dfs(it, vis, adj, order);
    //         }
    //     }

    //     order.push_back(node);
    // }

    bool topo(int k, vector<int> adj[], vector<int>& order, vector<int>& edge){

        queue<int> q;
        for(int i=1;i<=k;i++){
            if(edge[i] == 0){
                q.push(i);
            }
        }

        while(q.size()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(int it:adj[node]){
                edge[it]--;
                if(edge[it] == 0){
                    q.push(it);
                }
            }
        }

        return order.size() >= k;

    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> rowAdj[k+1];
        vector<int> colAdj[k+1];
        vector<int> incomingEdge1(k+1, 0), incomingEdge2(k+1, 0);
        for(int i=0;i<rowConditions.size();i++){
            rowAdj[rowConditions[i][0]].push_back(rowConditions[i][1]);
            incomingEdge1[rowConditions[i][1]]++;
        }

        for(int i=0;i<colConditions.size();i++){
            colAdj[colConditions[i][0]].push_back(colConditions[i][1]);
            incomingEdge2[colConditions[i][1]]++;
        }

        vector<int> rowOrder, colOrder;

        if(!topo(k, rowAdj, rowOrder, incomingEdge1) || !topo(k, colAdj, colOrder, incomingEdge2)){
            return {};
        }

        cout << "row" << endl;
        for(int it:rowOrder){
            cout << it << " ";
        }
        cout << endl;

        cout << "col" << endl;
        for(int it:colOrder){
            cout << it << " ";
        }
        cout << endl;
        map<int, int> colMap;
        for(int i=0;i<colOrder.size();i++){
            colMap[colOrder[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i=0;i<rowOrder.size();i++){
            ans[i][colMap[rowOrder[i]]] = rowOrder[i];
        }

        return ans;

    }
};