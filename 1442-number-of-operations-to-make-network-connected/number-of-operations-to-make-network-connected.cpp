class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
    
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n);
        int extraEdges = 0;
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findParent(u) == ds.findParent(v)){
                extraEdges++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        }
        cnt--; // to deduct the parent of the largest connected component

        if(extraEdges >= cnt){
            return cnt;
        }
        return -1;
    }
};