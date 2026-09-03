class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int p=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    p=p+4;
                    if(i>0&&grid[i-1][j]==1){
                        p--;
                    }
                    if(j>0&&grid[i][j-1]==1){
                        p--;
                    }
                    if(i<r-1&&grid[i+1][j]==1){
                        p--;
                    }
                    if(j<c-1&&grid[i][j+1]==1){
                        p--;
                    }
                }
            }
            
        }
        return p;
    }
};