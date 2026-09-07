class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> mindist(n,INT_MAX);
        vector<bool> visited(n,false);

        mindist[0]=0;
        int result=0;
        for(int i=0;i<n;i++){
            int curr=-1;
            for(int j=0;j<n;j++){
                if(!visited[j] && (curr==-1 || mindist[j]<mindist[curr])){
                    curr=j;
                }
            }
            visited[curr]=true;
            result+=mindist[curr];
            for(int j=0;j<n;j++){
                if(!visited[j]){
                    int dist=
                        abs(points[curr][0]-points[j][0])+
                        abs(points[curr][1]-points[j][1]);
                    mindist[j]=min(mindist[j],dist);
                }
            }
        }return result;
    }
};
