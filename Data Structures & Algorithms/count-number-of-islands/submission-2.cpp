class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int rows= grid.size();
        int columns= grid[0].size();
        int total=0;

        vector<vector<bool>> visited(rows, vector<bool>(columns, false));

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j< columns;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==false)
                {

                findIsland(grid,visited,i,j);
                total++;
                }
            }
        }
        return total;
        
    }

    void findIsland(vector<vector<char>> &grid, vector<vector<bool>> & visited,
    int row, int column)
    {
        if(row< 0 || row>= grid.size()){return;}
        if(column <0 || column>= grid[0].size()){return;}
        if(visited[row][column]==true || grid[row][column]=='0'){return;}

        visited[row][column]=true;

        findIsland(grid, visited, row-1, column);
        findIsland(grid, visited, row+1, column);
        findIsland(grid, visited, row, column+1);
        findIsland(grid, visited, row, column-1);

    }
};
