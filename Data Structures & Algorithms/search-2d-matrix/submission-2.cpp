class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j,n=matrix.size();
        int mid;
        j=n-1;
        int index;

        while(i<=j){

            mid=(i+j)/2;
            if(matrix[mid][0]==target){
                cout<<"first while loop";
                return true;

            }
           else if(matrix[mid][0]>target){
                j=mid-1;
            }
           else  if(matrix[mid][0]<target){
                i=mid+1;
            }
        }
        if(j==-1){
            cout<<"not existing in any row";
            return false;
        }
        else{
            index=min(i,j);
            i=0,j=matrix[index].size();
            while(i<=j){
                mid=(i+j)/2;
                if(matrix[index][mid]==target){
                    cout<<"second while loop";
                    return true;
                }
                else if(matrix[index][mid]>target){
                    j=mid-1;
                }
                else if(matrix[index][mid]<target){
                    i=mid+1;
                }

            }

        }
        cout<<"final";
        return false;

    }
};