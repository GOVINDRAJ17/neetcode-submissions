class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    bool dfs(int node,int parent){
        if(visited[node])
            return false;
        visited[node]=true;
        for(int neighbour:graph[node]){
            if(neighbour==parent)
                continue;

            if(!dfs(neighbour,node))
                return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1)
            return false;

        graph.resize(n);
        visited.resize(n, false);
        for(auto edge : edges) {

            int a = edge[0];
            int b = edge[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        if(!dfs(0, -1))
            return false;
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                return false;
        }
        return true;
    }
};
