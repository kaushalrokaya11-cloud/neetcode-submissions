class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int res = INT_MAX;
        for(int r =k-1;r<nums.size();r++ ){
            res = min(res, nums[r]-nums[l]);
            l++;
        }
        return res;
        
    }
};