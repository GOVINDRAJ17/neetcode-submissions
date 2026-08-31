class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    void dfs(int node){
        visited[node]=true;
        for(int neighbour:graph[node]){
            if(!visited[neighbour])
                dfs(neighbour);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        visited.resize(n,false);
        for(auto edge:edges){
            int a=edge[0];
            int b=edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                components++;
                dfs(i);
            }
        }
        return components;
    }
};
