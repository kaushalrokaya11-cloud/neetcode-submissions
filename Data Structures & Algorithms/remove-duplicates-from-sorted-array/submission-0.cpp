class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int count=0;
   

        for(int r =0;r<nums.size();r++){
            if(r>0 && nums[r]==nums[r-1]){
                continue;
            }
            else{
                nums[l]=nums[r];
                l++;
                count++;

            }
        }
        return count;
        
    }
};