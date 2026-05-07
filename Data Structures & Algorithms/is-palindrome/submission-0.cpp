class Solution {
public:
    bool isPalindrome(string s) {
        
      string key;
        for(int i=0;i<s.length();i++){
            if(48<=s[i]&&s[i]<=57 || 65<=s[i]&&s[i]<=90|| 97<=s[i]&&s[i]<=123)
            {
               key=key+s[i];
            }
        }
        int right=key.length()-1;
        int left=0;

        while(left<=key.length()/2){
        
            if(tolower(key[left])!=tolower(key[right])){
                return false;
            }
            left++;
            right--;

        }
        return true;
        
    }
};
