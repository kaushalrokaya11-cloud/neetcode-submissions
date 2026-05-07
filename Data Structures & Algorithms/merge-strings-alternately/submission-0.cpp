class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int longer;
        string result;
      int l1=word1.length(),l2=word2.length();
        for(int i=0;i<min(l1,l2);i++){
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        if(l1>l2){
            result=result+word1.substr(l2,l2-l1);
        }
        if(l2>l1){
            result=result+word2.substr(l1,l1-l2);
        }
        return result;
        
        
    }
};