class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        int rows=board.size();
        int cols=board[0].size();
       
       for(int i=0;i<rows;i++)
       {
            for(int j=0;j<cols;j++)
            { 
                vector<vector<bool>> visited(rows, vector<bool>(cols));
                string curr;
                bool result= dfs(board,visited,i,j,curr,word);
                if(result){return true;}
            }
       
       }
       return false;

        
    }
    bool dfs(vector<vector<char>> &board,vector<vector<bool>>visited,
    int i,int j ,string curr,string word)
    {
        if(curr==word){return true;}
        if(curr.length()>word.length()){return false;}
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||visited[i][j]==true)
        {return false;}

        curr=curr+board[i][j];
        visited[i][j]=true;

        return (
            dfs(board,visited,i-1,j,curr,word)||
            dfs(board,visited,i,j+1,curr,word)||
            dfs(board,visited,i+1,j,curr,word)||
            dfs(board,visited,i,j-1,curr,word)
        );




        // if(i >0) { bool bool1= dfs();}
        // if(j>0){bool bool2= dfs();}
        // if(j<board[0].size()-1){bool bool3=dfs();}
        // if(i<board.size()-1){bool bool4=dfs();}

        // return bool1||bool2||bool3||bool4;
    }
};
