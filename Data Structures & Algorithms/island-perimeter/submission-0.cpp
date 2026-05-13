class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int row= grid.size();
        int perimeter=0;
        int col= grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0 ;i<row;i++ ){
            for(int j=0;j<col;j++){
                if( grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=-1;
                    perimeter= bfs(grid,q);
                    break;
                }
            }
        }
        return perimeter;
        
    }
    int bfs(vector<vector<int>> &grid, queue<pair<int,int>> &q){
        vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        int total=0;
        int currPeri;

        while(!q.empty()){
            

            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            currPeri=4;

            for(int i=0;i<4;i++){
                int nr= row+ dirs[i][0];
                int nc= col+ dirs[i][1];

                if( nr>-1 && nr< grid.size()&& nc>-1 && nc< grid[0].size())
                {
                    if(grid[nr][nc]==-1) {currPeri--;continue;}
                    else if( grid[nr][nc]==1){

                    currPeri--;
                    q.push({nr,nc});
                    grid[nr][nc]=-1;
                    }
                }
            }
            total= total+ currPeri;
        }
        return total;
    }
};