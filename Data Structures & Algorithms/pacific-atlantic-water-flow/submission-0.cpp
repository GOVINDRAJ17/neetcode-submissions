class Solution {
public:

    int rows;
    int cols;
    void dfs(vector<vector<int>> & heights,
            vector<vector<bool>> & ocean,int r,int c)
        {
            ocean[r][c]=true;
            int dr[4]={1,-1,0,0};
            int dc[4]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr<0||nc<0||nr>=rows||nc>=cols)
                    continue;
                if(ocean[nr][nc])
                    continue;
                if(heights[nr][nc] < heights[r][c])
                    continue;
                dfs(heights,ocean,nr,nc);
            }            

        }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(
            rows, vector<bool>(cols, false)
        );

        vector<vector<bool>> atlantic(
            rows, vector<bool>(cols, false)
        );

        // Pacific: top and left
        for(int c = 0; c < cols; c++)
        {
            dfs(heights, pacific, 0, c);
        }

        for(int r = 0; r < rows; r++)
        {
            dfs(heights, pacific, r, 0);
        }

        // Atlantic: bottom and right
        for(int c = 0; c < cols; c++)
        {
            dfs(heights, atlantic, rows - 1, c);
        }

        for(int r = 0; r < rows; r++)
        {
            dfs(heights, atlantic, r, cols - 1);
        }

        vector<vector<int>> ans;

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                if(pacific[r][c] && atlantic[r][c])
                {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};
