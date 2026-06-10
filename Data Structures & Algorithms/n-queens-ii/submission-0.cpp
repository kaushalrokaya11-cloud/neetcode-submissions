class Solution {
    unordered_set<int> cols,mDiagonals,aDiagonals;
    int total=0;
public:
    int totalNQueens(int n) {
        dfs(0,n);
        return total;
    }
    void dfs(int rowNo,int n){
        if(rowNo==n){total++;return;}
        

        for(int i =0;i< n;i++){
            if(cols.count(i)|| mDiagonals.count(i-rowNo)|| aDiagonals.count(i+rowNo))continue;
            
            cols.insert(i);mDiagonals.insert(i-rowNo);aDiagonals.insert(i+rowNo);

            dfs(rowNo+1, n);

            cols.erase(i);mDiagonals.erase(i-rowNo);aDiagonals.erase(i+rowNo);

        }
    }
};