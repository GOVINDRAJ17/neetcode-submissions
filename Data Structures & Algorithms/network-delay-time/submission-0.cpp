class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto edge:times){
            int u=edge[0];
            int v=edge[1];
            int time=edge[2];
            graph[u].push_back({v,time});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,
                        greater<pair<int,int>>> pq;
        
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto[time,node]=pq.top();
            pq.pop();
            if(time>dist[node])
                continue;
            for(auto [neighbour,weight] : graph[node]){
                int newtime=time+weight;
                if(newtime<dist[neighbour]){
                    dist[neighbour]=newtime;
                    pq.push({newtime,neighbour});
                }
            }
        }
        int answer=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)
                return -1;
            answer=max(answer,dist[i]);
        }
        return answer;
    }
};
