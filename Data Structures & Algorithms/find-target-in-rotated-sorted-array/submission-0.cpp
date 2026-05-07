class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=pivotIndex(nums);
        //First Segment
        int l=0,r=pivot-1,m;
        for(int i=0;i<2;i++){

        while(l<=r){
            m=(l+r)/2;
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]>target){
                r=m-1;
            }
            else if(nums[m]<target){
                
                l=m+1;
            }
        }

        l=pivot;
        r=n-1;
        }
        return -1;

      
        
    }
    int pivotIndex(vector<int>&nums){
        int n=nums.size();
        int l=0,r=n-1,m;
          while(l<r){
            if(nums[l]<nums[r]){
                return l;
            }
            m=(l+r)/2;
            if(nums[m]>=nums[l]){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        return r;

    }
};
