class Solution {
public:
unordered_set<int> columns, mDiagonals,aDiagonals;
vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string>board(n, string(n,'.'));
        int row=0;
        dfs(row,n,board);
        return result;
    }

    void dfs(int rowNo,int &n,vector<string>&board){
        if(rowNo==n){
       
        result.push_back(board);return;}

        for(int i=0;i<n;i++ ){
            if( columns.count(i)||
            mDiagonals.count(rowNo-i)|| aDiagonals.count(rowNo+i)){
                
                continue;
            }

            board[rowNo][i]='Q';
           
            columns.insert(i);
            mDiagonals.insert(rowNo-i);
            aDiagonals.insert(rowNo+i);
            
         

            
          
             dfs(rowNo+1,n,board);
             board[rowNo][i]='.';

             
             columns.erase(i);
             mDiagonals.erase(rowNo-i);
             aDiagonals.erase(rowNo+i);
             
             
             
        }
    }
};
