class Solution {
public:
    vector<int> size;
    vector<int> parent;

    void init_DSU(int n){
        size.resize(n, 1);
        parent.resize(n, 0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){

        if(parent[node] == node){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void Union(int u, int v){

        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if(parent_u != parent_v){
            if(size[parent_u] >= size[parent_v]){
                size[parent_u] += size[parent_v];
                parent[parent_v] = parent[parent_u];
            }
            else{
                size[parent_v] += size[parent_u];
                parent[parent_u] = parent[parent_v];
            }
        }

    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        map<vector<int>, int> m;
        for(int i=0;i<points.size();i++){
            m[points[i]] = i;
        }
        vector<vector<int>> arr;

        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                arr.push_back({dist, m[points[i]], m[points[j]]});
            }
        }

        sort(arr.begin(), arr.end());
        int cost = 0;

        init_DSU(points.size());
        for(int i=0;i<arr.size();i++){
            int dist = arr[i][0];
            int u = arr[i][1];
            int v = arr[i][2];
            // cout << u << " " << v << " " << dist << endl;
            if(findParent(u) != findParent(v)){
                Union(u, v);
                cost += dist;
            }
        }

        return cost;
    }
};