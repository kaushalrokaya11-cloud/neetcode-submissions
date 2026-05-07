class Solution {
public:
vector<int> curr;
// queue<int> q;
unordered_set<int>hset;
vector<vector<int>>result;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return result;

        
    }
    void dfs(vector<int> nums){


        for(int j=0;j<nums.size();j++){
           if(hset.count(nums[j])){continue;}
           curr.push_back(nums[j]);
           hset.insert(nums[j]);
           dfs(nums);


           if(curr.size()==nums.size()){result.push_back(curr);
            int temp=curr.back();
           curr.pop_back();
           hset.erase(temp);
           return;}

           int temp=curr.back();
           curr.pop_back();
           hset.erase(temp);

        }

    }
};
