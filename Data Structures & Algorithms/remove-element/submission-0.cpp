class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        vector<int> output;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                output.push_back(nums[i]);
            }
        }
        nums=output;
        return output.size();
        
    }
};