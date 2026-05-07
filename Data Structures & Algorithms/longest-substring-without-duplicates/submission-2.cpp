class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, count =0;
        int right=0,per_count=0;
        unordered_set<char> hash_set;
        while(right<s.length()){
            if(hash_set.find(s[right])!=hash_set.end())
            {
             
              //right++;
                
              hash_set.erase(s[left]);
              left++;
             
            }
            else{
                hash_set.insert(s[right]);
                count=right-left+1;
                right++;
            }
            if (per_count< count){per_count=count;}
            
        }
        return per_count;
    }
};
