class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i =0, n = nums.size();
        int max_value=INT_MIN,max_count=0;
        unordered_set<int>container,counted;

        for(auto num:nums){
            container.insert(num);
            max_value= max(max_value,num);
        }

        while(i<n){
            if(counted.count(nums[i])){
                i++;
                continue;
            }
            int temp_count=0;
            int num = nums[i];
            while(true){
                temp_count ++;
                num++;
                if(!container.count(num)||num>max_value){
                    break;
                }
            }
            max_count = max(temp_count, max_count);
            i++;
        }
        return max_count;
        
    }
};
