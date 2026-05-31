//Understand why iterating from the start of array made it possible to create proper 
//intervals but iterating from the end of array couldn't.

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int n= nums.size();
        int res=0;

        int l=0,r=0;
        while(r<n-1){
            int farthest=0;

            for(int i=l;i<=r;i++){
                farthest = max(nums[i]+i,farthest);
            }
            res++;
            l=r+1;
            r= farthest;
        }

        return res;

        
    }
};
