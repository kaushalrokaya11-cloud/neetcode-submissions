class Solution {
public:
    int search(vector<int>& nums, int target) 
    {   int i=0,j=nums.size()-1,mid;
        int result =-1;
        while(i<=j){
            mid=(i+j)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                j=mid-1;
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
        }
        return result;
    }
};
