class Solution {
public:
vector<int> curr={};
vector<vector<int>>result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        // result.push_back({});
        return result;
    }
    void dfs(vector<int> &nums,int i){
        
        result.push_back(curr);
        if(i>=nums.size()){return;}
        
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]){continue;}
            curr.push_back(nums[j]);
            dfs(nums,j+1);
            curr.pop_back();
        }
    }
};
