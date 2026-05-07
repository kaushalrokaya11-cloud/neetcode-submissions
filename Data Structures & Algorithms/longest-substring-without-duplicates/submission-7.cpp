class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int>lastseen;
        int left=0;
        int right=0;
        int maxlen=0;
        for(right=0;right<s.length();right++){
            char c=s[right];
            if(lastseen.count(c)&& lastseen[c]>=left){
                left=lastseen[c]+1;
            }
            lastseen[c]=right;
            maxlen=max(maxlen,right-left+1);

        }  
        return maxlen;  
    }
};
