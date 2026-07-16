class NumMatrix {
public:

vector<vector<int>> prefix_sum;
    NumMatrix(vector<vector<int>>& matrix) {
       
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix_sum.resize(rows,vector<int>(cols));

        for(int i = 0;i<rows;i++){
            int curr_sum = 0;
            for ( int j =0;j<cols;j++){
                curr_sum += matrix[i][j];
                int prev_row_sum = (i==0)?0:prefix_sum[i-1][j];
                prefix_sum[i][j]= prev_row_sum + curr_sum;
            }
        }

        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      int large_rectangle_sum = prefix_sum[row2][col2];
      int upper_part_sum = row1 == 0?0:prefix_sum[row1-1][col2];
      int left_part_sum = col1==0?0:prefix_sum[row2][col1-1]; 
      int intersection_part_sum = (row1 ==0 || col1==0)?0: prefix_sum[row1-1][col1-1];

      int total_sum = large_rectangle_sum -(upper_part_sum + left_part_sum - intersection_part_sum);

      return total_sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */