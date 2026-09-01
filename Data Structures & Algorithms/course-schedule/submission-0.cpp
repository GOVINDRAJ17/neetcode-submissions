class Solution {
public:
    vector<vector<int>> graph;
    vector<int>state;

    bool dfs(int course){
        if(state[course]==1)
            return false;
        if(state[course]==2)
            return true;
        state[course]=1;
        for(int next:graph[course]){
            if(!dfs(next))
                return false;
        }
        state[course]=2;
        return true;
    }

    bool canFinish(int numcourses, vector<vector<int>>& prerequisites) {
        graph.resize(numcourses);
        state.resize(numcourses,0);
        for(auto edge:prerequisites){
            int course=edge[0];
            int prerequisites=edge[1];
            graph[prerequisites].push_back(course);
        }
        for(int i=0;i<numcourses;i++){
            if(!dfs(i))
                return false;
        }
        return true;
    }
};
