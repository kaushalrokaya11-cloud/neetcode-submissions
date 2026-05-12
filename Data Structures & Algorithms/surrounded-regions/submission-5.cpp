class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
       queue<pair<int,int>> q;
       int row= board.size();
       int col= board[0].size();
        vector<vector<int>> indices(row,vector<int>(col));

        //pushing indices of bordre Os into queue
       for(int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if(board[i][j]=='O' && (i==0 || i== row-1|| j==0 || j== col-1)){
                q.push({i,j});
                indices[i][j]=1;
            }
            else indices[i][j]=0;
        }
       }

       bfs(q,board,indices);

       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]=='O' && !indices[i][j]){
                board[i][j]='X';
            }
        }
       }
    }

    void bfs(queue<pair<int,int>> &q, vector<vector<char>> board, vector<vector<int>> &indices)
    {
        vector<vector<int>> dirs={
            { 1,0},{-1,0},{0,1},{0,-1}
        };
        while(!q.empty()){
           int row= q.front().first;
            int col= q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr= row+ dirs[i][0];
                int nc= col+ dirs[i][1];

                if(nr>-1 && nr<board.size() && nc>-1 && nc<board[0].size()){
                    
                        if( board[nr][nc]=='X') indices[nr][nc]=1;
                        if(indices[nr][nc]==0)
                        {

                        q.push({nr,nc});
                        indices[nr][nc]=1;
                        }
                    }
                    
            }
        }
    }
};
