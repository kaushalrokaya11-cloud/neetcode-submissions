class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int rows= grid.size();
        int columns= grid[0].size();
        vector<vector<bool>> visited(rows, vector< bool> (columns, false));
        int res;
        int maxArea= res=0;

        for(int i =0;i< rows;i ++){
            for (int j=0;j<columns;j++){
                res=dfs(grid, visited, i,j);
                maxArea= max(maxArea, res);
            }
        }   
        return maxArea; 
    }

    int dfs( vector<vector<int>> &grid, vector<vector<bool>> &visited,int  row,int column)
    {
        if(row<0|| row>= grid.size()){return 0;}
        if( column<0|| column>= grid[0].size()){return 0;}
        if( visited[row][column]==true){return 0;}
        if(grid[row][column]==0) return 0;

        visited[row][column]=true;

        return (1+ 
        dfs(grid, visited, row+1,column) +
        dfs(grid, visited, row,column+1) +
        dfs(grid, visited, row,column-1) +
        dfs(grid, visited, row-1,column)
        );
    }
};
