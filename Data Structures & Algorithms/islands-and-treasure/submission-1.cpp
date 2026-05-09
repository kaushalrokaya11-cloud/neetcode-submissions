class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid)
    {
     queue<pair<int,int>> q;
     for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==0){
                q.push({i,j});
                
            }
        }
     }

     bfs(q,grid);

    }

    void bfs(queue<pair<int,int>> q, vector<vector<int>> & grid){
        vector<vector<int>> direction=
        {
           {1,0},
           {-1,0},
           {0,1},
           {0,-1}
        
        };

        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr= row+ direction[i][0];
                int nc= col+ direction[i][1];

                if(nr<grid.size() && !(nr<0) && nc<grid[0].size() && nc>-1 && 
                 grid[nr][nc]==INT_MAX 
                )
                {
                    grid[nr][nc]=grid[row][col]+1;
                    q.push({nr,nc});
                }
            }


        }
    }
};
