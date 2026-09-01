class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b){
        int roota=find(a);
        int rootb=find(b);
        if(roota==rootb)
            return;
        if(rank[roota]<rank[rootb])
            parent[roota]=rootb;
        else if(rank[roota]>rank[rootb])
            parent[rootb]=roota;
        else{
            parent[rootb]=roota;
            rank[roota]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto edge:edges){
            int a=edge[0];
            int b=edge[1];
            if(find(a)==find(b)){
                return {a,b};
            }
            unite(a,b);
        }
        return {};
    }
};
