class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        queue<pair<int,int>> q;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==0){
                    q.push({r,c});
                }
            }
        }
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr<0||nc<0||nr>=rows||nc>=cols){
                    continue;
                }
                if(grid[nr][nc]==-1)
                    continue;
                if(grid[nr][nc]!=INT_MAX){
                    continue;
                }
                grid[nr][nc]=grid[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
};
