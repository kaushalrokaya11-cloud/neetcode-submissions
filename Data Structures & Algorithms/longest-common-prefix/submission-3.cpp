class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        int m = strs[0].length();
        string result=strs[0];
        int s=INT_MAX;
        

        for(int i =1;i< n;i++){
            int j=0;
            int k =min(m,(int)strs[i].length());
            
            
            while(j<=k && j<= s && strs[0].substr(0,j)==strs[i].substr(0,j)){
            j++;
            
            }
            s= min(s,j-1);
            result = strs[0].substr(0,s);
            
        }
        return result;
        
    }
};