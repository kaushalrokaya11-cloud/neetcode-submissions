class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> q;
        int rows= heights.size();
        int cols= heights[0].size();
        vector<vector<int>> result;

        vector<vector<bool>> pacific(rows, vector<bool>(cols,false)) ;
        vector<vector<bool>> atlantic(rows, vector<bool>(cols,false));

        for(int i=0;i< rows;i++){
            q.push({i,0});
            pacific[i][0]=true;
        }
        for(int i=1;i<cols;i++){
            q.push({0,i});
            pacific[0][i]=true;
        }

         bfs(q,heights,pacific);

        for(int i=0;i<rows;i++){
            q.push({i,cols-1});
            atlantic[i][cols-1]=true;
        }
        for(int i=0;i< cols-1;i++){
            atlantic[rows-1][i]=true;
            q.push({rows-1,i});
        }
        bfs(q,heights,atlantic);

        findResult(pacific, atlantic, result);
        return result;
        
    }

   void bfs( queue<pair<int,int>> &q, vector<vector<int>> &heights, 
    vector<vector<bool>> &store)
    {

        vector<vector<int>> dirs={
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        
        while(!q.empty()){
           int r= q.front().first;
            int c= q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr= r+ dirs[i][0];
                int nc= c+ dirs[i][1];

                if( nr< heights.size() && nr>-1 && nc <heights[0].size()&& nc>-1 &&
                store[nr][nc]==false && heights[r][c]<=heights[nr][nc]){
                    q.push({nr,nc});
                    store[nr][nc]=true;
                }
            }
        }
    }
    void findResult(vector<vector<bool>>pacific, vector<vector<bool>> atlantic,
    vector<vector<int>> &result)
    {
        for(int i=0;i<pacific.size();i++){
            for(int j=0;j< pacific[0].size();j++){
                if(pacific[i][j]==true && atlantic[i][j]==true){
                    result.push_back({i,j});
                }
            }
        }
    }
    

};
