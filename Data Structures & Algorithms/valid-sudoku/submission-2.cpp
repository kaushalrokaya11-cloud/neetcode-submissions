class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<char,int> rmap,cmap,smap;
    int i,j;
    
    for(i=0;i<board.size();i++){
        // xhecking rows
        for(j=0;j<board[i].size();j++){
            if(rmap.find(board[i][j])!=rmap.end()){
               cout<<"checking rows"<<i<<j;
                return false;
            }
            else if(board[i][j]!='.'){
                rmap[board[i][j]]=j;
            }
        }
        rmap.clear();

        // checking xolumns
        for(j=0;j<9;j++){
            if(cmap.find(board[j][i])!=cmap.end()){
                cout<<"checking columns"<<i;

                return false;
            }
            else if(board[j][i]!='.'){
                cmap[board[j][i]]=j;
            }
        }
        cmap.clear();
    }

    // For 3x3 squares
    for(i=0;i<9;i=i+3){
        for(j=0;j<9;j=j+3){
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                    if(smap.find(board[k][l])!=smap.end()){
                                    cout<<"checking square"<<i<<j;

                        return false;
                    }
                    else if(board[k][l]!='.'){
                        smap[board[k][l]]=i;
                    }
                }
            }
            smap.clear();
        }
    }
    return true;
   }
};
