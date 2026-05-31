class Solution {
public:
unordered_set<int> columns, mDiagonals,aDiagonals;
vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        
        string dRow(n,'.');
        vector<string> temp={};
        int row=0;
        dfs(row,n,dRow,temp);
        return result;
    }

    void dfs(int rowNo,int &n,string &dRow,vector<string> &temp){
        if(rowNo==n){
       
        result.push_back(temp);return;}

        for(int i=0;i<n;i++ ){
            if( columns.count(i)||
            mDiagonals.count(rowNo-i)|| aDiagonals.count(rowNo+i)){
                
                continue;
            }

            dRow[i]='Q';
           
            columns.insert(i);
            mDiagonals.insert(rowNo-i);
            aDiagonals.insert(rowNo+i);
            temp.push_back(dRow);
         

            
             dRow[i]='.';
             dfs(rowNo+1,n,dRow,temp);

             
             columns.erase(i);
             mDiagonals.erase(rowNo-i);
             aDiagonals.erase(rowNo+i);
             
             temp.pop_back();
             
        }
    }
};
