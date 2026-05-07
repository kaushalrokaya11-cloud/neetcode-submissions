class Solution {
public:
    int findMin(vector<int> &nums) {
        int left=0, right=nums.size()-1;
        int n=nums.size();
        int mid;
        int result=nums[0];
        while(left<right){
            mid=(left+right)/2;
         

            if(nums[left]<nums[right]){
                return nums[left];}
           else if(nums[mid]>=nums[left]){
               left=mid+1;
                

            }
            
            
            else {
                right=mid;
            }

           


        }
        return nums[left];
        
    }
};
