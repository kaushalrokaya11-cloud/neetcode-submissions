class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        int total_fresh=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){total_fresh++;}
                else if( grid[i][j]==2){q.push({i,j});}

            }
        } 

        int result= bfs(q,grid,total_fresh);   
        return result;
    }
    int bfs(queue<pair<int,int>> q, vector<vector<int>> &grid,int total_fresh){

        vector<vector<int>> dirs={
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        int time=0;
        int totalRotten=0;


        while(!q.empty())
        {
            int r= q.front().first;
            int c= q.front().second;
            
            q.pop();
            time= grid[r][c]-2;

            for(int i=0;i<4;i++)
            {
                int nr= r+ dirs[i][0];
                int nc= c+ dirs[i][1];

                if( nc>-1 && nc<grid[0].size() && nr >-1 && nr <grid.size()&&
                grid[nr][nc]==1){
                    totalRotten++;
                    grid[nr][nc]= grid[r][c]+1;
                   // time= max(time,grid[nr][nc]);
                    q.push({nr,nc});


                }
            }
        }

        if(total_fresh!=totalRotten){return -1;}
        return (time );
    }

};
