class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
    unordered_set<int> consecSet;
    vector<int> seq;
    int c=0,i,k,f,result=0;
   for(i=0;i<nums.size();i++){
    consecSet.insert(nums[i]);
   }
    for(i=0;i<nums.size();i++){
        if(!consecSet.count(nums[i]-1)){
            seq.push_back(nums[i]);
        }
    }
    for(i=0;i<seq.size();i++){
        
        k=0;
        f=1;
        while(f)
        {
            if(consecSet.count(seq[i]+k)){
                c=c+1;
                k=k+1;
                }
            else{
            if(c>result){
            result=c;
        }
                c=0;
                f=0;


            }
        }
       

    }
    return result;

}
};
