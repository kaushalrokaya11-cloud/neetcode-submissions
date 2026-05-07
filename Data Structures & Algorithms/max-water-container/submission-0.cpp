class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int result=0,n=heights.size(),temp;
        int i=0,j=n-1;
        while(i<j){

            temp=min(heights[i],heights[j])*(j-i);
            result=max(result,temp);
            if(heights[i]>=heights[j]){
                j--;
            }
            else if(heights[j]>heights[i]){
                i++;
            }
            

          
        }
        return result;
    }
};
