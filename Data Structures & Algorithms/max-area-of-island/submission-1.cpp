class Solution {
public:
    int rows;
    int cols;
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0||c<0||r>=rows||c>=cols)
            return 0;
        if(grid[r][c] == 0)
            return 0;
        grid[r][c]=0;
        int area=1;
        area+= dfs(grid,r+1,c);
        area+= dfs(grid,r-1,c);
        area+= dfs(grid,r,c+1);
        area+= dfs(grid,r,c-1);
        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        int maxarea=0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c] ==1){
                    int area=dfs(grid,r,c);
                    maxarea=max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
};
