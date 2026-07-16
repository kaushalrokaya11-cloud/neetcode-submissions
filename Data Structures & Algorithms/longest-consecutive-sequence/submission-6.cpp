class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i =0, n = nums.size();
        int max_count=0;
        unordered_set<int>container(nums.begin(),nums.end());

        while(i<n){
            int num = nums[i];
            if(container.count(num-1)){
                i++;
                continue;
            }
            int temp_count=0;
            while(container.count(num)){
                temp_count ++;
                num++;
            }

            max_count = max(temp_count, max_count);
            i++;
        }
        return max_count;
        
    }
};
