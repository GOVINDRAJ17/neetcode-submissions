class Solution {
public:
    unordered_map<string,vector<string>> graph;
    vector<string> result;

    void dfs(string airport){
        while(!graph[airport].empty()){
            string next=graph[airport].back();
            graph[airport].pop_back();
            dfs(next);
        }
        result.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket:tickets){
            graph[ticket[0]].push_back(ticket[1]);
        }
        for(auto& [airport,destinations] :graph){
            sort(destinations.rbegin(),destinations.rend());
        }
        dfs("JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};
