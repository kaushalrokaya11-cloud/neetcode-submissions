class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int r= board.size();
        int c= board[0].size();
        vector<vector<int>> grid(r, vector<int> (c));
        int res;
        vector<pair<int,int>> indices;

        //Making grid
        for(int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++){
                if(board[i][j]=='X') grid[i][j]=1;
                else grid[i][j]=0;
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O' && grid[i][j]==0){
                   res= bfs(i,j,indices,board,grid);
                   if( !res ) fill(board,indices);
                   
                }
                indices.clear();
            }
        }

        
    }

    int bfs(int &r, int &c, vector<pair<int,int>> &indices, vector<vector<char>> & board,
    vector<vector<int>> &grid){

        cout<<" bfs ran and indicies pushed for :"<< r<<c<< endl;

        int result=0;
        queue<pair<int,int>> q;
        q.push({r,c});
        indices.push_back({r,c}); grid[r][c]=1;

        vector<vector<int>> dirs={
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
                int nr= row+ dirs[i][0];
                int nc= col+ dirs[i][1];
                
                if(nr>-1 && nr< board.size() && nc>-1 && nc< board[0].size())
               
                {
                    if( grid[nr][nc]==0)
                    {
                        
                    grid[nr][nc]=1;
                    q.push({nr,nc});
                    indices.push_back({nr,nc});
                    cout<< "indices pushed: "<< nr<< nc<<endl;

                    }
                    
                }
                else{
                    result=1;
                    cout<<"indices touching out "<< nr<<nc<<endl;
                }
                
            }
        }
        return result;
    }


    void fill(vector<vector<char>> &board,vector<pair<int,int>> indices){

        for (pair<int,int> index: indices){
           int  r= index.first;
            int c= index.second;
            board[r][c]='X';
        }
    }
};
