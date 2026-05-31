class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0)return true;
        int checkpoint = nums.size()-1;

        for(int i=nums.size()-1;i>=0;i--){
            if((nums[i]+i)>=checkpoint) checkpoint =i; 
            
        }
        if(checkpoint==0)return true;
        else return false;
    }
};
