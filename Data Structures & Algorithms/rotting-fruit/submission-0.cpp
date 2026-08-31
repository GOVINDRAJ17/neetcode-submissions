class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        queue<pair<int,int>> q;
        int fresh=0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==2){
                    q.push({r,c});
                }
                if(grid[r][c]==1){
                    fresh++;
                }
            }
        }
        int minutes=0;
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto[r,c]=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int nr= r+dr[j];
                    int nc= c+dc[j];
                    if(nr < 0 || nc < 0 || nr >= rows || nc >= cols)
                        continue;
                    if(grid[nr][nc] !=1)
                        continue;
                    grid[nr][nc]=2;
                    fresh--;
                    q.push({nr,nc});
                }
            }
            minutes++;
        }
        if(fresh > 0)
            return -1;

        return minutes;
    }
};
