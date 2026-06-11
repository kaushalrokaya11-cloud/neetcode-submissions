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
            while( j< k){
                if(strs[0][j]!= strs[i][j])break;
                j++;
            }
            s= min(j,s);
            
            
        }
        result = strs[0].substr(0,s);
        return result;
        
    }
};