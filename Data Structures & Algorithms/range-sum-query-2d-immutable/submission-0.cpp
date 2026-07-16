class NumMatrix {
public:
vector<vector<int>> matrix;
vector<vector<int>> prefix_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix_sum.resize(rows,vector<int>(cols));

        for(int i = 0;i<rows;i++){
            int curr_sum = 0;
            for ( int j =0;j<cols;j++){
                curr_sum += matrix[i][j];
                prefix_sum[i][j]= curr_sum;
            }
        }

        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total_sum=0;
        for(int i = row1;i<=row2;i++){
        int left_boundary = (col1==0)?0:prefix_sum[i][col1-1];
        int right_boundary = prefix_sum[i][col2];
            total_sum += (right_boundary -left_boundary);

        }  
        return total_sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */