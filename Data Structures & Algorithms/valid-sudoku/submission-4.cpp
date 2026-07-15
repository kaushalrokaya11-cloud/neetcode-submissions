class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n= board.size();
        int box_size = sqrt(n);
        vector<unordered_set<int>> rows(n),cols(n);
        unordered_set<string>boxes;

        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                char curr= board[i][j];
                if(curr=='.')continue;
                if(rows[i].count(curr)||cols[j].count(curr)){
                    return false;
                }
                string box = to_string(i/box_size) + to_string(j/box_size)+curr;

                if(boxes.count(box)){
                    return false;
                }
                rows[i].insert(curr);cols[j].insert(curr);boxes.insert(box);


            }
        }
        return true;
        
    }
};
